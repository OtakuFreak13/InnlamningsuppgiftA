#ifndef HOUSING_REGISTER_H
#define HOUSING_REGISTER_H

#include"Housing.h"

class HousingRegister
{
private:
	Housing** housing;
	int cap;
	int elementsInArr;
	void expand(int newCap = 5);
public:
	HousingRegister(int cap = 5);
	~HousingRegister();

	HousingRegister(const HousingRegister &origObj);
	HousingRegister& operator=(const HousingRegister &origObj);

	bool addHousing(int id, string adress, int rent, string houseType, int livingSpace, int rooms);//göra om till bool?
	bool removeHousing(int id);

	string toStringSpecific()const;
	//int checkRent(int maxRent)const;
	string showHouseByRent(int maxRent)const;
	//int findSpecificHousing(string type, int rooms)const;
	string showSpecificHousing(string type, int rooms)const;
};



#endif // !HOUSING_REGISTER_H
