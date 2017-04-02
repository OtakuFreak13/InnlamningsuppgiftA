#include"HousingRegisterSystems.h"
#include<iostream>

using namespace std;

void menu(HousingRegister* housing)
{
	int choice = 9;
	bool continueBool = true;
	while (continueBool)
	{
		cout << "Press 1 to add new housing. " << endl <<
			"Press 2 to show all housing. " << endl <<
			"Press 3 to show all housing with rent lower than or equal to input value. " << endl <<
			"Press 4 to show all housing that conform to housing type and roomnumber norms. " << endl <<
			"Press 5 to remove housing by id. " << endl <<
			"Press 6 to change parameters of specific housing by id. " << endl <<
			"Press 7 to save housing to file. " << endl <<
			"Press 8 to read housing from file. " << endl <<
			"Pres 0 to exit program. " << endl;
		
		cin >> choice; cin.ignore();

		switch (choice)
		{
		case 1: 
			addNew1(housing);
			break;
		case 2:
			showAll2(housing);
			break;
		case 3:
			showAllByRent3(housing);
			break;
		case 4:
			showAllByType4(housing);
			break;
		case 5:
			removeById5(housing);
			break;
		case 6:
			changeParametersById6(housing);
			break;
		case 7:
			saveToFile7(housing);
			break;
		case 8:
			readFromFile8(housing);
			break;
		case 0:
			cout << "Exiting program. Have a nice day!... " << endl;
			continueBool = false;
			break;
		default:
			cout << "Error wrong input. Please try again..." << endl;
			break;
		}
	}

}

void addNew1(HousingRegister* housing)
{
	cout << "Please input id. " << endl;
	int id;
	cin >> id; cin.ignore();

	cout << "Please input adress. " << endl;
	string adress;
	//cin >> adress; cin.ignore();
	getline(cin, adress);

	cout << "Please input rent. " << endl;
	int rent;
	cin >> rent; cin.ignore();

	cout << "Please input housetype. " << endl;
	string houseType;
	//cin >> houseType; cin.ignore();
	getline(cin, houseType);

	cout << "Please input living space. " << endl;
	int livingSpace;
	cin >> livingSpace; cin.ignore();

	cout << "Please input amount of rooms. " << endl;
	int rooms;
	cin >> rooms; cin.ignore();

	if (!housing->addHousing(id, adress, rent, houseType, livingSpace, rooms))
	{
		cout << "Error! Housing with that Id already exist!" << endl;
	}
}

void showAll2(HousingRegister* housing)
{
	//cout<< housing->toStringSpecific() << endl;
	string *strArr = new string[housing->getElementsInArr()];
	housing->toStringSpecific(strArr);
	for (int i = 0; i < housing->getElementsInArr(); i++)
	{
		cout << strArr[i] << endl;
	}
	delete[] strArr;
}

void showAllByRent3(HousingRegister* housing)
{
	cout << "Please input maximum rent. ";
	int maxRent;
	cin >> maxRent; cin.ignore();
	// << housing->showHouseByRent(maxRent) << endl;
	string *strArr = new string[housing->getElementsInArr()];
	housing->showHouseByRent(maxRent, strArr);
	for (int i = 0; i < housing->getElementsInArr(); i++)
	{
		cout << strArr[i] << endl;
	}
	delete[] strArr;
}

void showAllByType4(HousingRegister* housing)
{
	cout << "Please input housing type. ";
	string housingType;
	cin >> housingType; cin.ignore();
	cout << "Please input number of rooms. ";
	int nrRooms;
	cin >> nrRooms; cin.ignore();
	//cout << housing->showSpecificHousing(housingType, nrRooms) << endl;
	string *strArr = new string[housing->getElementsInArr()];
	housing->showSpecificHousing(housingType, nrRooms, strArr);
	for (int i = 0; i < housing->getElementsInArr(); i++)
	{
		cout << strArr[i] << endl;
	}
	delete[] strArr;
}

void removeById5(HousingRegister* housing)
{
	cout << "Please input the id of the house you want to remove. ";
	int id;
	cin >> id; cin.ignore();
	housing->removeHousing(id);
}

void changeParametersById6(HousingRegister* housing)
{
	cout << "Please input the id of the house you want to change. ";
	int id;
	cin >> id; cin.ignore();
	if (!housing->checkId(id))
	{
		cout << "Error id not found! " << endl;
	}
	else
	{
		cout << "Please input the new id. ";
		int newId;
		cin >> newId; cin.ignore();
		if (id!=newId && housing->checkId(newId))
		{
			cout << "Error the new Id already exist! Please try again..." << endl;
			changeParametersById6(housing);
		}
		else
		{
			cout << "Please input the new adress. ";
			string newAdress = "Error";
			getline(cin, newAdress);
			cout << "Please input the new rent. ";
			int newRent = -1;
			cin >> newRent; cin.ignore();
			cout << "Please input the new house type. ";
			string newHouseType = "Error";
			getline(cin, newHouseType);
			cout << "Please input the new living space. ";
			int newLivingSpace = -1;
			cin >> newLivingSpace; cin.ignore();
			cout << "Please input the new amout of rooms. ";
			int newRooms = -1;
			cin >> newRooms; cin.ignore();
			housing->changeHousingParameters(id, newId, newAdress, newRent, newHouseType, newLivingSpace, newRooms);
		}
	}
}

void saveToFile7(HousingRegister* housing)
{
	string filename;
	cout << "Please input filename ending with .txt... ";
	cin >> filename;
	housing->writeToFile(filename);
}

void readFromFile8(HousingRegister* housing)
{
	string filename;
	cout << "Please input filename ending with .txt... ";
	cin >> filename;
	if (housing->readFromFile(filename) == "Error")
	{
		cout << "Error! Couldn't read file..." << endl;
	}
	else
	{
		cout << housing->readFromFile(filename) << endl << endl;
	}
}
