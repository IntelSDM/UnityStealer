#pragma once
class LocationManager
{
protected:
	std::map<std::string, std::string> FileLocations;
	bool LocationPresent(std::string);
public:
	void SetLocation(std::string, std::string);
	std::string GetLocation(std::string);
	void SortLocations();

};