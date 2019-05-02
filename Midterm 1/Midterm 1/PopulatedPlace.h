#include <iostream>
#include <fstream>

class PopulatedPlace
{
private:
	char* name;
	int population;
	bool HasDigits(const char*) const;
	void CopyFrom(const PopulatedPlace&);
	void Free();
public:
	PopulatedPlace();
	PopulatedPlace(const char*, const int);
	PopulatedPlace(const PopulatedPlace&);
	PopulatedPlace& operator=(const PopulatedPlace&);
	friend std::ostream& operator<<(std::ostream&, const PopulatedPlace&);
	bool operator==(const PopulatedPlace&) const;
	~PopulatedPlace();

	void setName(const char*);
	const char* getName() const;
	void setPopulation(int);
	int getPopulation() const;

	bool areTheSame(const PopulatedPlace&) const;
	void printPopulatedPlace() const;
};