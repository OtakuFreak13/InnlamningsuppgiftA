#include "Box.h"



Box::Box() : Shape(-1)
{
	this->width = -1;
	this->lenght = -1;
}

Box::Box(float hight, float width, float length) : Shape(hight)
{
	this->width = width;
	this->lenght = length;
}

Box::~Box()
{

}

string Box::toStringSpecific()
{
	return "This is a box";
}

float Box::getWidth()
{
	return this->width;
}

float Box::getLenght()
{
	return this->lenght;
}

float Box::getVolume()
{
	return this->volume;
}
