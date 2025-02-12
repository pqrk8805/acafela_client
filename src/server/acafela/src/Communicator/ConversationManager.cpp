#include <stdio.h>
#include <chrono>
#include "communicator.h"
#include "../Hislog.h"
#include "../SipMessage/SipMessage.pb.h"
#define LOG_TAG "COMMPATH"
#define CASE(Consume, CMD) \
	case acafela::sip::CMD:\
		if (isHandledMsgAndAck(sender,Consume,msg))\
			return true;

extern std::vector<std::thread *> additionalThreadList;
ICryptoKeyMgr * ConversationManager::keyManager;
ConferenceCallManager * ConversationManager::confManager;
SocketGroup ConversationManager::ctrlStreamSocket;
std::thread * ConversationManager::rcvThread;
CRITICAL_SECTION ConversationManager::waitAckCrit;
CRITICAL_SECTION ConversationManager::consumeAckCrit;
std::vector<std::tuple<long long, acafela::sip::SIPMessage>> ConversationManager::consumedPacketList;
std::vector<std::tuple<long long, int, std::string, acafela::sip::SIPMessage>> ConversationManager::waitAckPacketList;
std::map<Participant *, Conversation *> ConversationManager::conversationMap;
void ConversationManager::createControlServer(ICryptoKeyMgr * keyManager_p, ConferenceCallManager * confManager_p) {
	keyManager = keyManager_p;
	confManager = confManager_p;
	createSocket();
	InitializeCriticalSection(&waitAckCrit);
	InitializeCriticalSection(&consumeAckCrit);
	additionalThreadList.push_back(new std::thread([&] {
		while (1) {
			fflush(stdout);
			int recv_len;
			char * buf = new char[BUFLEN];
			memset(buf, NULL, BUFLEN);
			struct sockaddr_in si;
			int slen = sizeof(si);
			if ((recv_len = recvfrom(ctrlStreamSocket.server, buf, BUFLEN, 0, (struct sockaddr *) &si, &slen)) == SOCKET_ERROR)
				FUNC_LOGI("recvfrom() failed with error code : %d", WSAGetLastError());
			acafela::sip::SIPMessage msg;
			msg.ParseFromArray(buf, recv_len);
			delete buf;
			char ipStr[INET_ADDRSTRLEN];
			inet_ntop(AF_INET, &(si.sin_addr), ipStr, INET_ADDRSTRLEN);
			FUNC_LOGI("Receive msg %s : \n----%s----\n%s",
				ipStr,
				acafela::sip::Command_descriptor()->FindValueByNumber(msg.cmd())->name().c_str(),
				msg.DebugString().c_str()
			);
			if (msg.isack()) {
				if (msg.from().find("SERVER") != std::string::npos) {
					FUNC_LOGI("Receive msg %s : was ACK to server", ipStr);
					rcvAckHandler(ipStr, msg);
					continue;
				}
				FUNC_LOGI("Receive msg %s : was ACK to another", ipStr);
				forwardMessageHandler(std::string(ipStr), msg);
				continue;
			}
			if (!consumeMessageHandler(std::string(ipStr), msg)) {
				FUNC_LOGI("Receive msg %s : is MSG to another", ipStr);
				forwardMessageHandler(std::string(ipStr), msg);
			}
		}
	}));
	additionalThreadList.push_back(new std::thread([&] {
		while (1) {
			EnterCriticalSection(&waitAckCrit);
			for (int i = 0; i < waitAckPacketList.size(); i++) {
				auto iter = waitAckPacketList[i];
				if (std::get<1>(iter) >= TRYCNT) {
					waitAckPacketList.erase(waitAckPacketList.begin() + i--);
					continue;
				}
				if (getTime() - std::get<0>(iter) < TIMEOUT)
					continue;
				Participant * tmpPart = new Participant(std::get<2>(iter));
				sendCtrlMsg(tmpPart, std::get<3>(iter), std::get<1>(iter));
				delete tmpPart;
				waitAckPacketList.erase(waitAckPacketList.begin() + i--);
			}
			LeaveCriticalSection(&waitAckCrit);
			EnterCriticalSection(&consumeAckCrit);
			consumedPacketList.erase(std::remove_if(begin(consumedPacketList), end(consumedPacketList), [](const auto& i)
			{
				return getTime() - std::get<0>(i) >= TIMEOUT;
			}), end(consumedPacketList));
			LeaveCriticalSection(&consumeAckCrit);
			Sleep(50);
		}
	}));
}

