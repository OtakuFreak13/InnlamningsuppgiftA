#ifndef TIMBER_H
#define TIMBER_H

#include<string>

using namespace std;

class Timber
{
private:
	int pricePerMeter;
	int width;
	int hight;

public:
	Timber(int pricePerMeter, int width, int hight);
	~Timber();

	int getPricePerMeter()const;
	int getWidth()const;
	int getHight()const;

	string toString();
};


#endif // !TIMBER_H


