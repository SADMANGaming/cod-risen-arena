#include <string>
#include <iostream>

std::string generateHWID();
bool isValidSHA256(const std::string& str);
std::string hashSHA256(const std::string& data);
