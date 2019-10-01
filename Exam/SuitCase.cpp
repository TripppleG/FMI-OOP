#include "SuitCase.h"

void SuitCase::SetColour(const char* colour)
{
	int len = strlen(colour);
	if (HasANumber(colour) || len == 0)
	{
		throw "Invalid Colour Name!";
	}
	this->colour = new char[len + 1];
	strcpy_s(this->colour, len + 1, colour);
}

void SuitCase::SetName(const char* name)
{
	int len = strlen(name);
	if (HasANumber(name) || len == 0)
	{
		throw "Invalid Name!";
	}
	this->name = new char[len + 1];
	strcpy_s(this->name, len + 1, name);
}

void SuitCase::SetPhoneNumber(const char* phoneNumber)
{
	int len = strlen(phoneNumber);
	for (int i = 0; i < len; i++)
	{
		if (phoneNumber[i] <= '0' || phoneNumber[i] >= '9' || len == 0)
		{
			throw "Invalid Phone Number!";
		}
	}
	this->phoneNumber = new char[len + 1];
	strcpy_s(this->phoneNumber, len + 1, phoneNumber);
}

void SuitCase::SetAdress(const char* address)
{
	int len = strlen(address);
	if (len == 0)
	{
		throw "Invalid Address!";
	}
	this->address = new char[len + 1];
	strcpy_s(this->address, len + 1, address);
}

void SuitCase::SetSize(int size)
{
	if (size < 0)
	{
		throw "Invalid Size";
	}
	this->size = size;
}

void SuitCase::CopyFrom(const SuitCase& other)
{
	SetName(other.name);
	SetColour(other.colour);
	SetAdress(other.address);
	SetPhoneNumber(other.phoneNumber);
	SetSize(other.size);

	clothes = new Clothe*[size];
	for (int i = 0; i < size; i++)
	{
		clothes[i] = other.clothes[i];
	}
}

void SuitCase::Free()
{
	delete[] colour;
	delete[] name;
	delete[] address;
	delete[] phoneNumber;
}

SuitCase::SuitCase(const char* colour, const char* name, const char* address, const char* phoneNumber, int size)
{
	SetColour(colour);
	SetName(name);
	SetAdress(address);
	SetPhoneNumber(phoneNumber);
	SetSize(size);

	count = 0;
}

SuitCase::SuitCase(const SuitCase& other)
{
	CopyFrom(other);
}

SuitCase& SuitCase::operator=(const SuitCase& other)
{
	if (this != &other)
	{
		Free();
		CopyFrom(other);
	}
	return *this;
}

std::ostream& operator<<(std::ostream& ofs, const SuitCase& suitcase)
{
	ofs << "Colour: " << suitcase.colour << std::endl;
	ofs << "Owner name: " << suitcase.name << std::endl;
	ofs << "Address: " << suitcase.address << std::endl;
	ofs << "Phone number: " << suitcase.phoneNumber << std::endl << std::endl;

	for (int i = 0; i < suitcase.count; i++)
	{
		ofs << suitcase.clothes[i].GetColour() << " " << suitcase.clothes[i].GetType() << ":" << std::endl;
		ofs << "Size:" << suitcase.clothes[i].GetSize() << std::endl;
		ofs << "Price:" << suitcase.clothes[i].GetPrice() << std::endl << std::endl;
	}
	return ofs;
}

SuitCase::~SuitCase()
{
	Free();
}

SuitCase* SuitCase::Clone()
{
	SuitCase* copy = new SuitCase(*this);
	return copy;
}

void SuitCase::AddClothe(const Clothe& clothe)
{
	if (size == count)
	{
		throw "No room in the suitcase!";
	}
	clothes[count] = clothe;
	count++;
}

bool SuitCase::IsThereRoom() const
{
	return !(count == size);
}

void SuitCase::RemoveClotheOfType(const char* type)
{
	for (int i = 0; i < count; i++)
	{
		if (!strcmp(clothes[i].GetSize(), type))
		{
			for (int j = i; j < size; j++)
			{
				clothes[i] = clothes[i + 1];
			}
			count--;
		}
	}
}

void SuitCase::FindClothe(const char* colour, const char* type) const
{
	for (int i = 0; i < count; i++)
	{
		if (clothes[i].GetColour() == colour)
		{
			std::cout << "There is " << colour;
			if (clothes[i].GetType() == type)
			{
				std::cout << " " << type << std::endl;
			}
			else
			{
				std::cout << " clothe" << std::endl;
			}
		}
		return;
	}
	std::cout << "No such clothe!";
}

void SuitCase::SaveToFile()
{
	std::ofstream myFile("SuitCase.txt");
	myFile << *this;
}

const char* SuitCase::GetColour() const
{
	return colour;
}

const char* SuitCase::GetName() const
{
	return name;
}

const char* SuitCase::GetPhoneNumber() const
{
	return phoneNumber;
}

const char* SuitCase::GetAddress() const
{
	return address;
}

int SuitCase::GetSize() const
{
	return size;
}

int SuitCase::GetNumberOfClothesInSuitcase() const
{
	return count;
}