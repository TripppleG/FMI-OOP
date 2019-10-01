#pragma once
#include "Clothe.h"

class Panths : public Clothe
{
private:
	int panthLength;
	void SetPanthLength(int);
public:
	Panths(const char*, const char*, double, int);
	int GetLength() const;
	const char* GetType() const;
	Clothe* Clone();
};
