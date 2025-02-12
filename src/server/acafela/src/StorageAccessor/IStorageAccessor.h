#pragma once

#include <string>
#include <vector>

struct UserInfo 
{
	std::string emailAddress;
	std::string phoneNumber;
	std::string ipAddress;
	bool enabled;
};

class IStorageAccessor
{
protected:
	IStorageAccessor() {}
	IStorageAccessor(const IStorageAccessor&) = delete;
	IStorageAccessor& operator=(const IStorageAccessor&) = delete;
public:
	virtual ~IStorageAccessor() {}

	virtual int registerUser(
		const std::string& emailAddress,
		const std::string& password,
		const std::string& phoneNumber) = 0;

	virtual bool confirmPassword(
		const std::string& emailAddress,
		const std::string& password) = 0;

	virtual int changePassword(
		const std::string& emailAddress,
		const std::string& password) = 0;

	virtual bool confirmPhoneNumber(
		const std::string& emailAddress,
		const std::string& phoneNumber) = 0;

	virtual int confirmPhoneNumberPassword(
		const std::string& phoneNumber,
		const std::string& password) = 0;

	virtual std::string getTempPassword(
		const std::string& emailAddress) = 0;

	virtual std::string getEmailAddress(
		const std::string& phoneNumber) = 0;

	virtual int deleteUser(const std::string& emailAddress) = 0;	

	virtual int getUserNumber() = 0;
	virtual int updateUserNumber(int userNumber) = 0;

	virtual bool isExistUser(const std::string& emailAddress) = 0;
		
	virtual int saveDSItem(UserInfo& userInfo) = 0;
	virtual std::vector<UserInfo> getDSItems() = 0;
	virtual int disableUser(const std::string& emailAddress) = 0;
	virtual int enableUser(const std::string& emailAddress) = 0;

	virtual std::vector<std::string> getCCNumbers() = 0;
	virtual int saveCCItem(	const std::string& roomNumber,
							const std::string& dateFrom,
							const std::string& dateTo,
							const std::vector<std::string>& participantsList) = 0;
	virtual bool confirmCCUser( const std::string& roomNumber,
								const std::string& phoneNumber) = 0;
private:
	static IStorageAccessor* mInst;
};