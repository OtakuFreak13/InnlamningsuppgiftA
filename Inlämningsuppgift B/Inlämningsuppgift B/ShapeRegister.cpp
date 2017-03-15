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
		}
		else
		{
			aBoxPtr = dynamic_cast<Box*>(orgObj.shapes[i]);
			this->shapes[i] = new Box(*aBoxPtr);
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
	bool exists = false;

	if (this->capacity == this->amountOfShapes)
	{
		expand();
	}

	for (int i = 0; i < this->amountOfShapes; i++)
	{
		if (this->shapes[i]->getHight() == hight)//kolla efter dubletter
		{
			exists = true;
		}
	}
	if (exists == false)
	{
		this->shapes[this->amountOfShapes++] = new Cone(hight, radius);
	}

	return exists;
}

bool ShapeRegister::addBox(float hight, float width, float lenght)
{
	bool exists = false;

	if (this->capacity == this->amountOfShapes)
	{
		expand();
	}

	for (int i = 0; i < this->amountOfShapes; i++)
	{
		if (this->shapes[i]->getHight() == hight)
		{
			exists = true;
		}
	}
	if (exists == false)
	{
		this->shapes[this->amountOfShapes++] = new Box(hight, width, lenght);
	}

	return !exists;
}

bool ShapeRegister::removeShape(float hight)
{
	bool success = false;
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
	return success;
}


bool ShapeRegister::getAllShapesAsStrings(string arr[], int capOfArr)
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

bool ShapeRegister::getAllConesAsStrings(string arr[], int capOfArr)
{
	bool filled = false;
	Cone* aConePtr;
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		aConePtr = dynamic_cast<Cone*>(shapes[i]);
		if (this->shapes[i] != nullptr)
		{
			arr[i] = shapes[i]->toString();
			filled = true;
		}
	}
	return filled;
}

bool ShapeRegister::getAllBoxesAsStrings(string arr[], int capOfArr)
{
	bool filled = false;
	Box* aBoxPtr;
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		aBoxPtr = dynamic_cast<Box*>(shapes[i]);
		if (this->shapes[i] != nullptr)
		{
			arr[i] = shapes[i]->toString();
			filled = true;
		}
	}
	return filled;
}

bool ShapeRegister::editACone(float hight, float radius)
{
	bool exists = false;
	Cone* aConePtr = nullptr;
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		if (this->shapes[i]->getHight() == hight);
		{
			aConePtr = dynamic_cast<Cone*>(this->shapes[i]);
			if (aConePtr != nullptr)
			{
				aConePtr->setRadius(radius);
				exists = true;
			}
		}
	}
	return exists;
}

bool ShapeRegister::editABox(float hight, float width, float length)
{
	bool exists = false;
	Box* aBoxPtr = nullptr;
	for (int i = 0; i < this->amountOfShapes; i++)
	{
		if (this->shapes[i]->getHight() == hight);
		{
			aBoxPtr = dynamic_cast<Box*>(this->shapes[i]);
			if (aBoxPtr != nullptr)
			{
				aBoxPtr->setWidth(width);
				aBoxPtr->setLenght(length);
				exists = true;
			}
		}
	}
	return exists;
}

int ShapeRegister::nrOfShapes()
{
	return this->amountOfShapes;
}

int ShapeRegister::nrOfCones()
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

int ShapeRegister::nrOfBoxes()
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

ShapeRegister ShapeRegister::operator=(ShapeRegister orgObj)
{
	if (this != &orgObj) {

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

