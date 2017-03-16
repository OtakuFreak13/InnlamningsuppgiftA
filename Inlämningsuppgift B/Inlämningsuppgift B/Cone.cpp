#include "Cone.h"

#define M_PI           3.14159265358979323846  


//Cone::Cone() : Shape(-1) // hight = 0 <- du har inte definerat hight... 
//{						//Shape konstruktorn tar emot height; så länge vi skickar med något till den så kommer det agera som height...
//	this->radius = -1;
//}

Cone & Cone::operator=(const Cone & orgObj)
{
	Shape::operator=(orgObj);

	this->radius = orgObj.radius;
	return *this;
}

Cone::Cone(float hight, float radius) :Shape(hight)
{
	this->radius = radius;
}


Cone::~Cone()
{

}



string Cone::toStringSpecific()const
{
	
	return "\nRadius: " + to_string(this->radius)+"\n";
}

float Cone::volume()const
{
	return M_PI*this->radius * this->radius*this->getHight() / 3;
}

float Cone::getRadius()const
{
	return this->radius;
}



void Cone::setRadius(float radius)
{
	this->radius = radius;
}

