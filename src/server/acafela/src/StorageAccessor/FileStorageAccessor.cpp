#include "FileStorageAccessor.h"
#include <sys/stat.h>
#include <sys/types.h>

#include <windows.h>
#include "DBFile.h"

using namespace std;
std::mutex	FileStorageAccessor::mUserNumberLock;
std::mutex	FileStorageAccessor::mPasswordLock;
std::mutex	FileStorageAccessor::mPhoneNumberLock;
std::mutex	FileStorageAccessor::mDSLock;
std::mutex	FileStorageAccessor::mCCLock;
FileStorageAccessor::FileStorageAccessor()
{
}

FileStorageAccessor::~FileStorageAccessor()
{
}

int FileStorageAccessor::registerUser(const string& emailAddress, const string& password, const string& phoneNumber)
{
	{
		lock_guard<mutex> lock(mPasswordLock);

		PasswordFile f(emailAddress, "wb");
		
		f.WriteFile(password);		
	}

	{
		lock_guard<mutex> lock(mPhoneNumberLock);

		PhoneNumberFile f(emailAddress, "wb");

		f.WriteFile(phoneNumber);
	}

	return 0;
}

int FileStorageAccessor::changePassword(const string& emailAddress, const string& password)
{
	lock_guard<mutex> lock(mPasswordLock);

	PasswordFile f(emailAddress, "wb");

	f.WriteFile(password);

	return 0;
}

bool FileStorageAccessor::confirmPassword(const std::string& emailAddress, const std::string& password)
{
	lock_guard<mutex> lock(mPasswordLock);

	PasswordFile f(emailAddress, "rb");

	if (f.GetPF() == nullptr)
	{
		return false;
	}

	string savedPassword = f.ReadFile();

	if (password.compare(0, password.length(), savedPassword, 0, password.length()) == 0)
		return true;
	else
		return false;
}

bool FileStorageAccessor::confirmPhoneNumber(const string& emailAddress, const string& phoneNumber)
{
	lock_guard<mutex> lock(mPhoneNumberLock);

	PhoneNumberFile f(emailAddress, "rb");

	if (f.GetPF() == nullptr)
	{
		return false;
	}

	string savedPhoneNumber = f.ReadFile();

	if (phoneNumber.compare(0, phoneNumber.length(), savedPhoneNumber, 0, phoneNumber.length()) == 0)
		return true;
	else
		return false;
}

