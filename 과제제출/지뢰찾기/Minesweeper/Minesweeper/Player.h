#pragma once
#include"Mecro.h"
#include"Block.h"
#include"MapFactory.h"

enum KEY
{
	POS = 224,
	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT =77,
	ENTER = 13,
	SPACE = 32
};

class Player
{
	int m_ix;
	int m_iy; 
	int m_iFlagCount;
	bool m_bGOver;
	MapFactory*  factory;
	list<Block*> FlagList ;
public:
	Player();
	~Player();
	void Control(int w, int h, Map* map);
	void PutFlag();
	void PlayerInit();
	inline bool GetGOvert() { return m_bGOver; }
	inline int GetFlagCount() {	return m_iFlagCount;	}
};

