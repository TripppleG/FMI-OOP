#pragma once
#include <iostream>
#include <string.h>

class PopulatedPlace
{
private:
	char* name;
	int populaton;
	void CopyFrom(const PopulatedPlace& other)
	{
		int len = strlen(name);
		name = new char[len + 1];
		strcpy_s(name, len + 1, other.name);
	}
	void Free()
	{
		delete[] name;
		populaton = 0;
	}
public:
	PopulatedPlace();
	PopulatedPlace(const char*, int);
	PopulatedPlace(const PopulatedPlace&);
	PopulatedPlace& operator=(const PopulatedPlace&);
	~PopulatedPlace();

	void setName(const char*);
	char* getName()const;

	void setPopulation(int);
	int getPopulation() const;

};