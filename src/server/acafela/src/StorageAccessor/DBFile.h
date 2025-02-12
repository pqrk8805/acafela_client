#pragma once
#include <string>

class DBFile
{
public:
	DBFile() {}
	DBFile(const std::string& filename, const std::string& access_mode);
	~DBFile();
	FILE* GetPF() const { return mFile; }
	int GetSize() const { return mSize; }
	void OpenFile(const std::string& filename, const std::string& access_mode);
	void CloseFile();
	void WriteFile(const std::string& data);
	std::string ReadFile() const;
private:
	FILE* mFile = nullptr;
	int mSize = -1;
};

class PasswordFile : public DBFile
{
public:
	PasswordFile(const std::string& filename, const std::string& access_mode) :
		DBFile("./storage/password/" + filename, access_mode)
	{
	}
};

class PhoneNumberFile : public DBFile
{
public:
	PhoneNumberFile(const std::string& filename, const std::string& access_mode) :
		DBFile("./storage/phonenumber/" + filename, access_mode)
	{
	}
};

class DerectoryServiceFile : public DBFile
{
public:
	DerectoryServiceFile(const std::string& filename, const std::string& access_mode) :
		DBFile("./storage/directoryservice/" + filename, access_mode)
	{
	}
};

class ConferenceCallFile : public DBFile
{
public:
	ConferenceCallFile(const std::string& filename, const std::string& access_mode) :
		DBFile("./storage/conferencecall/" + filename, access_mode)
	{
	}
};
