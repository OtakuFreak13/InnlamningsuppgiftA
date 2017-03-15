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
public:
	ShapeRegister(int capacity = 5);
	ShapeRegister(const ShapeRegister& orgObj);
	~ShapeRegister();
	bool addCone(float hight, float radius);
	bool addBox(float hight, float width, float lenght);
	bool removeShape(float hight);
	bool getAllShapesAsStrings(string arr[], int capOfArr);
	bool getAllConesAsStrings(string arr[], int capOfArr);
	bool getAllBoxesAsStrings(string arr[], int capOfArr);
	bool editACone(float hight,float radius);
	bool editABox(float hight,float width, float );
	int nrOfShapes();
	int nrOfCones();
	int nrOfBoxes();
	ShapeRegister operator=(ShapeRegister orgObj);
};


#endif // !SHAPEREGISTER_H

