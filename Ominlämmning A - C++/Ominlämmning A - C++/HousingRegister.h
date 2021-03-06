#ifndef HOUSING_REGISTER_H
#define HOUSING_REGISTER_H

#include"Housing.h"

class HousingRegister
{
private:
	Housing** housing;
	int cap;
	int elementsInArr;
	void expand(const int newCap = 5);
public:
	HousingRegister(const int cap = 5);
	~HousingRegister();

	HousingRegister(const HousingRegister &origObj);
	HousingRegister& operator=(const HousingRegister &origObj);

	bool addHousing(const int id, const string adress, const int rent, const string houseType, const int livingSpace, const int rooms);
	bool removeHousing(const int id);

	void toStringSpecific(string *strArr)const;
	//int checkRent(int maxRent)const;
	void showHouseByRent(const int maxRent, string *strArr)const;
	//int findSpecificHousing(string type, int rooms)const;
	void showSpecificHousing(const string type, const int rooms, string *strArr)const;

	bool checkId(const int id)const;
	void changeHousingParameters(const int id, const int newId, const string newAdress, const int newRent, const string newHouseType, const int newLivingSpace, const int newRooms);
	string HousingRegister::readFromFile(const string fileName);
	void HousingRegister::writeToFile(const string filename);

	int getElementsInArr()const;
};



#endif // !HOUSING_REGISTER_H
