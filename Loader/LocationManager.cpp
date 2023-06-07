#include "pch.h"
#include "LocationManager.h"

void LocationManager::SetLocation(std::string name, std::string path)
{
	this->FileLocations[name] = path;
}
// call this before calling get location obviously.
bool LocationManager::LocationPresent(std::string name)
{
	if (!this->FileLocations[name].empty())
		return true;
	return false;
}
std::string LocationManager::GetLocation(std::string name)
{
	if (this->LocationPresent(name))
		return this->FileLocations[name];
	return "";
}
void LocationManager::SortLocations()
{
	// this is made incase you want to make a public list and then loop all of the entities
	std::list<std::string>scrap;
	for (std::pair<const std::string, std::string> dirpair : this->FileLocations)
	{
		if (dirpair.second == "") // check for null file directory
			scrap.push_back(dirpair.first); // cant remove while looping it
	}
	for (std::string first : scrap)
	{
		this->FileLocations.erase(first); // remove outside of looping the file locations
	}
}