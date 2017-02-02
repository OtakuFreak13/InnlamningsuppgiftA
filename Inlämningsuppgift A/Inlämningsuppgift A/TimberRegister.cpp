#include "TimberRegister.h"



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

}

bool TimberRegister::addToStock(int pricePerMeter, int width, int hight)
{
	bool exists = false;
	if (this->stockAmount == capacity) 
	{
		this->expand();
	}
	Timber temp(pricePerMeter, width, hight);
	for (int i = 0; i < stockAmount; i++)
	{
		if (temp == *stock[i]) //GÖr operator för == BLAH!!
		{
			exists = true;
		}
		if (!exists)
		{
			Timber[stockAmount++] = new Timber(pricePerMeter, width, hight);
		}
	}
	return !exists;
}

void TimberRegister::expand()
{
	this->capacity *= 2;

}

void TimberRegister::showStock()
{

}

void TimberRegister::readFile()
{

}

void TimberRegister::writeToFile()
{

}
