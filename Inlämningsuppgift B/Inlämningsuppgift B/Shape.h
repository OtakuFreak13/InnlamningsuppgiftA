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
	virtual ~Shape();
	int getHight()const;
	virtual string toString() = 0;
};


#endif // !SHAPE_H
