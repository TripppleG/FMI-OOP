#include "Region.h"

void Region::CopyFrom(const Region& other)
{
	places = new PopulatedPlace[other.size];
	size = other.size;
	for (int i = 0; i < size; i++)
	{
		places[i] = other.places[i];
	}
}

void Region::Free()
{
	delete[] places;
	size = 0;
}

Region::Region()
{
	places = nullptr;
	size = 0;
	elementsCount = 0;
}

Region::Region(const char* name, const int population, const int size) : PopulatedPlace(name, population)
{
	places = new PopulatedPlace[size];
	this->size = size;
	elementsCount = 0;
}

Region::Region(const Region& other) : PopulatedPlace(other)
{
	CopyFrom(other);
}

Region& Region::operator=(const Region& other)
{
	if (this != &other)
	{
		Free();
		PopulatedPlace::operator=(other);
		CopyFrom(other);
	}
	return *this;
}

Region::~Region()
{
	Free();
}

bool Region::addPopulatedPlace(const PopulatedPlace& other)
{
	if (elementsCount >= size)
	{
		return false;
	}
	places[elementsCount] = other;
	elementsCount++;
	return true;
}

bool Region::findPopulatedPLace(const PopulatedPlace& place) const
{
	for (int i = 0; i < size; i++)
	{
		if (places[i] == place)
		{
			return true;
		}
	}
	return false;
}

void Region::saveToFile(const char* filename)
{

	std::ofstream file(filename);
	if (!file)
	{
		std::cout << "Error opening the file!" << std::endl;
		return;
	}
	int min = 0;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (places[i].getPopulation() > places[j].getPopulation())
			{
				PopulatedPlace temp(places[i]);
				places[i] = places[j];
				places[j] = temp;
			}
		}
	}
	for (int i = 0; i < size; i++)
	{
		file << places[i];
	}
	file.close();
}