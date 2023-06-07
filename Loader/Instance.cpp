#include "pch.h"
#include "Instance.h"
LocationManager* LocationManagerInstance;
LocationManager* GetLocationManager()
{
	return LocationManagerInstance;
}
void CreateLocationManager()
{
	LocationManagerInstance = new LocationManager();
}