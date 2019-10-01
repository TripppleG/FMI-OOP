#pragma once
#include "Clothe.h"

class SuitCase
{
private:
	
	Clothe** clothes;
	char* colour;
	char* name;
	char* phoneNumber;
	char* address;
	int count;
	int size;

	void SetColour(const char*);
	void SetName(const char*);
	void SetPhoneNumber(const char*);
	void SetAdress(const char*);
	void SetSize(int);

	void CopyFrom(const SuitCase&);
	void Free();

public:
	SuitCase(const char*, const char*, const char*, const char*, int);
	SuitCase(const SuitCase&);
	SuitCase& operator=(const SuitCase&);
	friend std::ostream& operator<<(std::ostream&, const SuitCase&);
	~SuitCase();

	SuitCase* Clone();
	void AddClothe(const Clothe&);
	bool IsThereRoom() const;
	void RemoveClotheOfType(const char*);
	void FindClothe(const char*, const char*) const;
	void SaveToFile();

	const char* GetColour() const;
	const char* GetName() const;
	const char* GetPhoneNumber() const;
	const char* GetAddress() const;
	int GetSize() const;
	int GetNumberOfClothesInSuitcase() const;

};
