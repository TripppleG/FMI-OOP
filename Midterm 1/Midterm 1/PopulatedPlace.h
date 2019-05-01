#include <iostream>
#include <fstream>

class PopulatedPlace
{
private:
	char* name;
	int population;
	bool HasDigits() const;
	void Free();
	void CopyFrom(const PopulatedPlace&);
public:
	PopulatedPlace();
	PopulatedPlace(const char*, int);
	PopulatedPlace(const PopulatedPlace&);
	PopulatedPlace& operator=(const PopulatedPlace&);
	bool operator==(const PopulatedPlace&) const;
	~PopulatedPlace();

	void setName(const char*);
	const char* getName() const;
	void setPopulation(int);
	int getPopulation() const;

	bool areTheSame(const PopulatedPlace&) const;
	void printPopulatedPlace() const;
};