#include "BlockFactory.h"



BlockFactory::BlockFactory()
{
}


None* BlockFactory::MakeNone()
{
	return new None();
}


Number* BlockFactory::MakeNumber(IMG type)
{
	return new Number(type);
}

Flag* BlockFactory::MakeFlag()
{
	return new Flag();
}


Mine* BlockFactory::MakeMine()
{
	return new Mine();
}


BlockFactory::~BlockFactory()
{
}
