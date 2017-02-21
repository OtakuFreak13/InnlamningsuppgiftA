#ifndef SHAPE_H
#define SHAPE_H

#include<string>

using namespace std;

class Shape
{
private:
	float hight;
public:
	Shape();
	Shape(float hight = -1);
	virtual ~Shape();
	float getHight()const;
	string toString();
	virtual string toStringSpecific() = 0;
};


#endif // !SHAPE_H