string FileStorageAccessor::FindEmailAddress(const string& phoneNumber)
{	
	lock_guard<mutex> lock(mPhoneNumberLock);

	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	wstring path = L"./storage/phonenumber/*";	

	string emailAddress;
	bool bFind = false;
	hFind = FindFirstFile(path.c_str(), &FindFileData);
	while (hFind != INVALID_HANDLE_VALUE)
	{
		wstring wEmailAddress = FindFileData.cFileName;
		if (FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
		{
			string emailAddressBuf(wEmailAddress.begin(), wEmailAddress.end());			
			emailAddress = emailAddressBuf;
			PhoneNumberFile f(emailAddress, "rb");
			string savedPhoneNumber = f.ReadFile();

			if (phoneNumber.compare(0, phoneNumber.length(), savedPhoneNumber, 0, phoneNumber.length()) == 0)
			{
				bFind = true;
				break;
			}
		}	

		if (FindNextFile(hFind, &FindFileData) == FALSE)
			break;
	}
	FindClose(hFind);
	
	if (bFind == true)
	{
		return emailAddress;
	}
	else
	{
		return "";
	}
}

int FileStorageAccessor::confirmPhoneNumberPassword(const string& phoneNumber, const string& password)
{
	string emailAddress = FindEmailAddress(phoneNumber);

	if (emailAddress.compare("") == 0)
	{
		return -1;
	}

	bool bConfirm = confirmPassword(emailAddress, password);
	if (bConfirm == true)
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

#include <regex>
string extractIntegerWords(string str)
{
	string output;
	for (int i = 0; i < str.length(); i++)
	{
		if (isdigit(str[i]))
			output += str[i];
	}
	return output;
}

string FileStorageAccessor::getTempPassword(const string& emailAddress)
{
	lock_guard<mutex> lock(mPasswordLock);

	PasswordFile f(emailAddress, "rb");

	if (f.GetPF() == nullptr)
	{
		return "0000";
	}

	string savedPassword = f.ReadFile();

	string numPassword = extractIntegerWords(savedPassword);

	return numPassword.substr(0, 4);
}

std::string FileStorageAccessor::getEmailAddress(const string& phoneNumber)
{
	string emailAddress;
	WIN32_FIND_DATA FindFileData;
	wstring path = L"./storage/phonenumber/*";
		
	HANDLE hFind = FindFirstFile(path.c_str(), &FindFileData);
	while (hFind != INVALID_HANDLE_VALUE)
	{
		if (FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
		{
			wstring wfilename = FindFileData.cFileName;
			string savedEmailAddress(wfilename.begin(), wfilename.end());			
			
			PhoneNumberFile f(savedEmailAddress, "rb");
			string savedPhoneNumber = f.ReadFile();

			if (savedPhoneNumber.substr(0, phoneNumber.length()).compare(phoneNumber) == 0)
			{				
				if (savedEmailAddress.find(".bin") != string::npos)
					emailAddress = savedEmailAddress.substr(0, savedEmailAddress.length() - 4);
				else
					emailAddress = savedEmailAddress;
					
				break;
			}			
		}

		if (!FindNextFile(hFind, &FindFileData))
			break;
	}
	FindClose(hFind);

	return emailAddress;
}

int FileStorageAccessor::deleteUser(const std::string& emailAddress)
{
	wstring wEmailAddress(emailAddress.begin(), emailAddress.end());
	wstring extension;
	if (emailAddress.substr(emailAddress.length() - 4, 4).compare(".bin") != 0)
		extension = L".bin";
	{
		lock_guard<mutex> lock(mPasswordLock);

		wstring wPath = L"./storage/password/" + wEmailAddress + extension;
		DeleteFile(wPath.c_str());
	}
	{
		lock_guard<mutex> lock(mUserNumberLock);

		wstring wPath = L"./storage/phonenumber/" + wEmailAddress + extension;
		DeleteFile(wPath.c_str());
	}
	{
		lock_guard<mutex> lock(mDSLock);

		wstring wPath = L"./storage/directoryservice/" + wEmailAddress + extension;
		DeleteFile(wPath.c_str());
	}

	return 0;
}

int FileStorageAccessor::getUserNumber()
{
	lock_guard<mutex> lock(mUserNumberLock);

	PasswordFile f("UserNumber", "rb");

	if (f.GetPF())
	{
		string strUserNumber = f.ReadFile();
		int nUserNumber = stoi(strUserNumber);
		return nUserNumber;
	}
	else
	{
		return 0;
	}
}

int FileStorageAccessor::updateUserNumber(int userNumber)
{
	lock_guard<mutex> lock(mUserNumberLock);

	PasswordFile f("UserNumber", "wb");

	string userNumberString = to_string(userNumber);

	f.WriteFile(userNumberString);

	return 0;
}

bool FileStorageAccessor::isExistUser(const std::string& emailAddress)
{
	lock_guard<mutex> lock(mPasswordLock);

	PasswordFile f(emailAddress, "rb");

	if (f.GetSize() > 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int FileStorageAccessor::saveDSItem(UserInfo& userInfo)
{
	lock_guard<mutex> lock(mDSLock);

	if( userInfo.emailAddress.length() == 0 )
		userInfo.emailAddress = FindEmailAddress(userInfo.phoneNumber);

	DerectoryServiceFile f(userInfo.emailAddress, "wb");

	string enable = userInfo.enabled ? "T" : "F";
	string data = userInfo.phoneNumber + "-" + userInfo.ipAddress + "-" + enable;

	f.WriteFile(data);

	return 0;
}

int FileStorageAccessor::getDSItem(const std::string& emailAddress, UserInfo& ui)
{
	lock_guard<mutex> lock(mDSLock);

	DerectoryServiceFile f(emailAddress, "rb");

	if (f.GetPF() == nullptr)
		return -1;

	string data = f.ReadFile();

	size_t offset1 = data.find_first_of('-');
	size_t offset2 = data.find_last_of('-');
	string phoneNumber = data.substr(0, offset1);
	string ipAddress = data.substr(offset1 + 1, offset2 - offset1 - 1);
	string strEnabled = data.substr(offset2 + 1, 1);
	bool enabled = strEnabled.compare("T") == 0 ? true : false;
	ui = { emailAddress, phoneNumber, ipAddress, enabled };

	return 0;
}

vector<UserInfo> FileStorageAccessor::getDSItems()
{
	WIN32_FIND_DATA FindFileData;
	wstring path = L"./storage/directoryservice/*";

	vector<UserInfo> ds;
	HANDLE hFind = FindFirstFile(path.c_str(), &FindFileData);
	while (hFind != INVALID_HANDLE_VALUE)
	{
		if (FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
		{
			wstring wfilename = FindFileData.cFileName;
			string emailAddress(wfilename.begin(), wfilename.end());
			UserInfo ui;
			int err = getDSItem(emailAddress, ui);
			if( err == 0 )
				ds.push_back(ui);
		}

		if (!FindNextFile(hFind, &FindFileData))
			break;
	}
	FindClose(hFind);
	
	return ds;
}

int FileStorageAccessor::disableUser(const std::string& emailAddress)
{
	UserInfo ui;
	int err = getDSItem(emailAddress, ui);
	if (err == 0)
	{
		ui.enabled = false;
		saveDSItem(ui);
		return 0;
	}
	else
	{
		return -1;
	}	
}

int FileStorageAccessor::enableUser(const std::string& emailAddress)
{
	UserInfo ui;
	int err = getDSItem(emailAddress, ui);
	if (err == 0)
	{
		ui.enabled = true;
		saveDSItem(ui);
		return 0;
	}
	else
	{
		return -1;
	}
}

std::vector<std::string> FileStorageAccessor::getCCNumbers()
{
	WIN32_FIND_DATA FindFileData;
	wstring path = L"./storage/conferencecall/*";

	vector<string> ccNum;
	HANDLE hFind = FindFirstFile(path.c_str(), &FindFileData);
	while (hFind != INVALID_HANDLE_VALUE)
	{
		if (FindFileData.dwFileAttributes != FILE_ATTRIBUTE_DIRECTORY)
		{
			wstring wfilename = FindFileData.cFileName;
			string ccNumber(wfilename.begin(), wfilename.end());
			ccNum.push_back(ccNumber);
		}

		if (!FindNextFile(hFind, &FindFileData))
			break;
	}
	FindClose(hFind);

	return ccNum;
}

int FileStorageAccessor::saveCCItem(const string& roomNumber, const string& dateFrom, const string& dateTo, const vector<string>& phoneNumberList)
{
	lock_guard<mutex> lock(mCCLock);

	ConferenceCallFile f(roomNumber, "wb");

	string strParticipantsList;
	const string participantsNum = to_string(phoneNumberList.size());
	for (const auto& i : phoneNumberList)
	{
		strParticipantsList += i + ";";
	}

	const string data = dateFrom + ";" + dateTo + ";" + participantsNum + ";" + strParticipantsList;
	f.WriteFile(data);

	return 0;
}

bool FileStorageAccessor::confirmCCUser(const string& roomNumber, const string& phoneNumber)
{
	lock_guard<mutex> lock(mCCLock);

	ConferenceCallFile f(roomNumber, "rb");

	string data = f.ReadFile();

	if (data.compare("nullptr") == 0)
		return false;

	size_t idx = data.find(";" + phoneNumber + ";");

	if (idx == string::npos)
		return false;
	else
		return true;

	//int offset1 = data.find(';', 0);
	//int offset2 = data.find(';', offset1 + 1);
	//int offset3 = data.find(';', offset2 + 1);
	//string strParticipantsNum = data.substr(offset2, offset3 - offset2 - 1);
	//int participantsNum = stoi(strParticipantsNum);
	
	return true;
}