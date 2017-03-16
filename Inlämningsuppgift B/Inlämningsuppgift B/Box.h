#ifndef BOX_H
#define BOX_H

#include "Shape.h"

class Box :
	public Shape
{
private:
	float width;
	float lenght;
public:
	//Box();
	Box(float hight = -1, float width = -1, float length = -1);
	~Box();

	Box& operator=(const Box& orgObj);
	string toStringSpecific()const;
	float getWidth()const;
	float getLenght()const;
	void setWidth(int width);
	void setLenght(int lenght);
	float volume()const;

};


#endif // !BOX_H