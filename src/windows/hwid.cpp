#include <windows.h>
#include <iphlpapi.h>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include "libs/sha256.h" // Add your SHA256 header
#include <cstdint>
#include <regex>

#pragma comment(lib, "iphlpapi.lib")

std::string bytesToHex(const uint8_t* data, size_t length) {
    std::stringstream ss;
    for (size_t i = 0; i < length; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)data[i];
    }
    return ss.str();
}

std::string hashSHA256(const std::string& data) {
    uint8_t hash[32];
    SHA256_CTX ctx;
    sha256_init(&ctx);
    sha256_update(&ctx, reinterpret_cast<const uint8_t*>(data.c_str()), data.size());
    sha256_final(&ctx, hash);
    return bytesToHex(hash, 32);
}


std::string getMACAddress() {
    IP_ADAPTER_INFO AdapterInfo[16];
    DWORD dwBufLen = sizeof(AdapterInfo);

    if (GetAdaptersInfo(AdapterInfo, &dwBufLen) != ERROR_SUCCESS)
        return "";

    PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;
    std::stringstream ss;

    for (UINT i = 0; i < pAdapterInfo->AddressLength; i++) {
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)pAdapterInfo->Address[i];
    }

    return ss.str();
}

std::string getCPUInfo() {
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);

    std::stringstream ss;
    ss << sysInfo.dwProcessorType << sysInfo.dwNumberOfProcessors;
    return ss.str();
}

std::string getGPUInfo() {
    DISPLAY_DEVICEA dd;
    dd.cb = sizeof(dd);

    std::stringstream ss;
    for (int i = 0; EnumDisplayDevicesA(NULL, i, &dd, 0); i++) {
        ss << dd.DeviceID << dd.DeviceString;
    }

    return ss.str();
}

bool isValidSHA256(const std::string& str)
{
    return std::regex_match(str, std::regex("^[A-Fa-f0-9]{64}$"));
}

std::string generateHWID() {
    std::string cpu = getCPUInfo();
    std::string gpu = getGPUInfo();
    std::string mac = getMACAddress();

    std::string combined = cpu + gpu/* + mac*/;
    return hashSHA256(combined);
}
