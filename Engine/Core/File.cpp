#include "File.h"
#include "Logger.h"
#include <filesystem>
#include <fstream>

void neu::SetFilePath(const std::string& pathname)
{
	std::filesystem::current_path(pathname);
}

std::string neu::GetFilePath()
{
	return std::filesystem::current_path().string();
}

bool neu::FileExists(const std::string& pathname)
{
	return std::filesystem::exists(pathname);
}

bool neu::GetFileSize(const std::string& pathname, size_t& size)
{
	if (!FileExists(pathname)) return false;
	size = std::filesystem::file_size(pathname);

	return true;
}

bool neu::ReadFile(const std::string& pathname, std::string& buffer)
{
	if (!FileExists(pathname))
	{
		LOG("Error Could not read file %s", pathname.c_str());
		return false;
	}
	size_t size;
	GetFileSize(pathname, size);
	buffer.resize(size);

	std::ifstream stream(pathname);
	stream.read(buffer.data(), size);
	stream.close();

	return true;
}