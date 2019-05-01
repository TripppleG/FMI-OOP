#include "PopulatedPlace.h"

class Region : public PopulatedPlace
{
private:
	PopulatedPlace* places;
	int size;
	void CopyFrom(const Region&);
	void Free();
public:
	Region();
	Region(int);
	Region(const Region&);
	Region& operator=(const Region&);
	~Region();
	int getSize() const;
	bool addPopulatedPlace(const PopulatedPlace&);
	bool findPopulatedPLace(const PopulatedPlace&) const;
	void saveToFile(const char*);
};