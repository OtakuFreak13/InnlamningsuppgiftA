#include<iostream>
#include"Box.h"
#include"Cone.h"
#include"Shape.h"
#include"ShapeRegister.h"
#include"ShapeRegisterSystem.h"
#include"testShapeRegister.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	locale swedish("swedish");
	locale::global(swedish);
	
	ShapeRegister shapes;

	test2();
	cout << "Test avklarat, tryck enter för att starta program" << endl;
	getchar();
	system("cls");
	menu(&shapes);

	getchar();
	return 0;
}