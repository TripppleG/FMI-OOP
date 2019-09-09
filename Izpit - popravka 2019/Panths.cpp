#include "Panths.h"

void Panths::SetPanthLength(int panthLength)
{
	if (panthLength < 30)
	{
		throw "Invalid Length Value!";
	}
	this->panthLength = panthLength;
}

Panths::Panths(const char* colour, const char* size, double price, int panthLength) : Clothe(colour, size, price)
{
	SetPanthLength(panthLength);
}

int Panths::GetLength() const
{
	return panthLength;
}

const char* Panths::GetType() const
{
	return "Panths";
}
