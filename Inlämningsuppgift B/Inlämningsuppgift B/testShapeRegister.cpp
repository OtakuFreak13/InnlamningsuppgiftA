#include<iostream>
#include"Box.h"
#include"Cone.h"
#include"Shape.h"
#include"ShapeRegister.h"

void test2()
{

	cout << "Test 1: Skapa 2 shapes, cone och box" << endl;

	ShapeRegister *shapes = new ShapeRegister(2);
	shapes->addCone(5, 2.5);
	shapes->addBox(4, 3, 6);

	int arrCap = 2;
	string *list1 = new string[arrCap];
	shapes->getAllShapesAsStrings(list1, arrCap);
	for (int i = 0; i < arrCap; i++) 
	{
		cout << list1[i] << endl;
	}
	delete[] list1;

	cout << "Test 2: L�gger till en till box f�r att testa expand" << endl;
	shapes->addBox(1, 2, 7);	
	arrCap = 3;	
	string *list2 = new string[arrCap];
	shapes->getAllShapesAsStrings(list2, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list2[i] << endl;
	}
	delete[] list2;
	cout << "Test 3: testar att ta bort ett element som inte finns" << endl;
	shapes->removeShape(19);
	string *list3 = new string[arrCap];
	shapes->getAllShapesAsStrings(list3, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list3[i] << endl;
	}
	delete[] list3;
	cout << "Test 4: tar bort ett element som finns" << endl;
	shapes->removeShape(1);
	string *list4 = new string[arrCap];
	shapes->getAllShapesAsStrings(list4, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list4[i] << endl;
	}
	delete[] list4;
	cout << "Test 5: tar bort tv� till s� det ska vara tomt" << endl;
	shapes->removeShape(5);
	shapes->removeShape(4);
	string *list5 = new string[arrCap];
	shapes->getAllShapesAsStrings(list5, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list5[i] << endl;
	}
	delete[] list5;
	cout << "Test 6: L�gger till en cone och box igen" << endl;
	shapes->addBox(6, 6, 6);
	shapes->addCone(8, 6);
	string *list6 = new string[arrCap];
	shapes->getAllShapesAsStrings(list6, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list6[i] << endl;
	}
	delete[] list6;
	cout << "Test 7: redigering av cone och box" << endl;
	shapes->editABox(6, 1, 1, 1);//de h�r tv� editar och ska visas
	shapes->editACone(8, 5, 5);
	shapes->editABox(5, 3, 3, 3);//f�rs�ker edita en box height som finns men till h�r en cone 
	shapes->editACone(5, 1, 1);//f�rs�ker edita en cone och s�tta height till n�tt som �r upptaget
	string *list7 = new string[arrCap];
	shapes->getAllShapesAsStrings(list7, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list7[i] << endl;
	}
	delete[] list7;

	cout << "Test 8: testar tildelnings operatorn =" << endl;
	ShapeRegister *shapes2 = new ShapeRegister();
	shapes2 = shapes;

	string *list8 = new string[arrCap];
	shapes2->getAllShapesAsStrings(list8, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list8[i] << endl;//om det visar samma som 7:an �r det r�tt
	}
	delete[] list8;

	cout << "Test 8: testar kopierings konstruktorn" << endl;
	ShapeRegister *shapes3(shapes);
	string *list9 = new string[arrCap];
	shapes3->getAllShapesAsStrings(list9, 3);
	for (int i = 0; i < arrCap; i++)
	{
		cout << list9[i] << endl;//b�r allts� visa samma som f�reg�ende
	}
	delete[] list9;

	delete shapes;
	delete shapes2;
	delete shapes3;
}

