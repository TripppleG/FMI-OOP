#pragma once
#include "Clothe.h"

class Dress : public Clothe
{
private:
	int dressLength;
	void SetDressLength(int);
public:
	Dress(const char*, const char*, double, int);
	int GetLength() const;
	const char* GetType() const;
};