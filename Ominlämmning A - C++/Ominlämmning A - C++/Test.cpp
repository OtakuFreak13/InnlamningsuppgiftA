#include"Test.h"

#include<iostream>

void test()
{
	
	cout << "Skapar en array med cap 2 och l�gger till tv� element. Sen skrivs de ut." << endl;
	HousingRegister* housing = new HousingRegister(2);
	
	housing->addHousing(111, "Tranb�rsgatan 55, Hovdala", 4500, "House", 120, 5);
	housing->addHousing(222, "Mortenstorget 33A, Lund", 8700, "Apartment", 100, 4);
	//cout << housing->toStringSpecific() << endl;
	string *strArr = new string[housing->getElementsInArr()];
	housing->toStringSpecific(strArr);
	for (int i = 0; i < housing->getElementsInArr(); i++)
	{
		cout << strArr[i] << endl;
	}
	
	cout << "Addar en till f�r att testa expand()" << endl;
	housing->addHousing(333, "Ostindiefarargatan 10, Malm�", 5600, "Apartment", 75, 3);
	string *strArr2 = new string[housing->getElementsInArr()];
	housing->toStringSpecific(strArr2);
	for (int i = 0; i < housing->getElementsInArr(); i++)
	{
		cout << strArr2[i] << endl;
	}
	
	cout << "Testar att ta bort n�got som inte finns" << endl;
	housing->removeHousing(444);
	string *strArr3 = new string[housing->getElementsInArr()];
	housing->toStringSpecific(strArr3);
	for (int i = 0; i < housing->getElementsInArr(); i++)
	{
		cout << strArr3[i] << endl;
	}
	
	cout << "Testar att ta bort n�got som finns " << endl;
	housing->removeHousing(222);
	string *strArr4 = new string[housing->getElementsInArr()];
	housing->toStringSpecific(strArr4);
	for (int i = 0; i < housing->getElementsInArr(); i++)
	{
		cout << strArr4[i] << endl;
	}

	cout << "Tar bort de tv� kvarvarande bost�derna. B�r inte skriva ut n�got" << endl;
	housing->removeHousing(111);
	housing->removeHousing(333);
	string *strArr5 = new string[housing->getElementsInArr()];
	housing->toStringSpecific(strArr5);
	for (int i = 0; i < housing->getElementsInArr(); i++)
	{
		cout << strArr5[i] << endl;
	}

	cout << "L�gger till 2 nya emelent och skriver ut" << endl;
	housing->addHousing(444, "Krisebergsgata 27, Malm�", 4000, "House", 70, 2);
	housing->addHousing(555, "L�rkv�gen 9, S�sdala", 4300, "House", 120, 6);
	string *strArr6 = new string[housing->getElementsInArr()];
	housing->toStringSpecific(strArr6);
	for (int i = 0; i < housing->getElementsInArr(); i++)
	{
		cout << strArr6[i] << endl;
	}
	
	cout << "Testar kopieringskonstruktorn. B�r skriva ut samma som ovan: " << endl;
	HousingRegister* housing2 = new HousingRegister(*housing);
	string *strArr7 = new string[housing->getElementsInArr()];
	housing->toStringSpecific(strArr7);
	for (int i = 0; i < housing->getElementsInArr(); i++)
	{
		cout << strArr7[i] << endl;
	}

	cout << "Testar tilldelnings operatorn. B�r skriva ut samma som ovan: " << endl;
	HousingRegister *housing3 = new HousingRegister(1);
	*housing3 = *housing;
	string *strArr8 = new string[housing->getElementsInArr()];
	housing->toStringSpecific(strArr8);
	for (int i = 0; i < housing->getElementsInArr(); i++)
	{
		cout << strArr8[i] << endl;
	}

	delete housing;
	delete housing2;
	delete housing3;
	delete[] strArr;
	delete[] strArr2;
	delete[] strArr3;
	delete[] strArr4;
	delete[] strArr5;
	delete[] strArr6;
	delete[] strArr7;
	delete[] strArr8;
}