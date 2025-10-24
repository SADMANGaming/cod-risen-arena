#include "functions.hpp"
#include <string>
void _SV_Init();
void SV_Init_Hostname();
void banHWID(const std::string& hwidHash);
void unbanHWID(const std::string& hwidHash);
void _SVC_DirectConnect(netadr_t from);
bool checkHWIDBan(const std::string& hwidHash);
void custom_SV_AddOperatorCommands();
void Cmd_Unban();
void Cmd_Ban();
void SVC_Status(netadr_t from);
void custom_SVC_Status(netadr_t from);