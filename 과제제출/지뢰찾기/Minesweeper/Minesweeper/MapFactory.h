#pragma once
#include"Map.h"

class MapFactory
{
public:
	MapFactory();
	~MapFactory();
	Map* makeMap();
	None* makeNone();
	Flag* makeFlag();
	Mine* makeMine();
};

