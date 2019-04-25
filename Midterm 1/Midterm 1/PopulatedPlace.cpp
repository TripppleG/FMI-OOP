#include "PopulatedPlace.h"

bool HasDigits(const char* arr, int len)
{
	for (int i = 0; i < len; i++)
	{
		if (arr[i] >= '0' && arr[i] <= '9')
		{
			return true;
		}
	}
	return false;
}

void PopulatedPlace::Free()
{
	delete[] name;
	population = 0;
}

void PopulatedPlace::CopyFrom(const PopulatedPlace& other)
{
	int len = strlen(other.name);
	name = new char[len + 1];
	strcpy_s(name, len + 1, other.name);
	population = other.population;
}

PopulatedPlace::PopulatedPlace()
{
	name = nullptr;
	population = 0;
}

PopulatedPlace::PopulatedPlace(const char* name, int population)
{
	setName(name);
	setPopulation(population);
}

PopulatedPlace::PopulatedPlace(const PopulatedPlace& other)
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

std::ostream& operator<<(std::ostream& out, const PopulatedPlace& p)
{
	return out << p.getName() << " " << p.getPopulation() << std::endl;
}

PopulatedPlace::~PopulatedPlace()
{
	Free();
}

void PopulatedPlace::setName(const char* name)
{
	int len = strlen(name);
	if (HasDigits(name, len))
	{
		this->name = nullptr;
		return;
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
		population = 0;
	}
	this->population = population;
}

int PopulatedPlace::getPopulation() const
{
	return population;
}

void PopulatedPlace::printPopulatedPlace() const
{

}
