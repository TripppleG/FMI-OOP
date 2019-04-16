#pragma once
#include"PopulatedPlace.h"

class Region: public PopulatedPlace
{
private:
	PopulatedPlace* places;
	void CopyFrom(const Region& other)
	{
		int size = sizeof(Region) / sizeof(PopulatedPlace);
		for (int i = 0; i < size; i++)
		{
			PopulatedPlace(other.places[i]);
		}
	}
	void Free()
	{
		int size = sizeof(Region) / sizeof(PopulatedPlace);
		delete[] places;
	}
	
public:
	Region();
	Region(int);
	Region(const Region&);
	Region& operator=(const Region&);
	~Region();

	void setRegion(PopulatedPlace&, int);
	bool addPopulatedPlace(const PopulatedPlace&);
	bool findPopulatedPlace(const PopulatedPlace&) const;
	void saveToFile(const char*);
};