#include "Timber.h"



Timber::Timber(int pricePerMeter, int width, int hight)
{
	this->pricePerMeter = pricePerMeter;
	this->width = width;
	this->hight = hight;
}

Timber::~Timber()
{

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

string Timber::toString()
{
	return to_string(pricePerMeter) + " " + to_string(width) + "x" + to_string(hight);
}
