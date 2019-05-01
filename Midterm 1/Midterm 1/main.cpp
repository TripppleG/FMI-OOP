#include "Region.h"

int main()
{
	PopulatedPlace d1("Sofia", 200);
	Region r(2);
	r.addPopulatedPlace(d1);
	r.saveToFile("Name");
}