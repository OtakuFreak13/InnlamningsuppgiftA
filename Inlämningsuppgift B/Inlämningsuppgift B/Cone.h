#pragma once
#include "Shape.h"
class Cone :
	public Shape
{
private:
	int radius;
	int volume();
public:
	Cone();
	~Cone();
	string toString();
	string toStringSpecific();
};

