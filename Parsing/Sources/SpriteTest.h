#pragma once
#include "Parser.h"

// Sprite class for example
class Sprite
{
public:
	float PositionX;
	float PositionY;
	float PositionZ;
	float ScaleX;
	float ScaleY;
	int Origin;
	float Rotation;
	int ShaderType;
	bool UseGlobalShader;
	std::string TexturePath;
	bool HasAnimation;
	int AnimNumberX;
	int AnimNumberY;
	float AnimTimer;

	Sprite(Values _value)
		: PositionX(ToFloat(_value["PositionX"]))
		, PositionY(ToFloat(_value["PositionY"]))
		, PositionZ(ToFloat(_value["PositionZ"]))
		, ScaleX(ToFloat(_value["ScaleX"]))
		, ScaleY(ToFloat(_value["ScaleY"]))
		, Origin(ToInt(_value["Origin"]))
		, Rotation(ToFloat(_value["Rotation"]))
		, ShaderType(ToInt(_value["ShaderType"]))
		, UseGlobalShader(ToBool(_value["UseGlobalShader"]))
		, TexturePath(_value["TexturePath"])
		, HasAnimation(ToBool(_value["HasAnimation"]))
		, AnimNumberX(ToInt(_value["AnimNumberX"]))
		, AnimNumberY(ToInt(_value["AnimNumberY"]))
		, AnimTimer(ToFloat(_value["AnimTimer"]))
	{
	}
};