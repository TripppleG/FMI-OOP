#pragma once
#include "Clothe.h"

class Suit : public Clothe
{
public:
	Suit(const char* colour, const char* size, double price) : Clothe(colour, size, price) {}
	const char* GetType() const
	{
		return "Suit";
	}
};