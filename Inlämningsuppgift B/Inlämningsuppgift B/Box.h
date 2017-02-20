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
	Box(int width,int length) : shape(int hight);
	~Box();
};

