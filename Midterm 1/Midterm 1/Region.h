#include "PopulatedPlace.h"

class Region : public PopulatedPlace
{
private:
	PopulatedPlace* places;
	int size;
	int elementsCount;
	void CopyFrom(const Region&);
	void Free();
public:
	Region();
	Region(const char*, const int, const int);
	Region(const Region&);
	Region& operator=(const Region&);
	~Region();
	bool addPopulatedPlace(const PopulatedPlace&);
	bool findPopulatedPLace(const PopulatedPlace&) const;
	void saveToFile(const char*);
};