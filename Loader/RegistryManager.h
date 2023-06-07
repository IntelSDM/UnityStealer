#pragma once
class RegistryManager
{
protected:
	std::map<std::string, std::string> RegistryLocations;
	std::string ConvertUnicodeToString(char*,DWORD);
	bool DoesKeyExist(LPCWSTR);
public:
	std::string GetGameLocation(std::string);

};