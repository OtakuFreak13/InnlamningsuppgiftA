#ifndef SHAPE_H
#define SHAPE_H

#include<string>

using namespace std;

class Shape
{
private:
	float hight;
public:
	//Shape();
	Shape(float hight = -1);
	virtual ~Shape();
	Shape& operator=(Shape& orgObj);
	float getHight()const;
	string toString();
	virtual string toStringSpecific() = 0;
	Shape& operator==(Shape& orgObj);
};


#endif // !SHAPE_H
