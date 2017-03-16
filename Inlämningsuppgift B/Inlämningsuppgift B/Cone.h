#ifndef CONE_H
#define CONE_H


#include "Shape.h"

class Cone :
	public Shape
{
private:
	float radius;
public:
	//Cone(); // <- onödig kan använda nedre
	Cone(float hight = -1, float radius = -1);
	//Cone(int hight, int radius);
	~Cone();

	Cone& operator=(const Cone& orgObj);
	float getRadius() const;
	void setRadius(float radius);

	string toStringSpecific()const;

	float volume()const;

};



#endif // !CONE_H
