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

Shape & Shape::operator=(const Shape & orgObj)
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
	return "Hight: "+to_string(this->hight) + "\nVolume: " + to_string(this->volume()) + this->toStringSpecific();
}

bool Shape::operator==(const Shape & orgObj)const
{
	return this->hight == orgObj.hight;
}

void Shape::setHight(float newHight)
{
	this->hight = newHight;
}
