#include "UserProfile.h"
#include "EmailSender.h"
#include "Hislog.h"
#include "StorageAccessor/FileStorageAccessor.h"
#include "CryptoKey/MD5Hash.h"

#define LOG_TAG "UserProfile"

using namespace std;
UserProfile::UserProfile(IStorageAccessor& sa)
  : mSA(sa)
{
	mSP = make_unique<MD5>();
}

UserProfile::~UserProfile()
{
}

string UserProfile::generateUserPhoneNumber()
{
	int totalUserNumber = mSA.getUserNumber();

	string userPhoneNumber = to_string(totalUserNumber + 1111);

	string fillZero(4 - userPhoneNumber.size(), '0');

	userPhoneNumber = fillZero + userPhoneNumber;

	totalUserNumber += 1;

	mSA.updateUserNumber(totalUserNumber);

	return userPhoneNumber;
}

std::string UserProfile::registerUser(
                        const std::string& emailAddress,
                        const std::string& password)
{
    FUNC_LOGD("BEGIN");	
	
	string encPassword = mSP->GetSecureData(password);

	bool isExistUser = mSA.isExistUser(emailAddress);

	if (isExistUser == false)
	{
		string genPhoneNumber = generateUserPhoneNumber();
		printf("registerUser email/pw/# = %s/%s/%s\n", emailAddress.c_str(), password.c_str(), genPhoneNumber.c_str());
		mSA.registerUser(emailAddress, encPassword, genPhoneNumber);
		return genPhoneNumber;
	}
	else
	{
		return "0000";
	}
}

int UserProfile::changePassword(
                        const std::string& emailAddress,
                        const std::string& oldPassword,
                        const std::string& newPassword)
{
    FUNC_LOGD("BEGIN");	
	
	string encOldPassword = mSP->GetSecureData(oldPassword);
	bool confirmedPassword = mSA.confirmPassword(emailAddress, encOldPassword);

	string encNewPassword = mSP->GetSecureData(newPassword);
	if (confirmedPassword == true)
	{
		printf("changePassword email/old pw/new pw = %s/%s/%s\n", emailAddress.c_str(), oldPassword.c_str(), newPassword.c_str());
		return mSA.changePassword(emailAddress, encNewPassword);
	}
	else
		return -1;
}

int UserProfile::restorePassword(
                        const std::string& emailAddress,
                        const std::string& phoneNumber)
{
	FUNC_LOGD("BEGIN");
	

	bool confirmedPhoneNumber = mSA.confirmPhoneNumber(emailAddress, phoneNumber);
	if (confirmedPhoneNumber == true)
	{
		const string tempPassword = mSA.getTempPassword(emailAddress);
		const string encTempPassword = mSP->GetSecureData(tempPassword);
		mSA.changePassword(emailAddress, encTempPassword);

		printf("restorePassword email/#/pw = %s/%s/%s\n", emailAddress.c_str(), phoneNumber.c_str(), tempPassword.c_str());
		EmailSender::sendPasswordRecoveryMail(emailAddress, tempPassword);
		return 0;
	}
	else
	{
		return -1;
	}
}

