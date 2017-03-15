#include<iostream>
#include"Box.h"
#include"Cone.h"
#include"Shape.h"
#include"ShapeRegister.h"
#include"ShapeRegisterSystem.h"

using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);



	ShapeRegister shapes;
	menu(&shapes);

	getchar();
	return 0;
}