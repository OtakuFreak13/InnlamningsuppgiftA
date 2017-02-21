#include "Box.h"



Box::Box()
{

}

Box::Box(int hight, int width, int length) : Shape(hight)
{
	this->width = width;
	this->lenght = length;
}

Box::~Box()
{

}

string Box::toString()
{
	return string();
}
