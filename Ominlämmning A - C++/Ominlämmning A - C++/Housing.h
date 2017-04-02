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
	Housing(int id = -1, string adress = "No adress", int rent = -1, string houseType = "No type", int livingSpace = -1, int rooms = -1);
	~Housing();

	Housing(const Housing &origObj);
	Housing& operator=(const Housing &origObj);

	int getId()const;
	string getAdress()const;
	int getRent()const;
	string getHouseType()const;
	int getLivingSpace()const;
	int getRooms()const;
	
	void setId(int id);
	void setAdress(string adress);
	void setRent(int rent);
	void setHouseType(string houseType);
	void setLivingSpace(int livingSpace);
	void setRooms(int rooms);

	string toString()const;
};



#endif // !HOUSING_H
