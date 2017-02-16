#include "Timber.h"



Timber::Timber()
{
	amountM = -1;
	pricePerMeter = -1;
	width = -1;
	hight = -1;
}

Timber::Timber(int amountM, int pricePerMeter, int width, int hight)
{
	this->amountM = amountM;
	this->pricePerMeter = pricePerMeter;
	this->width = width;
	this->hight = hight;
}

Timber::~Timber()
{

}

int Timber::getAmountM() const
{
	return amountM;
}

int Timber::getPricePerMeter()const
{
	return pricePerMeter;
}

int Timber::getWidth()const
{
	return width;
}

int Timber::getHight() const
{
	return hight;
}

bool Timber::operator=(const Timber &copy)
{
	return (this->pricePerMeter = copy.pricePerMeter) && (this->width = copy.width) && (this->hight = copy.hight);
}

bool Timber::operator-=(const Timber &copy)
{
	return (this->amountM=copy.amountM) && (this->pricePerMeter = copy.pricePerMeter) && (this->width = copy.width) && (this->hight = copy.hight);
}

bool Timber::operator==(const Timber &copy)
{
	return (this->pricePerMeter == copy.pricePerMeter) && (this->width == copy.width) && (this->hight == copy.hight);
}

bool Timber::operator<=(const Timber &copy)
{
	return (this->width <= copy.width) && (this->hight <= copy.hight);
}

bool Timber::operator<(const Timber &copy)
{
	return (this->amountM > copy.amountM);
}

string Timber::toString()
{
	return to_string(amountM)+"m"+" "+to_string(pricePerMeter)+"kr/m" + " " + to_string(width) + "x" + to_string(hight)+"cm";
}

int Timber::value()
{
	int value = this->amountM * this->pricePerMeter;
	return value;
}