void ConversationManager::rcvAckHandler(std::string IP, acafela::sip::SIPMessage msg) {
	EnterCriticalSection(&waitAckCrit);
	for(auto waitAckPacket = waitAckPacketList.begin(); waitAckPacket != waitAckPacketList.end();){
		if (strcmp(std::get<2>(*waitAckPacket).c_str(), IP.c_str())
			|| std::get<3>(*waitAckPacket).cmd() != msg.cmd()) {
			waitAckPacket++;
			continue;
		}
		waitAckPacketList.erase(waitAckPacket);
		break;
	}
	LeaveCriticalSection(&waitAckCrit);
}

bool ConversationManager::isHandledMsgAndAck(Participant * part, bool isServerConsumed, acafela::sip::SIPMessage msg) {
	if (isServerConsumed) {
		msg.set_isack(true);
		sendCtrlMsg(part, msg, 0);
	}
	EnterCriticalSection(&consumeAckCrit);
	for (auto consumedPacket : consumedPacketList) {
		auto msg_con = std::get<1>(consumedPacket);
		if (msg_con.cmd() != msg.cmd()
		||  msg_con.from() != msg.from()
		||  msg_con.to() != msg.to())
			continue;
		LeaveCriticalSection(&consumeAckCrit);
		return true;
	}
	consumedPacketList.push_back({ getTime(), msg });
	LeaveCriticalSection(&consumeAckCrit);
	return false;
}

