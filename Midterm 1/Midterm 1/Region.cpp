#include "Region.h"

void Region::CopyFrom(const Region& other)
{
	int len = sizeof(*places) / sizeof(PopulatedPlace);
	for (int i = 0; i < len; i++)
	{

	}
}

void Region::Free()
{
	delete[] Region;
	size = 0;
}

Region::Region()
{
}

Region::Region(const Region&)
{
}

Region& Region::operator=(const Region&)
{
	// TODO: insert return statement here
}

Region::~Region()
{
}

bool Region::addPopulatedPlace(const PopulatedPlace&)
{
	return false;
}

bool Region::findPopulatedPLace(const PopulatedPlace&)
{
	return false;
}

void Region::saveToFile(const char*)
{
}
