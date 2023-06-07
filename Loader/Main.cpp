#include "pch.h"
#include "Instance.h"
/*
This entire loader project isn't required!
It just shows you how you might go about getting a game path and how to treat game paths.
This ideally should be done in js on a browser using an authority exploit to be able to drop files or just set a file download path on windows
This can also be done from a malicious app on the pc in order to keep opening itself.

Method 1, 2 copies of the game
*/

void main()
{
	CreateLocationManager();
	CreateRegistryManager();

	std::cout << GetRegistryManager()->GetGameLocation("{B0FDA062-7581-4D67-B085-C4E7C358037F}_is1");
}