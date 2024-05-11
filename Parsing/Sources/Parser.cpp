#include <iostream>

#include "Parser.h"

Values::Values(const std::string& _path, const std::string& _object)
{
	// Checking if the file exist
	if (FileExist(_path) == false)
	{
		// Bad things append here
		std::cout << "Failed to open : " + _path + ". File does not exist\n";
		return;
	}
	std::ifstream file;

	// Openning the file
	file.open(_path);

	char line[64]("");
	std::string lineString("");
	std::string key("");
	std::string value("");
	size_t size(0);

	while (!file.eof())
	{
		// Getting the first line of the file
		file.getline(line, 64, '\n');
		// Setting the Char* to a std::string
		lineString = line;

		// Check if the line is a balise
		if (lineString[0] != '[') continue;
		// Delete the '[' & ']' from the balise to get the object name
		lineString = lineString.substr((size_t)1, lineString.size() - 2);

		// Check if it's the right object
		if (lineString != _object) continue;

		// Get the '{' line after the object name
		file.getline(line, 64, '\n');

		bool readIsFinished(false);

		// Read the file wile the object isn't finished
		while (readIsFinished == false)
		{
			file.getline(line, 64, '\n');
			lineString = line;

			lineString = ReplaceAll(lineString, " ", "");

			// Check if the object has been parse

			if (lineString == "}")
			{
				readIsFinished = true;
				break;
			}

			// Dead line and extract key and value
			size = lineString.find(":");

			key = lineString.substr((size_t)0, size);
			value = lineString.substr(size + 1, lineString.size());

			m_mapValue[key] = value;
		}
	}
	file.close();
}

const std::string& Values::operator[](const std::string& _key) const
{
	if (m_mapValue.find(_key) == m_mapValue.end())
	{
		std::cout << "Failed to find : " + _key + " in the map\n";
		return "";
	}
	return m_mapValue.at(_key);
}

std::map<std::string, std::string>& Values::GetMap()
{
	return m_mapValue;
}

std::string Values::ReplaceAll(std::string _string, const std::string& _from, const std::string& _to)
{
	size_t startPosition = 0;
	while ((startPosition = _string.find(_from, startPosition)) != std::string::npos)
	{
		_string.replace(startPosition, _from.length(), _to);
		startPosition += _to.length();
	}
	return _string;
}

bool Values::FileExist(const std::string& _filePath)
{
	struct stat buffer;
	return (stat(_filePath.c_str(), &buffer) == 0);
}
