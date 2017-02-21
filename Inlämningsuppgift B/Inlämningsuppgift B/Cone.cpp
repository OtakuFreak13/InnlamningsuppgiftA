#include "Cone.h"




Cone::Cone() : Shape(-1) // hight = 0 <- du har inte definerat hight... 
{						//Shape konstruktorn tar emot height; så länge vi skickar med något till den så kommer det agera som height...
	this->radius = -1;
}

Cone::Cone(float hight, float radius) :Shape(hight)
{
	this->radius = radius;
	this->volume = M_PI*radius * radius*hight / 3;
}


Cone::~Cone()
{

}



string Cone::toStringSpecific()
{
	return "This is a Cone";
}

float Cone::getRadius()
{
	return this->radius;
}

float Cone::getVolume()
{
	return this->volume;
}


void Cone::setRadius(float radius)
{
	this->radius = radius;
}

