#include "DirectoryService.h"
#include "Hislog.h"

#define LOG_TAG "DirService"

DirectoryService::DirectoryService()
{
}

DirectoryService::~DirectoryService()
{
}

int DirectoryService::update(
                        const std::string& phoneNumber,
                        const std::string& password,
                        const std::string& ipAddress)
{
    std::lock_guard<std::mutex> guard(mLock);
    mBook[phoneNumber] = ipAddress;

    FUNC_LOGI("%s : %s", phoneNumber.c_str(), ipAddress.c_str());

    return 0;
}

int DirectoryService::query(
                        const std::string& phoneNumber,
                        std::string* ipAddress)
{
    std::lock_guard<std::mutex> guard(mLock);
    const auto iter = mBook.find(phoneNumber);
    if (iter == mBook.cend())
        return -1;
    if (iter->second.empty())
        return -2;
    *ipAddress = iter->second;
    return 0;
}

int DirectoryService::remove(
                        const std::string& phoneNumber)
{
    std::lock_guard<std::mutex> guard(mLock);
    return mBook.erase(phoneNumber) ? 0 : -1;
}

