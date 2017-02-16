#include<iostream>
#include<string>
#include"Timber.h"
#include"TimberRegister.h"
#include"TimberRegisterSystem.h"



using namespace std;

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	TimberRegister stock;
	
	//stock.addToStock(500, 78, 45, 35);
	//stock.addToStock(300, 34, 22, 23);
	//stock.addToStock(400, 67, 45, 45);
	//stock.showStock();
	//stock.showStockValue();

	menu(&stock);

	


	getchar();
	return 0;
}