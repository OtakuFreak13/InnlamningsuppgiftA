#include "HousingRegister.h"
#include<fstream>



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
		this->housing[i] = new Housing(*origObj.housing[i]);
		float b = 0;
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
			temp[i] = new Housing();
			*temp[i] = *origObj.housing[i];
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
	if (!exists)
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
				delete this->housing[i];
				//this->housing[i] = new Housing();
			}
			else
			{
				delete this->housing[i];
				this->housing[i] = this->housing[this->elementsInArr - 1];
				//delete this->housing[this->elementsInArr - 1];
				//this->housing[this->elementsInArr - 1] = new Housing();
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

bool HousingRegister::checkId(int id)const
{
	bool exists = false;
	for (int i = 0; i < this->elementsInArr; i++)
	{
		if (id == this->housing[i]->getId())
		{
			exists = true;

		}
	}
	return exists;
}

void HousingRegister::changeHousingParameters(int id, int newId, string newAdress, int newRent, string newHouseType, int newLivingSpace, int newRooms)
{
	for (int i = 0; i < this->elementsInArr; i++)
	{
		if (id == this->housing[i]->getId())
		{
			this->housing[i]->setId(newId);
			this->housing[i]->setAdress(newAdress);
			this->housing[i]->setRent(newRent);
			this->housing[i]->setHouseType(newHouseType);
			this->housing[i]->setLivingSpace(newLivingSpace);
			this->housing[i]->setRooms(newRooms);
		}
	}

}

string HousingRegister::readFromFile(string fileName)
{
	//bool exists = true;
	string returnString;
	ifstream in;
	in.open(fileName);
	if (!in)
	{
		returnString = "Error";
	}
	else
	{
		int elementsInArr = 0;
		in >> elementsInArr;
		//HousingRegister* temp = new HousingRegister(elementsInArr);
		int id;
		string adress;
		int rent;
		string housingType;
		int livingSpace;
		int rooms;
		for (int i = 0; i < elementsInArr; i++)
		{

			in >> id; in.ignore();
			in >> adress; in.ignore();
			in >> rent;	in.ignore();
			in >> housingType; in.ignore();
			in >> livingSpace; in.ignore();
			in >> rooms; in.ignore();
			//temp->housing[i]->setId(id);
			//temp->housing[i]->setAdress(adress);
			//temp->housing[i]->setRent(rent);
			//temp->housing[i]->setHouseType(housingType);
			//temp->housing[i]->setLivingSpace(livingSpace);
			//temp->housing[i]->setRooms(rooms);
			returnString += "\nId: " + to_string(id) + "\nAdress: " + adress + "\nRent per month: " + to_string(rent) + "kr" + "\nType of Housing" + housingType + "\nLiving area: " + to_string(livingSpace) + "m^2" + "\nNumber of rooms: " + to_string(rooms);
			
		}
	}
	in.close();
	return returnString;
}

void HousingRegister::writeToFile(string filename)
{
	ofstream out;
	out.open(filename);

	out << this->elementsInArr << endl;
	for (int i = 0; i < elementsInArr; i++)
	{
		out << this->housing[i]->getId() << endl;
		out << this->housing[i]->getAdress() << endl;
		out << this->housing[i]->getRent() << endl;
		out << this->housing[i]->getHouseType() << endl;
		out << this->housing[i]->getLivingSpace() << endl;
		out << this->housing[i]->getRooms() << endl;
	}
	out.close();
}
