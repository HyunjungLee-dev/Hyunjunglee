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
	float m_fMoveStartTime;

	DIRECTION m_eDirection;
	bool m_bMove;
	float m_ipositionX, m_ipositionY;
	int m_iMoveNum;
	int flag;
public:
	void Move();
	void Draw();
	void Update(HWND hWnd);
	Character();
	~Character();
};

