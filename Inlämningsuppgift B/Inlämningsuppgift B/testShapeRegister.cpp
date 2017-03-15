#include<iostream>
#include"Box.h"
#include"Cone.h"
#include"Shape.h"
#include"ShapeRegister.h"

void test()
{

	cout << "Test 1: Skapa 2 shapes, cone och box" << endl;

	ShapeRegister shapes(2);
	shapes.addCone(5, 2.5);
	shapes.addBox(4, 3, 6);

	int arrCap = 2;
	string *list = new string[arrCap];
	shapes.getAllShapesAsStrings(list, arrCap);
	for (int i = 0; i < arrCap; i++) 
	{
		cout << list[i] << endl;
	}

	cout << "Test 2" << endl;
	shapes.addBox(1, 2, 7);
	shapes.getAllShapesAsStrings(list, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list[i] << endl;
	}

	cout << "Test 3" << endl;
	shapes.removeShape(19);
	shapes.getAllShapesAsStrings(list, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list[i] << endl;
	}

	cout << "Test 4" << endl;
	shapes.removeShape(1);
	shapes.getAllShapesAsStrings(list, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list[i] << endl;
	}

	cout << "Test 5" << endl;
	shapes.removeShape(5);
	shapes.removeShape(4);
	shapes.getAllShapesAsStrings(list, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list[i] << endl;
	}

	cout << "Test 6" << endl;
	shapes.addBox(6, 6, 6);
	shapes.addCone(8, 6);
	shapes.getAllShapesAsStrings(list, 3);	
	for (int i = 0; i < arrCap; i++)
	{
		cout << list[i] << endl;
	}

	cout << "Test 6" << endl;
	//TODO testa copy och annat
	ShapeRegister shapes2;
	shapes2 = shapes;	//tilldelningskonstruktorn

	ShapeRegister myRegister3(shapes); //kopieringskonstruktorn

}

