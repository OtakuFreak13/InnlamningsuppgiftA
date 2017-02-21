#ifndef BOX_H
#define BOX_H

#include "Shape.h"

class Box :
	public Shape
{
private:
	float width;
	float lenght;
	float volume;
public:
	Box();
	Box(float hight = -1, float width = -1, float length = -1);
	~Box();
	string toStringSpecific();
	float getWidth();
	float getLenght();
	float getVolume();
};


#endif // !BOX_H