#include "Housing.h"



Housing::Housing(int id, string adress, int rent, string houseType, int livingSpace, int rooms)
{
	this->id = id;
	this->adress = adress;
	this->rent = rent;
	this->houseType = houseType;
	this->livingSpace = livingSpace;
	this->rooms = rooms;
}


Housing::~Housing()
{
	
}

Housing::Housing(const Housing & origObj)//Behvövs kanske inte?
{
	//this->setId(origObj.id);
	//this->setAdress(origObj.adress);
	//this->setRent(origObj.rent);
	//this->setHouseType(origObj.houseType);
	//this->setLivingSpace(origObj.livingSpace);
	//this->setRooms(origObj.rooms);
	this->id = origObj.id;
	this->adress = origObj.adress;
	this->rent = origObj.rent;
	this->houseType = origObj.houseType;
	this->livingSpace = origObj.livingSpace;
	this->rooms = origObj.rooms;
}

Housing& Housing::operator=(const Housing & origObj)
{
	if (this != &origObj) {
		this->id = origObj.id;
		this->adress = origObj.adress;
		this->rent = origObj.rent;
		this->houseType = origObj.houseType;
		this->livingSpace = origObj.livingSpace;
		this->rooms = origObj.rooms;
	}
	
	return *this;
}

int Housing::getId() const
{
	return this->id;
}

string Housing::getAdress() const
{
	return this->adress;
}

int Housing::getRent() const
{
	return this->rent;
}

string Housing::getHouseType() const
{
	return this->houseType;
}

int Housing::getLivingSpace() const
{
	return this->livingSpace;
}

int Housing::getRooms() const
{
	return this->rooms;
}

void Housing::setId(int id)
{
	this->id = id;
}

void Housing::setAdress(string adress)
{
	this->adress = adress;
}

void Housing::setRent(int rent)
{
	this->rent = rent;
}

void Housing::setHouseType(string houseType)
{
	this->houseType = houseType;
}

void Housing::setLivingSpace(int livingSpace)
{
	this->livingSpace = livingSpace;
}

void Housing::setRooms(int rooms)
{
	this->rooms = rooms;
}

string Housing::toString() const
{
	return "\nId: " + to_string(this->getId()) + "\nAdress: " + this->adress + "\nRent per month: " + to_string(this->getRent()) + "kr" + "\nType of Housing" + this->houseType + "\nLiving area: " + to_string(this->getLivingSpace()) + "m^2" + "\nNumber of rooms: " + to_string(this->getRooms());
}
