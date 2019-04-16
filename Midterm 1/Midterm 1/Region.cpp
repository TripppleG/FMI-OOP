#include "Region.h"

Region::Region() {}

Region::Region(int size)
{
	places = new PopulatedPlace[size];
	for (int i = 0; i < size; i++)
	{
		setRegion(places[i], size);
	}
}

Region::Region(const Region& other)
{
	CopyFrom(other);
}

Region& Region::operator=(const Region& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

Region::~Region()
{
	Free();
}

void Region::setRegion(PopulatedPlace& place, int size)
{
	for (int i = 0; i < size; i++)
	{
		place.setName("Name");
		place.setPopulation(0);
	}
}

bool Region::addPopulatedPlace(const PopulatedPlace& place)
{
	return true;
}

bool Region::findPopulatedPlace(const PopulatedPlace& place) const
{
	return !strcmp(place.getName(), getName()) && place.getPopulation() == getPopulation();
}

void Region::saveToFile(const char*)
{
}
