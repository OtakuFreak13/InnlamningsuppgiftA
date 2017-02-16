//menu
#include"TimberRegisterSystem.h"

void menu(TimberRegister *stock)
{
	int qont = 1;
	while (qont == 1)
	{

		int choice = 9;
		cout << "Welcome to TimberStocks! Please choose one of the following options:"
			<< endl << "Press 1 to add a timber to stock."
			<< endl << "Press 2 to remove a specific timber."
			<< endl << "Press 3 to show all timber in stock."
			<< endl << "Press 4 to choose to show all timber with less than a certain amount available."
			<< endl << "Press 5 to show total value of stock."
			<< endl << "Press 6 to change a specific timbers amount and or price."
			<< endl << "Press 7 to read a stock list from a .txt file."
			<< endl << "Press 8 to save stock as a .txt file."
			<< endl << "Press 0 to exit program." << endl;
		cin >> choice; cin.ignore();
		switch (choice)
		{
		case 1:
			one(stock);
			break;

		case 2:
			two(stock);
			break;

		case 3:
			stock->showStock();
			break;

		case 4:
			//int choicechoice = 0;
			//cout << "If you want to specifi the price per meter press 1." << endl
			//	<< "Or if you want to specifi the width press 2." << endl
			//	<< "Or if you want to specifi the hight press 3." << endl;
			//cin >> choicechoice; cin.ignore();
			//switch (choicechoice)
			//{
			//case 1:
			//	cout << "Please input price per meter... ";
			//	cin >> pri; cin.ignore();
			//	wid = 0;
			//	hig = 0;
			//	stock.showSpecificStock(0, pri, wid, hig);
			//	break;
			//case 2:
			//	cout << endl << "please input width... ";
			//	cin >> wid; cin.ignore();
			//	pri = 0;
			//	hig = 0;
			//	stock.showSpecificStock(0, pri, wid, hig);
			//	break;
			//case 3:
			//	cout << endl << "Please input hight... ";
			//	cin >> hig; cin.ignore();
			//	pri = 0;
			//	wid = 0;
			//	stock.showSpecificStock(0, pri, wid, hig);
			//	break;

			//default:
			//	cout << "Non of the choices choosen." << endl;
			//	break;
			//}
			four(stock);
			break;

		case 5:
			stock->showStockValue();
			break;

		case 6:
			//cout << "Please input price per meter... ";
			//cin >> pri; cin.ignore();
			//cout << endl << "please input width... ";
			//cin >> wid; cin.ignore();
			//cout << endl << "Please input hight... ";
			//cin >> hig; cin.ignore();
			//cout << endl;
			//stock.changeStock(0, pri, wid, hig);
			six(stock);
			break;

		case 7:
			seven(stock);
			break;

		case 8:	
			eight(stock);
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

void one(TimberRegister *stock)
{
	int amount;
	int pri;
	int wid;
	int hig;
	cout << endl << "Please input available amount of meters... ";
	cin >> amount; cin.ignore();
	cout << "Please input price per meter... ";
	cin >> pri; cin.ignore();
	cout << endl << "please input width... ";
	cin >> wid; cin.ignore();
	cout << endl << "Please input hight... ";
	cin >> hig; cin.ignore();

	cout << endl;
	stock->addToStock(amount, pri, wid, hig);
}
void two(TimberRegister *stock)
{
	int amount;
	int pri;
	int wid;
	int hig;
	cout << "Please input price per meter... ";
	cin >> pri; cin.ignore();
	cout << endl << "please input width... ";
	cin >> wid; cin.ignore();
	cout << endl << "Please input hight... ";
	cin >> hig; cin.ignore();
	cout << endl;
	stock->removeFromStock(0, pri, wid, hig);
}

void four(TimberRegister *stock)
{
	int amo;
	cout << "Please input an amount... ";
	cin >> amo; cin.ignore();
	
	stock->showSpecificStock(amo);
}

void six(TimberRegister *stock)
{
	int amo;
	int pri;
	int wid;
	int hig;
	int amoN;
	int priN;

	cout << "Please input price per meter of existing timber... ";
	cin >> pri; cin.ignore();
	cout << endl << "please input width of existing timber... ";
	cin >> wid; cin.ignore();
	cout << endl << "Please input hight of existing timber... ";
	cin >> hig; cin.ignore();
	cout << endl;
	int choicechoice = -1;
	cout << "If you want to change just the amount press 1." << endl
		<< "To change just the price per meter press 2." << endl
		<< "Or press 3 to change both.";
	cin >> choicechoice;
	switch (choicechoice)
	{

	case 1:
		cout << endl << "Please input new amount... ";
		cin >> amoN; cin.ignore();
		cout << endl;
		stock->changeStock(amoN, pri, wid, hig, amoN, priN, choicechoice);
		break;

	case 2:
		cout << "Please input a new price per meter... ";
		cin >> priN; cin.ignore();
		cout << endl;
		stock->changeStock(amo, pri, wid, hig, amoN, priN, choicechoice);
		break;

	case 3:
		cout << endl << "Please input new amount... ";
		cin >> amoN; cin.ignore();
		cout << "Please input a new price per meter... ";
		cin >> priN; cin.ignore();
		cout << endl;
		stock->changeStock(amoN, pri, wid, hig, amoN, priN, choicechoice);
		break;

	default:
		cout << "Non of the choices choosen." << endl;
		break;
	}


}

void seven(TimberRegister *stock)
{
	string filename;
	cout << "Please input filename ending with .txt... ";
	cin >> filename;
	stock->readFromFile(filename);
}

void eight(TimberRegister *stock)
{
	string filename;
	cout << "Please input filename ending with .txt... ";
	cin >> filename;
	stock->writeToFile(filename);
}
