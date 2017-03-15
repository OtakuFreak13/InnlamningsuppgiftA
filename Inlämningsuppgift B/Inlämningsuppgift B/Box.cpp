#include "Box.h"



//Box::Box() : Shape(-1)
//{
//	this->width = -1;
//	this->lenght = -1;
//}

Box::Box(float hight, float width, float length) : Shape(hight)
{
	this->width = width;
	this->lenght = length;
	this->volume = length*hight*width;
}

Box::~Box()
{

}

Box & Box::operator=(Box & orgObj)
{
	this->width = orgObj.width;
	this->lenght = orgObj.lenght;
	this->volume = orgObj.volume;

	return *this;
}

string Box::toStringSpecific()
{
	return"\nWidth: " + to_string(this->width) + "\nLength: " + to_string(this->lenght) + "\nVolume: " + to_string(this->volume)+ "\n";
}

float Box::getWidth()const
{
	return this->width;
}

float Box::getLenght()const
{
	return this->lenght;
}

float Box::getVolume()const
{
	return this->volume;
}

void Box::setWidth(int width)
{
	this->width=width;
}

void Box::setLenght(int length)
{
	this->lenght = length;
}




