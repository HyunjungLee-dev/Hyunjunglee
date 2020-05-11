#pragma once
#include"BitMap.h"
#include<math.h>

enum DIRECTION
{
	DIRECTION_DOWN,
	DIRECTION_UP,
	DIRECTION_LEFT,
	DIRECTION_RIGHT
};

class Character
{
private:
	BitMap m_CharaBit;
	DIRECTION m_eDirection;
	bool m_bJumpKey, m_bMove;
	float m_ipositionX, m_ipositionY;
	int m_iMoveNum;
	int jump;
	float count;
public:
	void init(HWND hWnd);
	void Move();
	void Draw(HDC hdc);
	void Update(HWND hWnd);
	void Jump();
	Character();
	~Character();
};

