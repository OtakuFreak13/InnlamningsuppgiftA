#pragma once
#include "Shape.h"
# define M_PI           3.14159265358979323846  
class Cone :
	public Shape
{
private:
	float radius; // B�r vara float
	float volume;	// b��r vara float 
public:
	Cone(); // <- on�dig kan anv�nda nedre
	Cone(float hight = -1, float radius = -1); 
	//Cone(int hight, int radius);
	~Cone();	
	
	float getVolume();
	float getRadius();
	void setRadius(float radius);

	string toStringSpecific();
	
};

