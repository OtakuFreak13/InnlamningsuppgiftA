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
}

Box::~Box()
{

}

Box & Box::operator=(const Box & orgObj)
{
	Shape::operator=(orgObj);
	this->width = orgObj.width;
	this->lenght = orgObj.lenght;

	return *this;
}

string Box::toStringSpecific()const
{
	return"\nWidth: " + to_string(this->width) + "\nLength: " + to_string(this->lenght) + "\n";
}

float Box::getWidth()const
{
	return this->width;
}

float Box::getLenght()const
{
	return this->lenght;
}

void Box::setWidth(int width)
{
	this->width=width;
}

void Box::setLenght(int length)
{
	this->lenght = length;
}

float Box::volume()const
{
	return this->lenght*this->getHight()*this->width;
}




