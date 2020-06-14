#pragma once
#include"Block.h"

class BlockFactory
{
public:
	None* MakeNone();
	Number* MakeNumber(IMG type);
	Flag* MakeFlag();
	Mine* MakeMine();

	BlockFactory();
	~BlockFactory();
};

