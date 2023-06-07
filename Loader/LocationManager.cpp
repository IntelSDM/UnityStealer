#include "pch.h"
#include "LocationManager.h"

void LocationManager::SetLocation(std::string name, std::string path)
{
	this->FileLocations[name] = path;
}
// call this before calling get location obviously.
bool LocationManager::LocationPresent(std::string name)
{
	if (this->FileLocations[name] != "")
		return true;
	return false;
}
std::string LocationManager::GetLocation(std::string name)
{
	if (this->LocationPresent(name))
		return this->FileLocations[name];
	return "Error";
}