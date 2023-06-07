#include "pch.h"
#include "RegistryManager.h"



std::string RegistryManager::ConvertUnicodeToString(char* str, DWORD buffer)
{
	std::string ret = "";
	for (int i = 0; i < buffer - 2; i += 2)
	{
		ret += str[i];
	}
	return ret;
}

std::string RegistryManager::GetGameLocation(std::string dirname)
{
	if (!this->RegistryLocations[dirname].empty())
		return RegistryLocations[dirname];
	dirname = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\" + dirname;
	std::wstring widedirname = std::wstring(dirname.begin(), dirname.end());
	LPCWSTR ldirname = widedirname.c_str();

	char value[255];
	DWORD buffer = 8192;
	RegGetValue(HKEY_LOCAL_MACHINE, ldirname, L"InstallLocation", RRF_RT_ANY, NULL, (PVOID)&value, &buffer);
	return this->ConvertUnicodeToString(value, buffer);

}
