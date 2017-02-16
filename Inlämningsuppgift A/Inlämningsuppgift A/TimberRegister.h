#ifndef TIMBER_REGISTER_H
#define TIMBER_REGISTER_H

#include<string>
#include"Timber.h"
#include<fstream> //////////
#include<iostream>

using namespace std;



class TimberRegister
{
private:
	Timber **stock;
	int capacity;
	int stockAmount;
	
public:
	TimberRegister();
	~TimberRegister();
	bool addToStock(int amountM, int pricePerMeter, int width, int hight);
	bool removeFromStock(int amountM, int pricePerMeter, int width, int hight);
	bool changeStock(int amountM, int pricePerMeter, int width, int hight, int amoN, int priN, int choicechoice);

	void expand();
	void showSpecificStock(int amount);
	void showStock();
	void showStockValue();
	void readFromFile(string fileName);
	void writeToFile(string filename);
};

#endif // !TIMBER_REGISTER_H