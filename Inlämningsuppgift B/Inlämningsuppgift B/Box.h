#pragma once
#include "Shape.h"
class Box :
	public Shape
{
private:
	float width;
	float lenght;
	float volume;
public:
	Box();
	Box(float hight, float width, float length);
	~Box();
	string toStringSpecific();
	float getWidth();
	float getLenght();
	float getVolume();
};

