#ifndef SHAPEREGISTER_H
#define SHAPEREGISTER_H

#include"Box.h"
#include"Cone.h"
#include"Shape.h"


class ShapeRegister
{
private:
	int capacity;
	int amountOfShapes;
	Shape* *shapes;
	void initiate(int from = 0);
	void expand();
	bool checkUniq(float hight)const;
public:
	ShapeRegister(int capacity = 5);
	ShapeRegister(const ShapeRegister& orgObj);
	~ShapeRegister();
	bool addCone(float hight, float radius);
	bool addBox(float hight, float width, float lenght);
	bool removeShape(float hight);
	bool getAllShapesAsStrings(string arr[], int capOfArr)const;
	bool getAllConesAsStrings(string arr[], int capOfArr)const;
	bool getAllBoxesAsStrings(string arr[], int capOfArr)const;
	bool editACone(float hight,float radius, float newHight);
	bool editABox(float hight,float width, float length, float newHeight);
	int nrOfShapes()const;
	int nrOfCones()const;
	int nrOfBoxes()const;
	ShapeRegister &operator=(const ShapeRegister &orgObj);
	
};


#endif // !SHAPEREGISTER_H

