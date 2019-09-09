#include "Clothe.h"

void Clothe::SetColour(const char* colour)
{
	int len = strlen(colour);
	if (HasANumber(colour) || len == 0)
	{
		throw "Invalid Colour Name!";
	}
	this->colour = new char[len + 1];
	strcpy_s(this->colour, len + 1, colour);
}

void Clothe::SetSize(const char* size)
{
	int len = strlen(size);
	if (len == 0 || (size != "XS" && size != "S" && size != "M" && size != "L" && size != "XL" && size != "XXL" && size != "XXXL"))
	{
		throw "Invalid Size";
	}
	this->size = new char[len + 1];
	strcpy_s(this->size, len + 1, size);
}

void Clothe::SetPrice(double price)
{
	if (price < 0)
	{
		throw "Invalid Price!";
	}
	this->price = price;
}

void Clothe::CopyFrom(const Clothe& other)
{
	SetColour(other.colour);
	SetPrice(other.price);
	SetSize(other.size);
}

void Clothe::Free()
{
	delete[]colour;
	delete[]size;
}

Clothe::Clothe()
{
	SetColour(".");
	SetSize(".");
	SetPrice(0);

}

Clothe::Clothe(const char* colour, const char* size, double price)
{
	SetColour(colour);
	SetSize(size);
	SetPrice(price);
}

Clothe::Clothe(const Clothe& other)
{
	CopyFrom(other);

}

Clothe& Clothe::operator=(const Clothe& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

Clothe::~Clothe()
{
	Free();
}

const char* Clothe::GetColour() const
{
	return colour;
}

const char* Clothe::GetSize() const
{
	return size;
}

double Clothe::GetPrice() const
{
	return price;
}
