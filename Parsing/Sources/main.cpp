#include <iostream>

#include "SpriteTest.h"

int main(void)
{
	std::cout << "Start" << std::endl;

	// Here we try to read the values from the file Sprite.txt for the object named Default
	Values data("Sprite.txt", "Default");
	// Then we print the values
	for (auto [_key, _value] : data.GetMap())
	{
		std::cout << _key << " " << _value << "\n";
	}
	std::cout << "End\n\n" << std::endl;

	// Here we create a sprite with the values we just read
	Sprite sprite(data);
	std::cout << "Sprite values:\n";
	std::cout << "PositionX: " << sprite.PositionX << "\n";
	std::cout << "PositionY: " << sprite.PositionY << "\n";
	std::cout << "PositionZ: " << sprite.PositionZ << "\n";
	std::cout << "Origin: " << sprite.Origin << "\n";
	std::cout << "Rotation: " << sprite.Rotation << "\n";
	std::cout << "ShaderType: " << sprite.ShaderType << "\n";

	return 0;
}