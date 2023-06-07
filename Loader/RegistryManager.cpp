#include "pch.h"
#include "RegistryManager.h"



std::string RegistryManager::ConvertUnicodeToString(char* str, DWORD buffer)
{
	std::string ret = "";
	// convert unicode which is 2x the bytesize to our string
	for (int i = 0; i < buffer - 2; i += 2)
	{
		ret += str[i];
	}
	return ret;
}
bool RegistryManager::DoesKeyExist(LPCWSTR key)
{
	HKEY hResultKey;
	LONG result = RegOpenKeyEx(HKEY_LOCAL_MACHINE, key, 0, KEY_READ, &hResultKey); // check if its open

	if (result == ERROR_SUCCESS) // succeeded to open
	{
		RegCloseKey(hResultKey);
		return true; 
	}

	return false;
}
std::string RegistryManager::GetGameLocation(std::string dirname)
{
	if (!this->RegistryLocations[dirname].empty())
		return RegistryLocations[dirname]; // return a value if we already have it
	dirname = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Uninstall\\" + dirname; // directory to the uninstall path. all installed programs are here
	std::wstring widedirname = std::wstring(dirname.begin(), dirname.end()); // convert to wide string
	LPCWSTR ldirname = widedirname.c_str();
	if (!this->DoesKeyExist(ldirname))
		return "";
    char value[1254];
	DWORD buffer = 8192;
	RegGetValue(HKEY_LOCAL_MACHINE, ldirname, L"InstallLocation", RRF_RT_ANY, NULL, (PVOID)&value, &buffer); // query the value
	return this->ConvertUnicodeToString(value, buffer); // translate it

}
