#include <iostream>

class PopulatedPlace
{
private:
	char* name;
	int population;
	void Free();
	void CopyFrom(const PopulatedPlace&);
public:
	PopulatedPlace();
	PopulatedPlace(const char*, int);
	PopulatedPlace(const PopulatedPlace&);
	PopulatedPlace& operator=(const PopulatedPlace&);
	friend std::ostream& operator<<(std::ostream&, const PopulatedPlace&);

	~PopulatedPlace();

	void setName(const char*);
	char* getName() const;
	void setPopulation(int);
	int getPopulation() const;

	void printPopulatedPlace() const;
};