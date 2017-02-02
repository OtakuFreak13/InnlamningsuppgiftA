#ifndef TIMBER_REGISTER_H
#define TIMBER_REGISTER_H

#include<string>
#include"Timber.h"
#include<fstream> //////////

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
	bool addToStock(int pricePerMeter, int width, int hight);

	void expand();
	void showStock();
	void readFile();
	void writeToFile();
};

#endif // !TIMBER_REGISTER_H