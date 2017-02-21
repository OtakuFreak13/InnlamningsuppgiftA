#pragma once
#include "Shape.h"
class Box :
	public Shape
{
private:
	int width;
	int lenght;
	int volume;
public:
	Box();
	Box(int hight, int width, int length);
	~Box();
	string toString();
	string toStringSpecific()
};

