#include "pch.h"
#include "PayloadManager.h"
#include "Instance.h"
void PayloadManager::LoadFile(std::string name, std::string file)
{
	std::string path = GetLocationManager()->GetLocation(name);
	if (path == "")
		return; // skip null directories
	// get pat to file
	char buffer[MAX_PATH];
	GetModuleFileNameA(NULL, buffer, MAX_PATH); // pass null handle returning this process handle
	std::string::size_type pos = std::string(buffer).find_last_of("\\/"); // to last directory
	std::string directory = std::string(buffer).substr(0, pos);

	std::filesystem::path filepath = directory + "/" + file;
	if (!std::filesystem::exists(filepath))
		return;

	std::cout <<name << " ) " << "Loading File: " << file << std::endl;

	// read our file
	std::ifstream stream(directory + "/" + file, std::ios::in | std::ios::binary);
	std::vector<uint8_t> bytearray;

	// check if we can write to it
	if (!stream.is_open())
		return;

	// change file format
	stream.unsetf(std::ios::skipws);
	// insert file bytes to byte array
	bytearray.insert(
		bytearray.begin(),
		std::istream_iterator<uint8_t>(stream),
		std::istream_iterator<uint8_t>()
	);

	// write the file in the new location
	std::ofstream fout(path + "/" + file, std::ios::out | std::ios::binary);
	fout.write((char*)bytearray.data(), bytearray.size());
	fout.close();
}