#pragma once
#include "Shape.h"
# define M_PI           3.14159265358979323846  
class Cone :
	public Shape
{
private:
	float radius; // Bör vara float
	float volume;	// bäör vara float 
public:
	Cone(); // <- onödig kan använda nedre
	Cone(float hight = -1, float radius = -1); 
	//Cone(int hight, int radius);
	~Cone();	
	
	float getVolume();
	float getRadius();
	void setRadius(float radius);

	string toStringSpecific();
	
};

