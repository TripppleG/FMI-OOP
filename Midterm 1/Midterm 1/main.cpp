#include "Region.h"

int main()
{
	int size = 10;
	int population = 2000;
	Region r("Somewhere", 5, size);
	PopulatedPlace s("Sofia", population);
	r.addPopulatedPlace(s);
	r.saveToFile("Region.txt");
}