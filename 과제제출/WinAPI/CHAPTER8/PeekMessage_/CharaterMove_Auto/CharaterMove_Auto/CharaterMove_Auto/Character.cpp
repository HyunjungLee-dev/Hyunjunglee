#include "Character.h"



Character::Character()
{
	m_ipositionX = 100.f;
	m_ipositionY = 175.f;
	m_iMoveNum = 0;
	m_bMove = false;
	m_fMoveStartTime = (float)timeGetTime() * 0.001f;
	flag = 0;
	m_eDirection = DIRECTION_RIGHT;

}

void Character::Move()
{
	float NowTime = (float)timeGetTime() * 0.001f;
	if (NowTime - m_fMoveStartTime >= 0.03f)
	{
		switch (m_eDirection)
		{
		case DIRECTION_RIGHT:
			m_bMove = true;
			m_ipositionX += 10;
			if (1000 <= m_ipositionX + 50)
				m_eDirection = DIRECTION_LEFT;
			break;
		case DIRECTION_LEFT:
			m_ipositionX -= 10;
			m_bMove = true;
			if (0 >= m_ipositionX)
				m_eDirection = DIRECTION_RIGHT;
			break;
		}
		if (!m_bMove)
		{
			m_iMoveNum = 0;
		}
		else if (m_bMove)
		{
			m_iMoveNum++;
			if (m_iMoveNum > 3)
				m_iMoveNum = 0;
			m_bMove = false;
		}
		m_fMoveStartTime = NowTime;
	}
}

void  Character::Update(HWND hWnd)
{

	Move();

}

void Character::Draw()
{
	BitMap::GetSingleton()->Draw(m_ipositionX, m_ipositionY, m_iMoveNum, (int)m_eDirection);
}



Character::~Character()
{
}
