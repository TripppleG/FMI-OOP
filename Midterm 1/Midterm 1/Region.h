#include "PopulatedPlace.h"

class Region : public PopulatedPlace
{
private:
	PopulatedPlace* places;
	void CopyFrom(const Region&);
	void Free();
public:
	Region();
	Region(const Region&);
	Region& operator=(const Region&);
	~Region();
	bool addPopulatedPlace(const PopulatedPlace&);
	bool findPopulatedPLace(const PopulatedPlace&);
	void saveToFile(const char*);
};