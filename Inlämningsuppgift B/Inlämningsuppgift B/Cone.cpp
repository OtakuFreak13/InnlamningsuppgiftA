#include "Cone.h"

#define M_PI           3.14159265358979323846  


//Cone::Cone() : Shape(-1) // hight = 0 <- du har inte definerat hight... 
//{						//Shape konstruktorn tar emot height; så länge vi skickar med något till den så kommer det agera som height...
//	this->radius = -1;
//}

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
	
	return "\nRadius: " + to_string(this->radius)+"\nVolume: "+ to_string(this->volume)+"\n";
}

float Cone::getRadius()const
{
	return this->radius;
}

Cone & Cone::operator=(Cone & orgObj)
{
	this->radius = orgObj.radius;
	this->volume = orgObj.volume;

	return *this;
}

float Cone::getVolume()const
{
	return this->volume;
}


void Cone::setRadius(float radius)
{
	this->radius = radius;
}

