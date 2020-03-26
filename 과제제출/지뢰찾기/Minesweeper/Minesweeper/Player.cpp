#include "Player.h"



Player::Player() 
{
	PlayerInit();
}

void Player::PlayerInit()
{
	m_ix = 0;
	m_iy = 0;
	m_bGOver = false;
	m_iFlagCount = 0;
}

void Player::Control(int w, int h, Map* map)
{
		int ch = getch();
		if (ch == ENTER)
		{
				if (map->CheckBlock(m_ix, m_iy) == false)
					m_bGOver =  true;
		}
		if (ch == SPACE)
		{
			PutFlag();
		}
		if (ch == POS)
		{
			ch = getch();
			switch (ch)
			{
			case UP:
				if (m_iy - 1 >= 0)
					m_iy--;
				break;
			case DOWN:
				if (m_iy + 1 < h)
					m_iy++;
				break;
			case LEFT:
				if (m_ix - 1 >= 0)
					m_ix--;
				break;
			case RIGHT:
				if (m_ix + 1 < w)
					m_ix++;
				break;
			default:
				break;
			}
			gotoxy(m_ix * 2 + 2, m_iy + 1);
		}
} 

void Player::PutFlag()
{
	list<Block*>::iterator begin = FlagList.begin();
	list<Block*>::iterator end = FlagList.end();
		while (begin != end)
		{
			if (FlagList.empty())
				break;
			else	if ((*begin)->GetX() == m_ix && (*begin)->GetY() == m_iy) // 이미 깃발이 있다면
			{
				(*begin)->DrawBlock(false);
				m_iFlagCount--;
				FlagList.erase(begin);
				return;
			}
			begin++;
		}
	Block* block;
	block = factory->makeFlag();
	block->SetBlock(m_ix, m_iy);
	FlagList.push_back(block);
	m_iFlagCount++;
	block->DrawBlock(true);
}


Player::~Player()
{

}
