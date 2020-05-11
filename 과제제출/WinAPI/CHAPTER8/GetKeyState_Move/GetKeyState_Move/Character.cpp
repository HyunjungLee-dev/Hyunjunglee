#include "Character.h"
#define GRAVITY 1500


Character::Character()
{
	m_ipositionX = 100.f;
	m_ipositionY = 175.f;
	m_iMoveNum = 0;
	m_bJumpKey = false;
	m_bMove = false;
	count = 0;
	jump = 0;

}

void Character::init(HWND hWnd)
{
	HDC hdc = GetDC(hWnd);
	m_CharaBit.Init(hdc,L"image.bmp");
	ReleaseDC(hWnd, hdc);
}

void Character::Move()
{
	if (GetKeyState(VK_LEFT) & 0x8000)
	{
		m_eDirection = DIRECTION_LEFT;
		m_bMove = true;
		m_ipositionX -= 10;
	}
	if (GetKeyState(VK_RIGHT) & 0x8000)
	{
		m_eDirection = DIRECTION_RIGHT;
		m_bMove = true;
		m_ipositionX += 10;
	}
	if (GetKeyState(VK_UP) & 0x8000)
	{
		m_eDirection = DIRECTION_UP;
		m_bMove = true;
		m_ipositionY -= 10;
	}
	if (GetKeyState(VK_DOWN) & 0x8000)
	{
		m_eDirection = DIRECTION_DOWN;
		m_bMove = true;
		m_ipositionY += 10;
	}
	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		m_bJumpKey = true;
		m_iMoveNum = 3;
	}
}

void  Character::Update(HWND hWnd)
{
	if (!m_bMove && !m_bJumpKey)
	{
		m_iMoveNum = 0;
	}
	else if (!m_bJumpKey && m_bMove)
	{
		m_iMoveNum++;
		if (m_iMoveNum > 3)
			m_iMoveNum = 0;
		m_bMove = false;
		KillTimer(hWnd, 2);
	}
	else
	{
		SetTimer(hWnd, 2, 100, NULL);
		Jump();
	}
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

	while (jump < cycle)
	{
		if (m_eDirection == DIRECTION_LEFT)
			m_ipositionX -= 10;
		else if (m_eDirection == DIRECTION_RIGHT)
			m_ipositionX += 10;
		m_ipositionY = m_ipositionY + -sin(pi * 2 / cycle * count) * 60;
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
