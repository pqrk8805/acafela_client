#include "ConferenceCallManager.h"
#include "EmailSenderCC.h"
#include "StorageAccessor/FileStorageAccessor.h"
#include <algorithm>

using namespace std;

ConferenceCallManager::ConferenceCallManager()
{
	mSA = make_unique<FileStorageAccessor>();
}

string ConferenceCallManager::generateNewCCNumber()
{
	vector<string> ccNumList = mSA->getCCNumbers();
	
	for (int i = 2587; i < 10000; i++)
	{
		string ccNumber = to_string(i);
		string fillZero(4 - ccNumber.size(), '0');
		ccNumber = fillZero + ccNumber;

		auto ret = std::find_if(begin(ccNumList), end(ccNumList), [ccNumber](const string& str)
		{
			return str.compare(ccNumber) == 0 ? true : false;
		});

		if (ret == end(ccNumList))
			return "#" + ccNumber;
	}
	

	return "-1";
}

int ConferenceCallManager::MakeConferenceCall(const string& dateFrom, const string& dateTo, const vector<string>& participantsList)
{
	string ccNumber = generateNewCCNumber();

	for (const auto& i : participantsList)
	{
		string emailAddress = mSA->getEmailAddress(i);
		EmailSenderCC::sendCCInvitation(emailAddress, ccNumber, "\"" + dateFrom + "\"", "\"" + dateTo + "\"");
	}

	mSA->saveCCItem(ccNumber, dateFrom, dateTo, participantsList);
	
	openConversationRoom(ccNumber, false);

	return 0;
}

Conversation * ConferenceCallManager::openConversationRoom(std::string ccNo, bool isVideo) {
	Conversation * conv = new Conversation({}, true);
	if (isVideo)
		conv->enableVideoConversation();
	conversationMap[ccNo] = conv;
	return conv;
}

void ConferenceCallManager::removeConversationRoom(std::string ccNo) {
	conversationMap[ccNo] = nullptr;
}

Conversation * ConferenceCallManager::getConversationRoom(std::string ccNo) {
	const auto iter = conversationMap.find(ccNo);
	if (iter == conversationMap.cend())
		return nullptr;
	return conversationMap[ccNo];
}