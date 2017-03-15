#include "Shape.h"



//Shape::Shape()
//{
//
//}

Shape::Shape(float hight)
{
	this->hight = hight;
}


Shape::~Shape()
{

}

Shape & Shape::operator=(Shape & orgObj)
{
	this->hight = orgObj.hight;
	return *this;
}

float Shape::getHight()const
{


	return this->hight;
}

string Shape::toString()
{
	return "Hight: "+to_string(this->hight) + this->toStringSpecific();
}

Shape & Shape::operator==(Shape & orgObj)
{
	this->hight == orgObj.hight;
	return *this;
}
