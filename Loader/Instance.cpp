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

RegistryManager* RegistryManagerInstance;

RegistryManager* GetRegistryManager()
{
	return RegistryManagerInstance;
}
void CreateRegistryManager()
{
	RegistryManagerInstance = new RegistryManager();
}

PayloadManager* PayloadManagerInstance;

PayloadManager* GetPayloadManager()
{
	return PayloadManagerInstance;
}
void CreatePayloadManager()
{
	PayloadManagerInstance = new PayloadManager();
}