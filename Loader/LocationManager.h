#pragma once
class LocationManager
{
protected:
	std::map<std::string, std::string> FileLocations;
public:
	void SetLocation(std::string, std::string);
	std::string GetLocation(std::string);
	bool LocationPresent(std::string);

};