#include "ShapeRegister.h"



void ShapeRegister::initiate(int from)
{
	for (int i = from; i < this->capacity; i++)
	{
		this->shapes[i] = nullptr;
	}
}


void ShapeRegister::expand()
{
	this->capacity = capacity * 2;

	Shape* *temp = new Shape*[this->capacity];
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		temp[i] = this->shapes[i];
	}
	delete[] this->shapes;
	this->shapes = temp;
	this->initiate(this->amountOfShapes);
}

ShapeRegister::ShapeRegister(int capacity)
{
	this->amountOfShapes = 0;
	this->capacity = capacity;
	this->shapes = new Shape*[capacity];
	this->initiate();
}

ShapeRegister::ShapeRegister(const ShapeRegister & orgObj)
{
	this->amountOfShapes = orgObj.amountOfShapes;
	this->capacity = orgObj.capacity;
	this->shapes = new Shape*[orgObj.capacity];
	Cone* aConePtr = nullptr;
	Box* aBoxPtr = nullptr;

	for (int i = 0; i < orgObj.amountOfShapes; i++)
	{
		aConePtr = dynamic_cast<Cone*>(orgObj.shapes[i]);
		if (aConePtr != nullptr)
		{
			this->shapes[i] = new Cone(*aConePtr);
			//*this->shapes[i] = *aConePtr;
		}
		else
		{
			aBoxPtr = dynamic_cast<Box*>(orgObj.shapes[i]);
			this->shapes[i] = new Box(*aBoxPtr);
			//*this->shapes[i] = *aBoxPtr;
		}
	}
}


ShapeRegister::~ShapeRegister()
{
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		delete this->shapes[i];
	}
	delete[] this->shapes;
}

bool ShapeRegister::addCone(float hight, float radius)
{
	bool exists = checkUniq(hight);

	if (this->capacity == this->amountOfShapes && !exists)
	{
		expand();
	}

	if (!exists)
	{
		this->shapes[this->amountOfShapes++] = new Cone(hight, radius);
	}

	return exists;
}

bool ShapeRegister::addBox(float hight, float width, float lenght)
{
	bool exists = checkUniq(hight);


	if (!exists)
	{

		if (this->capacity == this->amountOfShapes && !exists)
		{
			expand();
		}

		if (!exists)
		{
			this->shapes[this->amountOfShapes++] = new Box(hight, width, lenght);
		}
	}
	return exists;
}

bool ShapeRegister::removeShape(float hight)
{
	bool success = false;
	if (checkUniq(hight))
	{
		for (int i = 0; i < this->amountOfShapes; i++)
		{
			if (shapes[i]->getHight() == hight)
			{
				delete this->shapes[i];
				this->shapes[i] = this->shapes[amountOfShapes - 1];
				success = true;
				this->amountOfShapes--;
			}
		}
	}
	return success;
}


bool ShapeRegister::getAllShapesAsStrings(string arr[], int capOfArr)const
{
	bool filled = false;
	if (capOfArr >= this->amountOfShapes)
	{
		for (int i = 0; i < this->amountOfShapes; i++)
		{
			arr[i] = shapes[i]->toString();
		}
		filled = true;
	}
	return filled;
}

bool ShapeRegister::getAllConesAsStrings(string arr[], int capOfArr)const
{
	bool filled = false;
	Cone* aConePtr;
	if (capOfArr >= this->amountOfShapes)
	{
		int counter = 0;
		filled = true;
		for (int i = 0; i < this->amountOfShapes; i++)
		{
			aConePtr = dynamic_cast<Cone*>(shapes[i]);
			if (aConePtr != nullptr)
			{
				arr[counter] = shapes[i]->toString();
				counter++;
			}
		}
	}
	return filled;
}

bool ShapeRegister::getAllBoxesAsStrings(string arr[], int capOfArr)const
{
	bool filled = false;
	Box* aBoxPtr;
	if (capOfArr >= this->amountOfShapes)
	{
		filled = true;
		int counter = 0;
		for (int i = 0; i < this->amountOfShapes; i++)
		{
			aBoxPtr = dynamic_cast<Box*>(shapes[i]);
			if (aBoxPtr != nullptr)
			{
				arr[counter] = shapes[i]->toString();
				counter++;
			}
		}
	}
	return filled;
}

bool ShapeRegister::editACone(float hight, float radius, float newHight)
{
	bool exists = this->checkUniq(newHight);
	if (!exists)
	{
		Cone* aConePtr = nullptr;
		for (int i = 0; i < this->amountOfShapes; i++)
		{
			if (this->shapes[i]->getHight() == hight)
			{

				aConePtr = dynamic_cast<Cone*>(this->shapes[i]);
				if (aConePtr != nullptr)
				{
					aConePtr->setRadius(radius);
					aConePtr->setHight(newHight);
					exists = true;
				}
			}
		}
	}
	return exists;
}

bool ShapeRegister::editABox(float hight, float width, float length, float newHight)
{
	bool exists = this->checkUniq(newHight);
	if(!exists)
	{
		Box* aBoxPtr = nullptr;
		for (int i = 0; i < this->amountOfShapes; i++)
		{
			if (this->shapes[i]->getHight() == hight)
			{
				aBoxPtr = dynamic_cast<Box*>(this->shapes[i]);
				if (aBoxPtr != nullptr)
				{
					aBoxPtr->setWidth(width);
					aBoxPtr->setLenght(length);
					aBoxPtr->setHight(newHight);
					exists = true;
				}
			}
		}	
	}
	return exists;
}

int ShapeRegister::nrOfShapes()const
{
	return this->amountOfShapes;
}

int ShapeRegister::nrOfCones()const
{
	int existingCones = 0;
	Cone* aConePtr = nullptr;
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		aConePtr = dynamic_cast<Cone*>(this->shapes[i]);
		if (aConePtr != nullptr)
		{
			existingCones++;
		}
	}
	return existingCones;
}

int ShapeRegister::nrOfBoxes()const
{
	int existingBoxes = 0;
	Box* aBoxPtr = nullptr;
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		aBoxPtr = dynamic_cast<Box*>(this->shapes[i]);
		if (aBoxPtr != nullptr)
		{
			existingBoxes++;
		}
	}
	return existingBoxes;
}

ShapeRegister &ShapeRegister::operator=(const ShapeRegister &orgObj)
{
	if (this != &orgObj) {
		for (int i = 0; i < this->amountOfShapes;i++) 
		{
			delete this->shapes[i];
		}
		delete[] this->shapes;
		this->amountOfShapes = orgObj.amountOfShapes;
		this->capacity = orgObj.capacity;
		this->shapes = new Shape*[orgObj.capacity];

		Cone* aConePtr = nullptr;
		Box* aBoxPtr = nullptr;

		for (int i = 0; i < orgObj.amountOfShapes; i++)
		{
			aConePtr = dynamic_cast<Cone*>(orgObj.shapes[i]);
			if (aConePtr != nullptr)
			{
				this->shapes[i] = new Cone(*aConePtr);
			}
			else
			{
				aBoxPtr = dynamic_cast<Box*>(orgObj.shapes[i]);
				this->shapes[i] = new Box(*aBoxPtr);
			}
		}
	}
	return *this;
}

bool ShapeRegister::checkUniq(float hight)const
{
	bool exists = false;
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		if (this->shapes[i]->getHight() == hight)
		{
			exists = true;
		}
	}
	return exists;
}

