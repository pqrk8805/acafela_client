#include <stdio.h>
#include "communicator.h"
#include "../Hislog.h"
#define LOG_TAG "CONV"

Conversation::Conversation(std::vector<std::tuple<Participant *, int>> partList, bool isServerPassed) {
	FUNC_LOGI("Make Conversation Room, %s", isServerPassed ? "P2P" : "P2S");
	for (auto partAndPort : partList) {
		FUNC_LOGI("%s join room", std::get<0>(partAndPort)->getIP().c_str());
		conversationRoom.push_back(partAndPort);
	}
	for (auto partAndPort : partList) {
		Participant * part = std::get<0>(partAndPort);
		FUNC_LOGI("Create %s data path, RCVPort : %d", std::get<0>(partAndPort)->getIP().c_str(), std::get<1>(partAndPort));
		DataPath * dPath = new DataPath(part, this, part->getIP().c_str(), std::get<1>(partAndPort), isServerPassed);
		for (auto partAndPort_temp : partList) {
			Participant * part_temp = std::get<0>(partAndPort_temp);
			if (part == part_temp)
				continue;
			dPath->initParticipant(part_temp, std::get<1>(partAndPort_temp));
		}
		part->setDataPath(dPath);
		dPath->openDataPath();
	}
}

void Conversation::terminateConversation() {
	for (auto partAndPort : conversationRoom) {
		Participant * part = std::get<0>(partAndPort);
		acafela::sip::SIPMessage msg;
		msg.set_cmd(acafela::sip::BYE);
		msg.set_from("SERVER");
		msg.set_to(part->getIP());
		ConversationManager().sendControlMessage(part, msg); 
		part->getDataPath()->terminateDataPath();
		delete part->getDataPath();
		part->clearDataPath();
	}
}

void Conversation::broadcast_Data(Participant * partSend, int len, char * data) {
	for (auto partAndPort : conversationRoom) {
		Participant * part = std::get<0>(partAndPort);
		if (part == partSend)
			continue;
		part->getDataPath()->addToSendData(partSend, len, data);
	}
}

void Conversation::boradcast_Ctrl(std::string msg) {
	//tbd
	;
}

void Conversation::addParticipant(Participant * part, int port) {
	FUNC_LOGI("%s join room", part->getIP().c_str());
	for (auto partAndPort : conversationRoom)
		std::get<0>(partAndPort)->getDataPath()->addParticipant(part, port);
	
	FUNC_LOGI("Create %s data path, RCVPort : %d", part->getIP().c_str(), port);
	DataPath * dPath = new DataPath(part, this, part->getIP(), port);
	for (auto partAndPort : conversationRoom)
		dPath->initParticipant(std::get<0>(partAndPort), std::get<1>(partAndPort));
	conversationRoom.push_back(std::make_tuple(part, port));
	part->setDataPath(dPath);
	dPath->openDataPath();
}

void Conversation::removeParticipant(Participant * part) {
	part->getDataPath()->terminateDataPath();
	delete part->getDataPath();
	part->clearDataPath();
	for (auto iter = conversationRoom.begin(); iter < conversationRoom.end(); iter++){
		if (std::get<0>(*iter) != part)
			continue;
		conversationRoom.erase(iter);
		break;
	}
	for (auto partAndPort : conversationRoom)
		std::get<0>(partAndPort)->getDataPath()->removeParticipant(part);
	acafela::sip::SIPMessage returnMessage;
	returnMessage.set_cmd(acafela::sip::BYE);
	returnMessage.set_from("SERVER");
	returnMessage.set_to(part->getIP());
	ConversationManager().sendControlMessage(part, returnMessage);
}