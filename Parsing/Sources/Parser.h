#pragma once
#include <fstream>
#include <map>
#include <string>

#define ToInt(x) std::stoi(x)
#define ToFloat(x) std::stof(x)
#define ToDouble(x) std::stod(x)
#define ToBool(x) x == "true" ? true : false

inline std::string operator""_s(const char* _string, size_t _size)
{
	return std::string(_string, _size);
}

inline bool operator""_b(const char* _string, size_t _size)
{
	return (bool)(std::stoi(std::string(_string, _size)));
}

class Values
{
public:
    /**
     * @brief Construct a new Values object.
     * 
     * @param _path The path to the file containing the values.
     * @param _object The object to retrieve values for.
     */
    Values(const std::string& _path, const std::string& _object);

    /**
     * @brief Destroy the Values object.
     * 
     */
    ~Values() = default;

    /**
     * @brief Get the value associated with the specified object.
     * 
     * @param _object The object to retrieve the value for.
     * @return const std::string& The value associated with the object.
     */
    const std::string& operator[](const std::string& _object) const;

    /**
     * @brief Get the map of values.
     * 
     * @return std::map<std::string, std::string>& The map of values.
     */
    std::map<std::string, std::string>& GetMap();

private:
    /**
     * @brief Replace all occurrences of a substring in a string.
     * 
     * @param _string The string to perform the replacement on.
     * @param _from The substring to replace.
     * @param _to The replacement substring.
     * @return std::string The string with all occurrences replaced.
     */
    std::string ReplaceAll(std::string _string, const std::string& _from, const std::string& _to);

    /**
     * @brief Check if a file exists.
     * 
     * @param _filePath The path to the file.
     * @return bool True if the file exists, false otherwise.
     */
    bool FileExist(const std::string& _filePath);

private:
    std::map<std::string, std::string> m_mapValue;
};
