#include "DBFile.h"
#include <windows.h>
#include <fstream>

using namespace std;

DBFile::DBFile(const std::string& filename, const std::string& access_mode)
{
	wstring rootPath = L"./storage/";	
	CreateDirectory(rootPath.c_str(), NULL);

	wstring wfilename = wstring(filename.begin(), filename.end());
	int filenameOffset = filename.find_last_of('/');	
	wstring subPath = wfilename.substr(0, filenameOffset);
	CreateDirectory(subPath.c_str(), NULL);

	OpenFile(filename, access_mode);
}

DBFile::~DBFile()
{
	CloseFile();
}

void DBFile::OpenFile(const std::string& filename, const std::string& access_mode)
{
	std::string binfile;
	if (filename.substr(filename.length() - 4, 4).compare(".bin") != 0)
		binfile = filename + ".bin";
	else
		binfile = filename;

	ifstream file;
	file.open(binfile.c_str(), ios::in | ios::binary);
	if (file.is_open())
	{
		file.seekg(0, std::ios_base::end);
		mSize = file.tellg();
	}
	file.close();

	fopen_s(&mFile, binfile.c_str(), access_mode.c_str());
}

void DBFile::CloseFile()
{
	if (mFile != nullptr)
		fclose(mFile);
}

void DBFile::WriteFile(const std::string& data)
{
	if(mFile != nullptr)
		fwrite(data.c_str(), data.length(), 1, GetPF());
}

std::string DBFile::ReadFile() const
{
	std::string data(256, '\0');

	if (mFile != nullptr)
	{
		fread(&data[0], GetSize(), 1, GetPF());
		return data;
	}
	else
	{
		return "nullptr";
	}
}