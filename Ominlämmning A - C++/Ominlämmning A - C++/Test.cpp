#include"Test.h"

#include<iostream>

void test()
{
	cout << "Skapar en array med cap 2 och lägger till två element. Sen skrivs de ut." << endl;
	HousingRegister* housing = new HousingRegister(2);
	housing->addHousing(111, "Tranbärsgatan 55, Hovdala", 4500, "House", 120, 5);
	housing->addHousing(222, "Mortenstorget 33A, Lund", 8700, "Apartment", 100, 4);
	cout << housing->toStringSpecific() << endl;

	cout << "Addar en till för att testa expand()" << endl;
	housing->addHousing(333, "Ostindiefarargatan 10, Malmö", 5600, "Apartment", 75, 3);
	cout << housing->toStringSpecific() << endl;

	cout << "Testar att ta bort något som inte finns" << endl;
	housing->removeHousing(444);
	cout << housing->toStringSpecific() << endl;

	cout << "Testar att ta bort något som finns " << endl;
	housing->removeHousing(222);
	cout << housing->toStringSpecific() << endl;

	cout << "Tar bort de två kvarvarande bostäderna. Bör inte skriva ut något" << endl;
	housing->removeHousing(111);
	housing->removeHousing(333);
	cout << housing->toStringSpecific() << endl;

	cout << "Lägger till 2 nya emelent och skriver ut" << endl;
	housing->addHousing(444, "Krisebergsgata 27, Malmö", 4000, "House", 70, 2);
	housing->addHousing(555, "Lärkvägen 9, Sösdala", 4300, "House", 120, 6);
	cout << housing->toStringSpecific() << endl;

	cout << "Testar kopieringskonstruktorn. Bör skriva ut samma som ovan: " << endl;
	HousingRegister* housing2 = new HousingRegister(*housing);
	cout << housing2->toStringSpecific() << endl;

	cout << "Testar tilldelnings operatorn. Bör skriva ut samma som ovan: " << endl;
	HousingRegister *housing3 = new HousingRegister(1);
	*housing3 = *housing;
	cout << housing3->toStringSpecific() << endl;

	delete housing;
	//delete housing2;
	delete housing3;
}