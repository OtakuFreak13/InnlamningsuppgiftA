#ifndef VEHICLE_H
#define VEHICLE_H

#include<string>
#include<iostream>

using namespace std;

class Vehicle
{
private:
	int nrOfWheels = -1;
	int regNum = -1;
	string name = "no name";
public:
	Vehicle();
	~Vehicle();
	void addVehicle();
	int getNrOfWheels();
	string getName();
};

#endif // !VEHICLE_H