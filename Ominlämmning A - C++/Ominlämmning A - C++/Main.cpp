#include"Test.h"


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	setlocale(0, "swedish");

	test();
	system("pause");


	return 0;
}