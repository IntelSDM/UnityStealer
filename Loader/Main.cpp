#include "pch.h"
#include "Instance.h"
/*
This entire loader project isn't required!
It just shows you how you might go about getting a game path and how to treat game paths.
This ideally should be done in js on a browser using an authority exploit to be able to drop files or just set a file download path on windows
This can also be done from a malicious app on the pc in order to keep opening itself.
Only run in 64bit
Method 1, 2 copies of the game
*/

void main()
{
	CreateLocationManager();
	CreateRegistryManager();

	std::cout << GetRegistryManager()->GetGameLocation("{6F320B93-EE3C-4826-85E0-ADF79F8D4C61}") << std::endl;
	// Get locations of 3 main unity games
	GetLocationManager()->SetLocation("7DTD", GetRegistryManager()->GetGameLocation("Steam App 251570"));
	GetLocationManager()->SetLocation("Unturned", GetRegistryManager()->GetGameLocation("Steam App 304930"));
	GetLocationManager()->SetLocation("EFT", GetRegistryManager()->GetGameLocation("EscapeFromTarkov"));

	std::cout << GetLocationManager()->GetLocation("7DTD") << std::endl;
	std::cout << GetLocationManager()->GetLocation("Unturned") << std::endl;
	std::cout << GetLocationManager()->GetLocation("EFT") << std::endl;

	GetPayloadManager()->LoadFile("7DTD", "0Harmony.dll");
	GetLocationManager()->SortLocations();
	
}