void test() {

	//Testning:
	//1. Skapa ett objekt av typen ShapeRegister(l�t startkapaciteten vara 2).
	ShapeRegister *myRegister = new ShapeRegister(2);

	//2. L�gg in 2 olika Shapes.
	//Skriv ut de str�ngar som erh�lls i arrayen som medlemsfunktionen f�r ShapeRegister-objektet fyller i.	
	cout << endl << "Test 1: " << endl;

	myRegister->addBox(10, 10, 10);
	myRegister->addCone(11, 11);

	int arrCap = 2;
	string *arr = new string[arrCap];

	myRegister->getAllShapesAsStrings(arr, arrCap);

	for (int i = 0; i < arrCap; i++) {
		cout << "Element nr " << to_string(i) << ": " << arr[i] << endl;

	}
	delete[] arr;

	//3. L�gg till ytterligare tv� shapes(vilket ska medf�ra att arrayen i ShapeRegister - objektet expanderar).
	//Skriv ut de str�ngar som erh�lls i arrayen som medlemsfunktionen f�r ShapeRegister - objektet fyller i.
	cout << endl << "Test 2: " << endl;
	myRegister->addBox(12, 12, 12);
	myRegister->addCone(13, 11);

	arrCap = 4;
	arr = new string[arrCap];

	myRegister->getAllShapesAsStrings(arr, arrCap);

	for (int i = 0; i < arrCap; i++) {
		cout << "Element nr " << to_string(i) << ": " << arr[i] << endl;

	}
	delete[] arr;

	//4. F�rs�k ta bort ett virke som inte finns inlagt och kontrollera att ingen borttagning gjordes samt
	//generera en utskrift av detta.
	cout << endl << "Test 3: Ska visa samma som Test 2 om allt �r r�tt.. " << endl;

	myRegister->removeShape(14);


	arrCap = 4;
	arr = new string[arrCap];

	myRegister->getAllShapesAsStrings(arr, arrCap);

	for (int i = 0; i < arrCap; i++) {
		cout << "Element nr " << to_string(i) << ": " << arr[i] << endl;

	}
	delete[] arr;

	//5. Ta bort ett virke som finns inlagt och kontrollera att borttagningen genomf�rts.
	cout << endl << "Test 4: tar bort shapen med l�ngden 13..." << endl;

	myRegister->removeShape(13);


	arrCap = 3; //efter Remove s� borde vi bara ha 3 kvar, inte fyra som tidigare 
				// om vi matar in 4 s� kommer vi ist�llet f� ett error... (som tar oss till else satsen i "if(status)" satsen senare...
	arr = new string[arrCap];

	bool status = myRegister->getAllShapesAsStrings(arr, arrCap);

	//vi kollade om vi kunde h�mta ut antalet baserat p� v�r arr och arrCap, tyv�rr gick inte det 
	if (status) {
		for (int i = 0; i < arrCap; i++) {
			cout << "Element nr " << to_string(i) << ": " << arr[i] << endl; // kommer printa ut tomt... 

		}
	}
	else {
		cout << "ERROR; 'myRegister->getAllShapesAsStrings(arr, arrCap)' returnerade: " << to_string(status) << "(allts� false)" << endl;
	}


	delete[] arr;
	//6. Tag bort de resterande 3 virkena fr�n TimberRegister - objektet och kontrollera att det d�refter inte
	//inneh�ller n�gra virken.

	cout << endl << "Test 5: ta bort de restrerande shape... (kommer bara visa en tom lista...)" << endl;

	myRegister->removeShape(10);
	myRegister->removeShape(11);
	myRegister->removeShape(12);


	arrCap = myRegister->nrOfShapes(); //efter Remove s� borde vi bara ha 3 kvar, inte fyra som tidigare 
									   // om vi matar in 4 s� kommer vi ist�llet f� ett error... (som tar oss till else satsen i "if(status)" satsen senare...
	arr = new string[arrCap];

	status = myRegister->getAllShapesAsStrings(arr, arrCap);

	//vi kollade om vi kunde h�mta ut antalet baserat p� v�r arr och arrCap, tyv�rr gick inte det 
	if (status) {
		for (int i = 0; i < arrCap; i++) {
			cout << "Element nr " << to_string(i) << ": " << arr[i] << endl; // kommer printa ut tomt... 

		}
	}
	else {
		cout << "ERROR; 'myRegister->getAllShapesAsStrings(arr, arrCap)' returnerade: " << to_string(status) << "(allts� false)" << endl;
	}


	delete[] arr;

	//7. L�gg till 2 nya virken till TimberRegister - objektet och kontrollera att dessa finns inlagda.

	cout << endl << "Test 6: l�gg till 2 shapes igen..." << endl;

	myRegister->addBox(44, 44, 44);
	myRegister->addCone(55, 50);

	arrCap = myRegister->nrOfShapes(); //efter Remove s� borde vi bara ha 3 kvar, inte fyra som tidigare 
									   // om vi matar in 4 s� kommer vi ist�llet f� ett error... (som tar oss till else satsen i "if(status)" satsen senare...
	arr = new string[arrCap];

	status = myRegister->getAllShapesAsStrings(arr, arrCap);

	//vi kollade om vi kunde h�mta ut antalet baserat p� v�r arr och arrCap, tyv�rr gick inte det 
	if (status) {
		for (int i = 0; i < arrCap; i++) {
			cout << "Element nr " << to_string(i) << ": " << arr[i] << endl; // kommer printa ut tomt... 
		}
	}
	else {
		cout << "ERROR; 'myRegister->getAllShapesAsStrings(arr, arrCap)' returnerade: " << to_string(status) << "(allts� false)" << endl;
	}

	delete[] arr;

	//8. testa om redigeringen fungerar
	cout << endl << "Test 7: Redigera en shape..." << endl;

	myRegister->editABox(44, 22, 22, 75);
	myRegister->editACone(55, 25, 66);

	arrCap = myRegister->nrOfShapes(); //efter Remove s� borde vi bara ha 3 kvar, inte fyra som tidigare 
									   // om vi matar in 4 s� kommer vi ist�llet f� ett error... (som tar oss till else satsen i "if(status)" satsen senare...
	arr = new string[arrCap];

	status = myRegister->getAllShapesAsStrings(arr, arrCap);

	//vi kollade om vi kunde h�mta ut antalet baserat p� v�r arr och arrCap, tyv�rr gick inte det 
	if (status) {
		for (int i = 0; i < arrCap; i++) {
			cout << "Element nr " << to_string(i) << ": " << arr[i] << endl; // kommer printa ut tomt... 
		}
	}
	else {
		cout << "ERROR; 'myRegister->getAllShapesAsStrings(arr, arrCap)' returnerade: " << to_string(status) << "(allts� false)" << endl;
	}

	delete[] arr;

	//9. testa att redigera en 
	cout << endl << "Test 8: Redigera en box f�r h�jden av en cone... om det fungerar �r det samma som test 7." << endl;

	myRegister->editABox(55, 22, 22, 80);	//DET finns ingen box med h�jden 55
	myRegister->editACone(44, 25, 91);		// finns ingen box med h�jden av 44

	arrCap = myRegister->nrOfShapes(); //efter Remove s� borde vi bara ha 3 kvar, inte fyra som tidigare 
									   // om vi matar in 4 s� kommer vi ist�llet f� ett error... (som tar oss till else satsen i "if(status)" satsen senare...
	arr = new string[arrCap];

	status = myRegister->getAllShapesAsStrings(arr, arrCap);

	//vi kollade om vi kunde h�mta ut antalet baserat p� v�r arr och arrCap, tyv�rr gick inte det 
	if (status) {
		for (int i = 0; i < arrCap; i++) {
			cout << "Element nr " << to_string(i) << ": " << arr[i] << endl; // kommer printa ut tomt... 
		}
	}
	else {
		cout << "ERROR; 'myRegister->getAllShapesAsStrings(arr, arrCap)' returnerade: " << to_string(status) << "(allts� false)" << endl;
	}

	delete[] arr;

	//10. Testa p� l�mpligt s�tt kopieringskonstruktor(copykonstruktor) och tilldelningsoperator.
	//Avsluta programmet och kontrollera slutligen att inga minnesl�ckor uppt�ckts!
	cout << endl << "Test 9: vi matar ut resultatet av myRegister, och myRegister2 och myRegister3 ." << endl << "(test av copyconstruktor och tilldelningsoperatorn)" << endl << "Ska inneh�lla samma data om r�tt..." << endl << "vi l�gger ocks� till 2 nytt objekt p� varje Register" << endl;
	ShapeRegister myRegister2 = ShapeRegister();
	myRegister2 = *myRegister;	//tilldelningskonstruktorn

	ShapeRegister myRegister3(*myRegister); //kopieringskonstruktorn

											////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	myRegister->addCone(66, 50);
	myRegister->addBox(67, 50, 50);

	arrCap = myRegister->nrOfShapes();

	arr = new string[arrCap];

	status = myRegister->getAllShapesAsStrings(arr, arrCap);

	cout << endl << "myRegister" << endl;
	for (int i = 0; i < arrCap; i++) {
		cout << "Element nr " << to_string(i) << ": " << arr[i] << endl; // kommer printa ut tomt... 
	}
	delete[] arr;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	myRegister2.addCone(68, 50);
	myRegister2.addBox(69, 50, 50);
	int arrCap2 = myRegister2.nrOfShapes();

	string *arr2 = new string[arrCap2];

	status = myRegister2.getAllShapesAsStrings(arr2, arrCap2);

	cout << endl << "myRegister2" << endl;
	for (int i = 0; i < arrCap2; i++) {
		cout << "Element nr " << to_string(i) << ": " << arr2[i] << endl; // kommer printa ut tomt... 
	}

	delete[] arr2;

	////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	myRegister3.addCone(70, 50);
	myRegister3.addBox(71, 50, 50);

	int arrCap3 = myRegister3.nrOfShapes();

	string *arr3 = new string[arrCap3];

	status = myRegister3.getAllShapesAsStrings(arr3, arrCap3);

	cout << endl << "myRegister3" << endl;
	for (int i = 0; i < arrCap3; i++) {
		cout << "Element nr " << to_string(i) << ": " << arr3[i] << endl; // kommer printa ut tomt... 
	}

	delete[] arr3;
	delete myRegister;
}