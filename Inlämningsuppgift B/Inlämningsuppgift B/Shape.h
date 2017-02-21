#ifndef SHAPE_H
#define SHAPE_H

#include<string>

using namespace std;

class Shape
{
private:
	int hight;
public:
	Shape();
	Shape(int hight);
	virtual ~Shape();
	int getHight()const;
	string toString();
	virtual string toStringSpecific() = 0;
};


#endif // !SHAPE_H
