// #include <windows.h>
// #include <iphlpapi.h>
// #include <iostream>
// #include <sstream>
// #include <iomanip>
// #include <string>
// #include "libs/sha256.h" // Add your SHA256 header
// #include <cstdint>
// #include <regex>

// #pragma comment(lib, "iphlpapi.lib")

// std::string bytesToHex(const uint8_t* data, size_t length) {
//     std::stringstream ss;
//     for (size_t i = 0; i < length; i++) {
//         ss << std::hex << std::setw(2) << std::setfill('0') << (int)data[i];
//     }
//     return ss.str();
// }

// std::string hashSHA256(const std::string& data) {
//     uint8_t hash[32];
//     SHA256_CTX ctx;
//     sha256_init(&ctx);
//     sha256_update(&ctx, reinterpret_cast<const uint8_t*>(data.c_str()), data.size());
//     sha256_final(&ctx, hash);
//     return bytesToHex(hash, 32);
// }


// // Helper: geeeeeepeeeeeeeeeteeeeeeeeeeee
// static std::string sanitizeShort(const std::string& s, size_t maxlen = 24) {
//     std::string out;
//     for (char c : s) if (std::isalnum((unsigned char)c)) out += c;
//     if (out.size() > maxlen) out.resize(maxlen);
//     return out;
// }

// std::string getHDDSerialNumber() {
//     // Try physical drive 0 (better than volume serial)
//     HANDLE h = CreateFileA("\\\\.\\PhysicalDrive0",
//                            GENERIC_READ,
//                            FILE_SHARE_READ | FILE_SHARE_WRITE,
//                            NULL,
//                            OPEN_EXISTING,
//                            0,
//                            NULL);
//     if (h != INVALID_HANDLE_VALUE) {
//         // Query device descriptor
//         STORAGE_PROPERTY_QUERY query = {};
//         query.PropertyId = StorageDeviceProperty;
//         query.QueryType = PropertyStandardQuery;

//         // allocate buffer reasonably large
//         const DWORD bufSize = 1024;
//         BYTE buffer[bufSize];
//         DWORD bytes = 0;
//         if (DeviceIoControl(h,
//                             IOCTL_STORAGE_QUERY_PROPERTY,
//                             &query,
//                             sizeof(query),
//                             buffer,
//                             bufSize,
//                             &bytes,
//                             NULL)) {
//             STORAGE_DEVICE_DESCRIPTOR* desc = reinterpret_cast<STORAGE_DEVICE_DESCRIPTOR*>(buffer);
//             if (desc->SerialNumberOffset && desc->SerialNumberOffset < bytes) {
//                 char* sn = reinterpret_cast<char*>(buffer + desc->SerialNumberOffset);
//                 std::string serial = sn;
//                 CloseHandle(h);
//                 return sanitizeShort(serial);
//             }
//         }
//         CloseHandle(h);
//     }

//     DWORD volSerial = 0;
//     if (GetVolumeInformationA("C:\\", NULL, 0, &volSerial, NULL, NULL, NULL, 0)) {
//         // format as hex string (8 chars) and sanitize
//         char buf[16];
//         sprintf_s(buf, "%08X", volSerial);
//         return sanitizeShort(std::string(buf));
//     }

//     return ""; // nothing found
// }

// std::string getMACAddress() {
//     IP_ADAPTER_INFO AdapterInfo[16];
//     DWORD dwBufLen = sizeof(AdapterInfo);

//     if (GetAdaptersInfo(AdapterInfo, &dwBufLen) != ERROR_SUCCESS)
//         return "";

//     PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;
//     std::stringstream ss;

//     for (UINT i = 0; i < pAdapterInfo->AddressLength; i++) {
//         ss << std::hex << std::setw(2) << std::setfill('0') << (int)pAdapterInfo->Address[i];
//     }

//     return ss.str();
// }

// std::string getCPUInfo() {
//     SYSTEM_INFO sysInfo;
//     GetSystemInfo(&sysInfo);

