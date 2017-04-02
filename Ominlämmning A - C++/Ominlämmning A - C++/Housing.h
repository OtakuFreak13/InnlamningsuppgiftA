#ifndef HOUSING_H
#define HOUSING_H

#include<string>

using namespace std;

class Housing
{
private:
	int id;
	string adress;
	int rent;
	string houseType;
	int livingSpace;
	int rooms;
public:
	Housing(const int id = -1, const string adress = "No adress", const int rent = -1, const string houseType = "No type", const int livingSpace = -1, const int rooms = -1);
	~Housing();

	Housing(const Housing &origObj);
	Housing& operator=(const Housing &origObj);

	int getId()const;
	string getAdress()const;
	int getRent()const;
	string getHouseType()const;
	int getLivingSpace()const;
	int getRooms()const;
	
	void setId(const int id);
	void setAdress(const string adress);
	void setRent(const int rent);
	void setHouseType(const string houseType);
	void setLivingSpace(const int livingSpace);
	void setRooms(const int rooms);

	string toString()const;
};



#endif // !HOUSING_H
