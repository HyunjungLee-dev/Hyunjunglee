#pragma once
#include"MapSite.h"

class Wall : public MapSite
{
	int Type;
public:
	Wall();
	virtual ~Wall();
	virtual void enter() {};
	virtual void Print();
};

