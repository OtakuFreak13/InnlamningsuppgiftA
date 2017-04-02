#include<iostream>
#include"Box.h"
#include"Cone.h"
#include"Shape.h"
#include"ShapeRegister.h"

void test2()
{

	cout << "Test 1: Skapa 2 shapes, cone och box" << endl;

	ShapeRegister *shapes = new ShapeRegister(2);
	shapes->addCone(5, 2.5);
	shapes->addBox(4, 3, 6);

	int arrCap = 2;
	string *list1 = new string[arrCap];
	shapes->getAllShapesAsStrings(list1, arrCap);
	for (int i = 0; i < arrCap; i++) 
	{
		cout << list1[i] << endl;
	}
	delete[] list1;

	cout << "Test 2: Lägger till en till box för att testa expand" << endl;
	shapes->addBox(1, 2, 7);	
	arrCap = 3;	
	string *list2 = new string[arrCap];
	shapes->getAllShapesAsStrings(list2, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list2[i] << endl;
	}
	delete[] list2;
	cout << "Test 3: testar att ta bort ett element som inte finns" << endl;
	shapes->removeShape(19);
	string *list3 = new string[arrCap];
	shapes->getAllShapesAsStrings(list3, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list3[i] << endl;
	}
	delete[] list3;
	cout << "Test 4: tar bort ett element som finns" << endl;
	shapes->removeShape(1);
	string *list4 = new string[arrCap];
	shapes->getAllShapesAsStrings(list4, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list4[i] << endl;
	}
	delete[] list4;
	cout << "Test 5: tar bort två till så det ska vara tomt" << endl;
	shapes->removeShape(5);
	shapes->removeShape(4);
	string *list5 = new string[arrCap];
	shapes->getAllShapesAsStrings(list5, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list5[i] << endl;
	}
	delete[] list5;
	cout << "Test 6: Lägger till en cone och box igen" << endl;
	shapes->addBox(6, 6, 6);
	shapes->addCone(8, 6);
	string *list6 = new string[arrCap];
	shapes->getAllShapesAsStrings(list6, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list6[i] << endl;
	}
	delete[] list6;
	cout << "Test 7: redigering av cone och box" << endl;
	shapes->editABox(6, 1, 1, 1);//de här två editar och ska visas
	shapes->editACone(8, 5, 5);
	shapes->editABox(5, 3, 3, 3);//försöker edita en box height som finns men till hör en cone 
	shapes->editACone(5, 1, 1);//försöker edita en cone och sätta height till nått som är upptaget
	string *list7 = new string[arrCap];
	shapes->getAllShapesAsStrings(list7, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list7[i] << endl;
	}
	delete[] list7;

	cout << "Test 8: testar tildelnings operatorn =" << endl;
	ShapeRegister *shapes2 = new ShapeRegister();
	*shapes2 = *shapes;

	string *list8 = new string[arrCap];
	shapes2->getAllShapesAsStrings(list8, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list8[i] << endl;//om det visar samma som 7:an är det rätt
	}
	delete[] list8;

	cout << "Test 9: testar kopierings konstruktorn" << endl;
	ShapeRegister *shapes3 = new ShapeRegister(*shapes);
	string *list9 = new string[arrCap];
	shapes3->getAllShapesAsStrings(list9, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list9[i] << endl;//bör alltså visa samma som föregående
	}
	delete[] list9;

	delete shapes;
	delete shapes2;
	delete shapes3;
}
