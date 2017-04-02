#include"Test.h"
#include"HousingRegisterSystems.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	setlocale(0, "swedish");

	test();
	system("pause");

	HousingRegister* housing = new HousingRegister(2);
	menu(housing);

	delete housing;
	return 0;
}