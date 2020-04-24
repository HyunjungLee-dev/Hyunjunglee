#include "Character.h"
#define GRAVITY 1500


Character::Character()
{
	m_ipositionX = 100.f;
	m_ipositionY = 175.f;
	m_iMoveNum = 1;
	m_bJumpKey = false;
	count = 0;
	jump = 0;

}

void Character::init(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);
	m_CharaBit.Init(hdc);
	ReleaseDC(hWnd, hdc);
}

void Character::Move(HWND hWnd,WPARAM wParam)
{
	switch (wParam)
	{
	case VK_LEFT:
		m_eDirection = DIRECTION_LEFT;
		m_ipositionX -= 10;
		break;
	case VK_RIGHT:
		m_eDirection = DIRECTION_RIGHT;
		m_ipositionX += 10;
		break;
	case VK_UP:;
		m_eDirection = DIRECTION_UP;
		m_ipositionY -= 10;
		break;
	case VK_DOWN:
		m_eDirection = DIRECTION_DOWN;
		m_ipositionY += 10;
		break;
	case VK_SPACE:
		m_bJumpKey = true;
		m_iMoveNum = 3;
		break;
	}
	InvalidateRect(hWnd, NULL, TRUE);
}

void  Character::Update(HWND hWnd, HDC hdc)
{
	if (!m_bJumpKey)
	{
		m_iMoveNum++;
		if (m_iMoveNum > 3)
			m_iMoveNum = 0;
		KillTimer(hWnd, 1);
	}
	else
	{
		SetTimer(hWnd, 1, 100, NULL);
		Jump();
	}
	Draw(hdc);
}

void Character::Draw(HDC hdc)
{
	m_CharaBit.Draw(hdc, m_ipositionX, m_ipositionY, m_iMoveNum, (int)m_eDirection);
}



void Character::Jump()
{
	int cycle = 8;
	double pi = 3.141592;

	if (!m_bJumpKey)
		return;

	while(jump  < cycle)
	{
		if (m_eDirection == DIRECTION_LEFT)
			m_ipositionX -= 10;
		else if(m_eDirection == DIRECTION_RIGHT)
			m_ipositionX += 10;
		m_ipositionY = m_ipositionY + -sin(pi * 2 / cycle * count) *60;
		count++;
		jump++;
		return;
	}
	jump = 0;
	m_bJumpKey = false;
}

Character::~Character()
{
}
