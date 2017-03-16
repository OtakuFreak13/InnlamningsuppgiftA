#include "ShapeRegisterSystem.h"



void menu(ShapeRegister *shapes)
{

	int qont = 1;
	while (qont == 1)
	{

		int choice = 9;
		cout << "Welcome to ShapeList! Please choose one of the following options:"
			<< endl << "Press 1 to add a cone."
			<< endl << "Press 2 to add a box"
			<< endl << "Press 3 to show all shapes"
			<< endl << "Press 4 to show all cones."
			<< endl << "Press 5 to show all boxes"
			<< endl << "Press 6 to remove a specific shape."
			<< endl << "Press 7 to edit a cone."
			<< endl << "Press 8 to edit a box."
			<< endl << "Press 0 to exit program." << endl;
		cin >> choice; cin.ignore();
		switch (choice)
		{
		case 1:
			one(shapes);
			break;

		case 2:
			two(shapes);
			break;

		case 3:
			three(shapes);
			break;

		case 4:
			four(shapes);
			break;

		case 5:
			five(shapes);
			break;

		case 6:

			six(shapes);
			break;

		case 7:
			seven(shapes);
			break;

		case 8:
			eight(shapes);
			break;

		case 0:

			qont = 0;
			break;

		default:
			cout << "Error! Wrong input please try again..." << endl;
			break;
		}
	}
}


void one(ShapeRegister *shapes)
{
	float cHight;
	float cRadius;
	cout << "Please input height of the cone... ";
	cin >> cHight; cin.ignore();
	cout << "Please input radius of the cone... ";
	cin >> cRadius; cin.ignore();
	shapes->addCone(cHight, cRadius);
}

void two(ShapeRegister *shapes)
{
	float bHight;
	float bWidth;
	float bLength;
	cout << "Please input height of the box... ";
	cin >> bHight; cin.ignore();
	cout << "Please input width of the box... ";
	cin >> bWidth; cin.ignore();
	cout << "Please input length of the box... ";
	cin >> bLength; cin.ignore();
	shapes->addBox(bHight, bWidth, bLength);
}

void three(ShapeRegister *shapes)
{
	int arrCap = shapes->nrOfShapes();
	string *list = new string[arrCap];
	shapes->getAllShapesAsStrings(list, arrCap);

	for (int i = 0; i < arrCap; i++)
	{
		cout << list[i] << endl; 
	}
	delete[] list;
}

void four(ShapeRegister *shapes)
{
	int arrCap = shapes->nrOfShapes();
	string *list = new string[arrCap];
	shapes->getAllConesAsStrings(list, arrCap);

	for (int i = 0; i < arrCap; i++)
	{
		cout << list[i] << endl; 
	}
	delete[] list;
}

void five(ShapeRegister *shapes)
{
	int arrCap = shapes->nrOfShapes();
	string *list = new string[arrCap];
	shapes->getAllBoxesAsStrings(list, arrCap);

	for (int i = 0; i < arrCap; i++)
	{
		cout << list[i] << endl;
	}
	delete[] list;
}

void six(ShapeRegister *shapes)
{
	float bHight;
	cout << "Please input height of the shape you want to remove... ";
	cin >> bHight; cin.ignore();
	shapes->removeShape(bHight);
}

void seven(ShapeRegister *shapes)
{
	float cHight;
	float cRadius;
	float cNewHight;
	cout << "Please input height of the cone you want to edit... ";
	cin >> cHight; cin.ignore();
	cout << "Please input new radius of the cone you want to edit... ";
	cin >> cRadius; cin.ignore();
	cout << "Please input new height of the cone you want to edit... ";
	cin >> cNewHight; cin.ignore();
	shapes->editACone(cHight, cRadius, cNewHight);
}

void eight(ShapeRegister *shapes)
{
	float bHight;
	float bWidth;
	float bLength;
	float bNewHight;
	cout << "Please input height of the box you want to edit... ";
	cin >> bHight; cin.ignore();
	cout << "Please input new width of the box you want to edit... ";
	cin >> bWidth; cin.ignore();
	cout << "Please input new length of the box you want to edit... ";
	cin >> bLength; cin.ignore();
	cout << "Please input new height of the box you want to edit... ";
	cin >> bNewHight; cin.ignore();
	shapes->editABox(bHight, bWidth, bLength, bNewHight);
}
