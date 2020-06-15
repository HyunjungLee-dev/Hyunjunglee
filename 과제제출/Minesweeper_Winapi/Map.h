#pragma once
#include"BlockFactory.h"

class Map
{

	vector<Block*> m_pMap;
	BlockFactory* m_pFactory;

	int m_iNoneCount;
	int m_iMineCount;
	bool m_MineCheck;

	int m_iHeight;
	int m_iWidth;

	int sizeX, sizeY;


	HDC m_backbufferDC;
	POS m_BlockPos;

public:
	void Init(int startX, int startY, HDC hdc, int minenum, LEVEL level);
	void SetMine(int startX, int startY, int minenum);
	void SetSize(LEVEL level, int minenum);

	void CheckBlock(int x, int y);
	void ChageBlock(Block* block);
	bool SearchMine(int x, int y);
	int MineNumber(int x, int y);
	
	void OpenMine();
	void CloseBlock();

	bool Collision(POINT pos, MOUSE button);

	void Render();
	void Release();

	POS GetBlockPos() { return m_BlockPos; }
	bool GetMineCheck() {return m_MineCheck;}
	int GetNoneCount() { return m_iNoneCount; }
	Map();
	~Map();
	
};

