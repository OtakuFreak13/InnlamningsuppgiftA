#include "HousingRegister.h"



void HousingRegister::expand(int newCap)
{
	this->cap += newCap;
	Housing* *temp = new Housing*[this->cap];
	for (int i = 0; i < this->elementsInArr; i++)
	{
		temp[i] = this->housing[i];
	}
	delete[] this->housing;
	this->housing = temp;
}

HousingRegister::HousingRegister(int cap)
{
	this->cap = cap;
	this->elementsInArr = 0;
	housing = new Housing*[this->cap];
	for (int i = 0; i < this->elementsInArr; i++)
	{
		housing[i] = nullptr;
	}
}


HousingRegister::~HousingRegister()
{
	for (int i = 0; i < this->elementsInArr; i++)
	{
		delete this->housing[i];
	}
	delete[] this->housing;
}

HousingRegister::HousingRegister(const HousingRegister & origObj)
{
	this->elementsInArr = origObj.elementsInArr;
	this->cap = origObj.cap;
	this->housing = new Housing*[origObj.cap];
	for (int i = 0; i < this->elementsInArr; i++)
	{
		this->housing[i] = origObj.housing[i];
	}
}

HousingRegister& HousingRegister::operator=(const HousingRegister & origObj)
{
	if (this != &origObj)
	{
		delete[] this->housing;
		this->cap = origObj.cap;
		this->elementsInArr = origObj.elementsInArr;
		Housing* *temp = new Housing*[origObj.cap];
		for (int i = 0; i < origObj.elementsInArr; i++)
		{
			temp[i] = origObj.housing[i];
		}
		this->housing = temp;
	}
	return *this;
}

bool HousingRegister::addHousing(int id, string adress, int rent, string houseType, int livingSpace, int rooms)
{
	bool added = false;
	bool exists = false;
	for (int i = 0; i < this->elementsInArr; i++)
	{
		if (id == this->housing[i]->getId())
		{
			exists = true;
		}
	}
	if (exists != true)
	{
		if (this->elementsInArr == this->cap)
		{
			this->expand();
		}
		this->housing[elementsInArr++] = new Housing(id, adress, rent, houseType, livingSpace, rooms);
		//this->housing[this->elementsInArr]->setId(id);
		//this->housing[this->elementsInArr]->setAdress(adress);
		//this->housing[this->elementsInArr]->setRent(rent);
		//this->housing[this->elementsInArr]->setHouseType(houseType);
		//this->housing[this->elementsInArr]->setLivingSpace(livingSpace);
		//this->housing[this->elementsInArr]->setRooms(rooms);
		//elementsInArr++;
		added = true;
	}
	return added;
}

bool HousingRegister::removeHousing(int id)
{
	bool removed = false;
	Housing**temp;
	for (int i = 0; i < this->elementsInArr; i++)
	{
		if (id == this->housing[i]->getId())
		{
			if (i == (this->elementsInArr - 1))
			{
				this->housing[i] = new Housing();
			}
			else
			{
				this->housing[i] = this->housing[this->elementsInArr - 1];
				this->housing[this->elementsInArr - 1] = new Housing();
			}
			//for (int j = 0; j < i; j++)
			//{
			//	temp[j] = this->housing[j];
			//	if (this->elementsInArr - 1 > i)
			//	{
			//		for (int g = i + 1; g < this->elementsInArr - 1; g++)
			//		{
			//			temp[g - 1] = this->housing[g];
			//		}
			//	}
			//}
		//delete this->housing[i];
		this->elementsInArr--;
		removed = true;
		}
		
	}
	return removed;
}

string HousingRegister::toStringSpecific()const
{
	string allHouses;
	for (int i = 0; i < this->elementsInArr; i++)
	{
		allHouses += this->housing[i]->toString() + "\n";
	}
	return allHouses;
}

string HousingRegister::showHouseByRent(int maxRent) const
{
	string housesByRent;
	for (int i = 0; i < this->elementsInArr; i++)
	{
		if (maxRent >= this->housing[i]->getRent())
		{
			housesByRent += this->housing[i]->toString() + "\n";
		}
	}
	return housesByRent;
}

string HousingRegister::showSpecificHousing(string type, int rooms) const
{
	string specificHousing;

	for (int i = 0; i < this->elementsInArr; i++)
	{
		if (type == this->housing[i]->getHouseType() && rooms == this->housing[i]->getRooms())
		{
			specificHousing += this->housing[i]->toString() + "\n";
		}
	}

	return specificHousing;
}
