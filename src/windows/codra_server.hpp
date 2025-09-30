#include "functions.hpp"
#include <string>
void _SV_Init();
void banHWID(const std::string& hwidHash);
void unbanHWID(const std::string& hwidHash);
void _SVC_DirectConnect(netadr_t from);
bool checkHWIDBan(const std::string& hwidHash);