//     std::stringstream ss;
//     ss << sysInfo.dwProcessorType << sysInfo.dwNumberOfProcessors;
//     return ss.str();
// }

// std::string getGPUInfo() {
//     DISPLAY_DEVICEA dd;
//     dd.cb = sizeof(dd);

//     std::stringstream ss;
//     for (int i = 0; EnumDisplayDevicesA(NULL, i, &dd, 0); i++) {
//         ss << dd.DeviceID << dd.DeviceString;
//     }

//     return ss.str();
// }

// bool isValidSHA256(const std::string& str)
// {
//     return std::regex_match(str, std::regex("^[A-Fa-f0-9]{64}$"));
// }

// std::string generateHWID() {
//     std::string cpu = getCPUInfo();
//     std::string gpu = getGPUInfo();
//     std::string mac = getMACAddress();
//     std::string hdd = getHDDSerialNumber();

//     std::string combined = /*cpu + gpu + mac*/ hdd;
//     return hashSHA256(combined);
// }

// std::string generatenohashHWID()
// {

//     std::string hdd = getHDDSerialNumber();

//     return hdd;
// }

#include <windows.h>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <regex>

#include "libs/sha256.h" //SHAAAAAAAAAAAAAAAAAAAAAAA 2222222225555555666 LIBBB RAHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH

std::string bytesToHex(const uint8_t* data, size_t length) {
    std::stringstream ss;
    for (size_t i = 0; i < length; i++)
        ss << std::hex << std::setw(2) << std::setfill('0') << (int)data[i];
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

bool isValidSHA256(const std::string& str)
{
    return std::regex_match(str, std::regex("^[A-Fa-f0-9]{64}$"));
}

std::string getDriveSerial(const std::string& driveLetter) {
    DWORD serialNumber = 0;
    if (GetVolumeInformationA((driveLetter + ":\\").c_str(), nullptr, 0, &serialNumber, nullptr, nullptr, nullptr, 0)) {
        std::stringstream ss;
        ss << std::hex << serialNumber;
        return ss.str();
    }
    return "";
}

bool isSSD(const std::string& driveLetter) {
    HANDLE hDevice;
    std::string path = "\\\\.\\" + driveLetter + ":";
    hDevice = CreateFileA(path.c_str(), 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
    if (hDevice == INVALID_HANDLE_VALUE) return false;

    STORAGE_PROPERTY_QUERY query;
    ZeroMemory(&query, sizeof(query));
    query.PropertyId = StorageDeviceSeekPenaltyProperty;
    query.QueryType = PropertyStandardQuery;

    BYTE buffer[sizeof(DEVICE_SEEK_PENALTY_DESCRIPTOR)] = {0};
    DWORD bytesReturned = 0;
    BOOL result = DeviceIoControl(hDevice, IOCTL_STORAGE_QUERY_PROPERTY, &query, sizeof(query),
                                  &buffer, sizeof(buffer), &bytesReturned, NULL);
    CloseHandle(hDevice);

    if (!result) return false;

    DEVICE_SEEK_PENALTY_DESCRIPTOR* desc = reinterpret_cast<DEVICE_SEEK_PENALTY_DESCRIPTOR*>(buffer);
    return desc->IncursSeekPenalty == FALSE; // FALSE = SSD, TRUE = HDD
}

std::string generateHWID() {
    DWORD drives = GetLogicalDrives();
    std::string serial;

    for (char letter = 'C'; letter <= 'Z'; letter++) {
        if (!(drives & (1 << (letter - 'A')))) continue;
        UINT type = GetDriveTypeA((std::string(1, letter) + ":\\").c_str());
        if (type != DRIVE_FIXED) continue;

        std::string driveSerial = getDriveSerial(std::string(1, letter));
        if (driveSerial.empty()) continue;

        if (isSSD(std::string(1, letter))) {
            serial = driveSerial; // Prefer SSD
            break;
        } else if (serial.empty()) {
            serial = driveSerial; // First HDD if no SSD found yet
        }
    }

    if (serial.empty()) serial = "unknown";
    return hashSHA256(serial);
}
