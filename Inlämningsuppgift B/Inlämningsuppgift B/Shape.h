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
	Shape& operator=(const Shape& orgObj);
	float getHight()const;
	string toString();
	virtual string toStringSpecific() const = 0;
	virtual float volume() const = 0;
	bool operator==(const Shape& orgObj)const;
	void setHight(float newHight);
};


#endif // !SHAPE_H
