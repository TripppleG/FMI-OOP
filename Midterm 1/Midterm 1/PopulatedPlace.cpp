#include "PopulatedPlace.h"

PopulatedPlace::PopulatedPlace() 
{
	setName("");
	setPopulation(0);
}

PopulatedPlace::PopulatedPlace(const char* name, int population)
{
	setName(name);
	setPopulation(population);
}

PopulatedPlace::PopulatedPlace(const PopulatedPlace&other)
{
	CopyFrom(other);
}

PopulatedPlace& PopulatedPlace::operator=(const PopulatedPlace& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

PopulatedPlace::~PopulatedPlace()
{
	Free();
}

void PopulatedPlace::setName(const char* name)
{
	int len = strlen(name);
	for (int i = 0; i < len; i++)
	{
		if (name[i] >= '1' && name[i] <= '9')
		{
			this->name = new char[1];
			this->name = '\0';
			return;
		}
	}
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, name);
}

char* PopulatedPlace::getName() const
{
	return name;
}

void PopulatedPlace::setPopulation(int population)
{
	if (population < 0)
	{
		this->populaton = 0;
		return;
	}
	this->populaton = population;
}

int PopulatedPlace::getPopulation() const
{
	return populaton;
}