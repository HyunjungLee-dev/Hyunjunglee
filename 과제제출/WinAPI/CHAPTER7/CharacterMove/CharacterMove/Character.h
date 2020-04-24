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
	bool m_bJumpKey;
	float m_ipositionX, m_ipositionY;
	int m_iMoveNum;
	int jump;
	float count;
public:
	void init(HWND hWnd);
	void Move(HWND hWnd,WPARAM wParam);
	void Draw(HDC hdc);
	void Update(HWND hWnd, HDC hdc);
	void Jump();
	Character();
	~Character();
};

