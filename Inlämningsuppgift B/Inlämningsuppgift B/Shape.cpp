#include "Shape.h"



Shape::Shape()
{

}

Shape::Shape(float hight)
{
	this->hight = hight;
}


Shape::~Shape()
{

}

float Shape::getHight()const
{


	return 0;
}

string Shape::toString()
{
	

	return this->toStringSpecific();
}
