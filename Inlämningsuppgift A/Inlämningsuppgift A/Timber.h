#ifndef TIMBER_H
#define TIMBER_H

#include<string>

using namespace std;

class Timber
{
private:
	int amountM;
	int pricePerMeter;
	int width;
	int hight;

public:
	Timber();
	Timber(int amountM, int pricePerMeter, int width, int hight);
	~Timber();
	int getAmountM()const;
	int getPricePerMeter()const;
	int getWidth()const;
	int getHight()const;

	bool operator=(const Timber &copy);
	bool operator==(const Timber &copy);	
	bool operator-=(const Timber &copy);
	bool Timber::operator<=(const Timber &copy);
	bool Timber::operator<(const Timber &copy);

	string toString();
	int value();
};


#endif // !TIMBER_H


