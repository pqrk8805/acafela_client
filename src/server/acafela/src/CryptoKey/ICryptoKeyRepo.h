#pragma once

#include <stdint.h>
#include <vector>

class ICryptoKeyRepo
{
protected:
        ICryptoKeyRepo() {}
        ICryptoKeyRepo(const ICryptoKeyRepo&) = delete;
        ICryptoKeyRepo& operator=(const ICryptoKeyRepo&) = delete;
public:
    virtual ~ICryptoKeyRepo() {}

    virtual std::vector<char> getKey(
                                const std::string sessionId) = 0;
};
