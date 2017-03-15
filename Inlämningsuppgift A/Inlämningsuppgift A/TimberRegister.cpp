#include "TimberRegister.h"
#include<fstream>



TimberRegister::TimberRegister()
{
	this->capacity = 2;
	this->stockAmount = 0;

	stock = new Timber*[capacity];
	for (int i = 0; i < capacity; i++)
	{
		stock[i] = nullptr;
	}
}


TimberRegister::~TimberRegister()
{
	for (int i = 0; i < this->stockAmount; i++)
		delete this->stock[i];

	delete[] stock;
}

bool TimberRegister::addToStock(int amountM, int pricePerMeter, int width, int hight)
{
	bool exists = false;
	if (stockAmount == capacity)
	{
		this->expand();
	}
	Timber temp(amountM, pricePerMeter, width, hight);
	for (int i = 0; i < stockAmount; i++)
	{
		if (temp == *stock[i])
		{
			exists = true;
		}
	}
	if (!exists)
	{
		stock[stockAmount++] = new Timber(amountM, pricePerMeter, width, hight);
	}

	return !exists;
}

bool TimberRegister::removeFromStock(int amountM, int pricePerMeter, int width, int hight)
{
	bool exists = false;
	Timber temp(amountM, pricePerMeter, width, hight);
	for (int i = 0; i < stockAmount && stockAmount != 1; i++)
	{
		if (temp == *stock[i])
		{
			if (i == (stockAmount - 1))
			{
				stock[i] = new Timber();

			}
			else
			{
				stock[i] = stock[stockAmount - 1];
				stock[stockAmount - 1] = new Timber();
			}

			exists = true;
			stockAmount--;
		}

	}
	if (stockAmount == 1 && temp == *stock[0])
	{
		stock[0] = new Timber();
		stockAmount--;
		exists = true;
	}

	return !exists;
}

bool TimberRegister::changeStock(int amountM, int pricePerMeter, int width, int hight, int amoN, int priN, int choicechoice)
{
	bool exists = false;
	Timber temp(amountM, pricePerMeter, width, hight);
	for (int i = 0; i < stockAmount; i++)
	{
		if (temp == *stock[i])
		{
			if (choicechoice == 1)
			{
				Timber temptemp(amoN, pricePerMeter, width, hight);
				*stock[i] -= temptemp;
			}
			else if (choicechoice == 2)
			{
				Timber temptemp(amountM, priN, width, hight);
				*stock[i] = temptemp;
			}
			else if (choicechoice == 3)
			{
				Timber temptemp(amoN, priN, width, hight);
				*stock[i] -= temptemp;
			}
			exists = true;
		}
		else
		{
			exists = false;
		}
	}

	return !exists;

}

void TimberRegister::expand()
{
	this->capacity *= 2;

	Timber ** newArr = new Timber*[this->capacity];

	for (int i = 0; i < this->capacity; i++)
	{
		if (i < this->stockAmount)
			newArr[i] = this->stock[i];
		else
			newArr[i] = nullptr;
	}

	delete[]this->stock;
	this->stock = newArr;
}

void TimberRegister::showSpecificStock(int amount)
{
		Timber temp(amount, 0, 0, 0);
		for (int i = 0; i < stockAmount; i++)
		{
			if (temp < *stock[i])
			{
				cout << stock[i]->toString() << endl;
			}
		}
}

void TimberRegister::showStock()
{
	for (int i = 0; i < stockAmount; i++)
	{
		cout << stock[i]->toString() << endl << endl;
	}
}

void TimberRegister::showStockValue()
{
	int totValue = 0;
	for (int i = 0; i < stockAmount; i++)
	{
		totValue += stock[i]->value();
	}
	cout << totValue << endl;
}

void TimberRegister::readFromFile(string fileName)
{
	ifstream in;
	in.open(fileName);
	int stockAmount = 0;
	in >> stockAmount;
	in.ignore();//TODO stäng dem
}

void TimberRegister::writeToFile(string filename)
{
	ofstream out;
	out.open(filename);

	out << stockAmount << endl;
	for (int i = 0; i < stockAmount; i++)
	{
		out << stock[i]->getAmountM() << endl;
		out << stock[i]->getPricePerMeter() << endl;
		out << stock[i]->getHight() << endl;
		out << stock[i]->getWidth() << endl;
		//TODO stäng dem
	}
}
