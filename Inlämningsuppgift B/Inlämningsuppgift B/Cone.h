#ifndef CONE_H
#define CONE_H


#include "Shape.h"

class Cone :
	public Shape
{
private:
	float radius;
	float volume;
public:
	//Cone(); // <- on�dig kan anv�nda nedre
	Cone(float hight = -1, float radius = -1);
	//Cone(int hight, int radius);
	~Cone();

	Cone& operator=(Cone& orgObj);
	float getVolume() const;
	float getRadius() const;
	void setRadius(float radius);

	string toStringSpecific();

};



#endif // !CONE_H
