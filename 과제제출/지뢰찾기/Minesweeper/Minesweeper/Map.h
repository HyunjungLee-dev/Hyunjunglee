#pragma once
#include"Block.h"


class Map
{
	Draw draw;
	list<Block*> map;
	int m_iMineCount;
	int m_iNoneCount;


public:
	Map();
	~Map();
	void AddBlock(Block* block);
	void ChageBlock(Block* block);
	bool CheckBlock(int x, int y,int w,int h);
	void Print(bool benter);
	int SearchMine(int x, int y);
	inline int GetMineCount() {return m_iMineCount;}
	inline int GeNoneCount() { return m_iNoneCount; }
};

