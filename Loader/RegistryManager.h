#pragma once
class RegistryManager
{
protected:
	std::map<std::string, std::string> RegistryLocations;
	std::string ConvertUnicodeToString(const char*,DWORD buffer);
public:
	std::string GetGameLocation(std::string);

};