void ConversationManager::createSocket() {
	ctrlStreamSocket.client = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (ctrlStreamSocket.client == INVALID_SOCKET)
		FUNC_LOGE("Could not create socket : %d", WSAGetLastError());
	
	if ((ctrlStreamSocket.server = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET)
		FUNC_LOGE("Could not create socket : %d", WSAGetLastError());
	FUNC_LOGI("Server Socket created.");

	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(CTRLSERVERRCVPORT);

	if (bind(ctrlStreamSocket.server, (struct sockaddr *)&server, sizeof(server)) == SOCKET_ERROR)
	{
		FUNC_LOGE("Bind failed with error code : %d", WSAGetLastError());
		exit(EXIT_FAILURE);
	}
}

long long ConversationManager::getTime() {
	return std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
}

void ConversationManager::setRetryCtrlMsg(std::string ip, acafela::sip::SIPMessage msg, int retryConut) {
	EnterCriticalSection(&waitAckCrit);
	waitAckPacketList.push_back({ getTime(), retryConut, ip, msg });
	LeaveCriticalSection(&waitAckCrit);
}

void ConversationManager::sayGoodbyeMsg(std::string IP) {
	acafela::sip::SIPMessage returnMessage;
	FUNC_LOGI("Cannot find user from directory : Say Good Bye~");
	returnMessage.set_cmd(acafela::sip::BYE);
	//Bye Call 중간에도 받?
	returnMessage.set_from("SERVER");
	returnMessage.set_to(IP);
	Participant * tmpPart = new Participant(IP);
	sendCtrlMsg(tmpPart, returnMessage, 0);
	delete tmpPart;
}

bool ConversationManager::consumeMessageHandler(std::string IP, acafela::sip::SIPMessage msg) {
	Participant * from = ParticipantDirectory().getFromNumber(msg.from());
	Participant * to = ParticipantDirectory().getFromNumber(msg.to());
	Participant * sender = ParticipantDirectory().getFromIP(IP);
	if (((msg.to().find("#") == std::string::npos) && to == nullptr) || from == nullptr || sender == nullptr) {
		sayGoodbyeMsg(IP);
		return true;
	}
	switch (msg.cmd()) {
		case acafela::sip::INVITE:
		{
			if (msg.to().find("#") != std::string::npos) {
				if (isHandledMsgAndAck(sender, true, msg))
					return true;
				Conversation * conversation = confManager->getConversationRoom(msg.to());
				if (conversation == nullptr) {
					FUNC_LOGI("Request to Make Key in ConvRoom");
					keyManager->generateKey(msg.to());
					conversation = confManager->openConversationRoom(msg.to(), msg.isvideocall());
				}
				conversation->addParticipant(sender, PortHandler().getPortNumber());
				conversationMap[sender] = conversation;
				return true;
			} else {
				if (isHandledMsgAndAck(sender, false, msg))
					return false;
				FUNC_LOGI("Request to Make Key");
				keyManager->generateKey(msg.sessionid());
				Conversation * conversation = new Conversation({
					{from,PortHandler().getPortNumber()},
					{to,PortHandler().getPortNumber()}
					}, false);
				if(msg.isvideocall())
					conversation->enableVideoConversation();
				conversationMap[from] = conversation;
				conversationMap[to] = conversation;
				return false;
			}
		}
		CASE(true, MAKECALL) {
			FUNC_LOGI("Request to Make Call");
			Conversation * conversation = conversationMap[sender];
			if (conversation == nullptr)
				return true;
			conversation->makeConversation();
			if (conversation->isVideoComm())
				conversation->startVideoConversation();
			return true;
		}
		CASE(true, TERMINATE) {
			FUNC_LOGI("Request to Terminate");
			Conversation * conversation = conversationMap[sender];
			if (conversation == nullptr)
				return true;
			if (!conversation->isP2P() && conversation->getPartCount() > 2) {
				conversation->removeParticipant(from);
				conversationMap.erase(from);
				return true;
			}
			conversation->terminateConversation();
			confManager->removeConversationRoom(msg.to());
			for (auto iter = conversationMap.begin(); iter != conversationMap.end();) {
				if (std::get<1>(*iter) != conversation)
					iter++;
				else
					iter = conversationMap.erase(iter);
			}
			delete conversation;
			return true;
		}
		CASE(true, STARTVIDEO) {
			FUNC_LOGI("Request to StartVideo");
			Conversation * conversation = conversationMap[sender];
			if (conversation == nullptr)
				return true;
			conversation->startVideoConversation();
			return true;
		}
		CASE(true, STOPVIDEO) {
			FUNC_LOGI("Request to StartVideo");
			Conversation * conversation = conversationMap[sender];
			if (conversation == nullptr)
				return true;
			conversation->stopVideoConversation();
			return true;
		}
	}
	return false;
}

void ConversationManager::forwardMessageHandler(std::string IP, acafela::sip::SIPMessage msg) {
	Participant * from = ParticipantDirectory().getFromNumber(msg.from());
	Participant * to = ParticipantDirectory().getFromNumber(msg.to());
	Participant * sender = ParticipantDirectory().getFromIP(IP);
	if (to == nullptr || from == nullptr || sender == nullptr) {
		sayGoodbyeMsg(IP);
		return;
	}
	//if (conversationMap[sender] == NULL)
	//	sendCtrlMsg(to, msg);
	//else
	Conversation * conversation = conversationMap[sender];
	if (conversation == nullptr)
		return;
	if(conversation->isP2P())
		conversation->boradcast_CtrlExceptMe(sender, msg);
}

void ConversationManager::sendCtrlMsg(Participant * to, acafela::sip::SIPMessage msg, int retryCount) {
	struct sockaddr_in server;
	server.sin_family = AF_INET;
	server.sin_port = htons(CTRLSERVERSNDPORT);
	inet_pton(AF_INET, to->getIP().c_str(), &(server.sin_addr));
	FUNC_LOGI("Send msg %s : \n----%s----\n%s", 
		to->getIP().c_str(), 
		acafela::sip::Command_descriptor()->FindValueByNumber(msg.cmd())->name().c_str(), 
		msg.DebugString().c_str()
	);
	size_t size = msg.ByteSizeLong();
	void *buffer = new char[size];
	msg.SerializeToArray(buffer, size);
	if (sendto(ctrlStreamSocket.client, (char *)buffer, size, 0, (struct sockaddr*) &server, sizeof(struct sockaddr_in)) == SOCKET_ERROR)
		FUNC_LOGE("sendto() failed with error code : %d", WSAGetLastError());
	if (!strcmp(msg.from().c_str(), "SERVER"))
		setRetryCtrlMsg(to->getIP(), msg, ++retryCount);
	delete buffer;
}
