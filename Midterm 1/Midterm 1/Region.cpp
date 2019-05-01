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
}

Region::Region(int size)
{
	places = new PopulatedPlace[size];
	this->size = size;
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

Region::~Region() {}

int Region::getSize() const
{
	return size;
}

bool Region::addPopulatedPlace(const PopulatedPlace& other)
{
	places[0] = other;
	return false;
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
	Region r(*this);
	std::ofstream file(filename);
	file.write((const char*)(r.getName()), sizeof(r.getName()));
}
