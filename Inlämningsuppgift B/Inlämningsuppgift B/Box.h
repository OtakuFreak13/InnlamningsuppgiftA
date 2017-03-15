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
	//Box();
	Box(float hight = -1, float width = -1, float length = -1);
	~Box();

	Box& operator=(Box& orgObj);
	string toStringSpecific();
	float getWidth()const;
	float getLenght()const;
	float getVolume()const;
	void setWidth(int width);
	void setLenght(int lenght);

};


#endif // !BOX_H