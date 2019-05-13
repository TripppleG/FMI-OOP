#include "Region.h"

int main()
{
	int size = 5;
	Region r("Somewhere", 5, size);
	PopulatedPlace a("Sofia", 20000);
	PopulatedPlace b("Vidin", 200);
	PopulatedPlace c("Varna", 432);
	PopulatedPlace d("Plovdiv", 1996);
	PopulatedPlace e("Burgas", 1660);
	r.addPopulatedPlace(a);
	r.addPopulatedPlace(b);
	r.addPopulatedPlace(c);
	r.addPopulatedPlace(d);
	r.addPopulatedPlace(e);
	r.saveToFile("Populated Places.txt");
}