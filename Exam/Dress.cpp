#include "Dress.h"

void Dress::SetDressLength(int dressLength)
{
	if (dressLength < 30)
	{
		throw "Invalid Length Value!";
	}
	this->dressLength = dressLength;
}

Dress::Dress(const char* colour, const char* size, double price, int panthLength) : Clothe(colour, size, price)
{
	SetDressLength(panthLength);
}

int Dress::GetLength() const
{
	return dressLength;
}

const char* Dress::GetType() const
{
	return "Dress";
}

Clothe* Dress::Clone()
{
	Clothe* copy = new Dress(*this);
	return copy;
}
