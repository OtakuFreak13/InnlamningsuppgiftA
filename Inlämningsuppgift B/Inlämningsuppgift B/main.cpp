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



	ShapeRegister shapes;

	//Cone cone(1, 2);
	//Cone cone2 = Cone(3,4);
	////Cone cone3 = cone2; <- FEL
	//cone = cone2;
	//
	//cout << cone.toString() << endl; //<<skicka till test filen

	test2();
	//menu(&shapes);

	getchar();
	return 0;
}