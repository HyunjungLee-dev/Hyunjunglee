#include "MapFactory.h"



MapFactory::MapFactory()
{
}

Map*  MapFactory::makeMap()
{
	return new Map();
}

None* MapFactory::makeNone()
{
	return new None();
}

Flag* MapFactory::makeFlag()
{
	return new Flag();
}


Mine* MapFactory::makeMine()
{
	return new Mine();
}

MapFactory::~MapFactory()
{

}
