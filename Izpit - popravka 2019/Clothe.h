#pragma once
#include <iostream>

inline bool HasANumber(const char* arr)
{
	int len = strlen(arr);
	for (int i = 0; i < len; i++)
	{
		if (arr[i] >= '0' || arr[i] <= '9')
		{
			return true;
		}
	}
	return false;
}

class Clothe
{
private:
	char* colour;
	char* size;
	double price;

	void SetColour(const char*);
	void SetSize(const char*);
	void SetPrice(double);

	void CopyFrom(const Clothe&);
	void Free();
public:
	Clothe();
	Clothe(const char*, const char*, double);
	Clothe(const Clothe&);
	Clothe& operator=(const Clothe&);
	~Clothe();
	
	const char* GetColour() const;
	const char* GetSize() const;
	double GetPrice() const;
	virtual const char* GetType() const = 0;
};