#include "Map.h"



Map::Map() 
{
}

void Map::Init(int startX, int startY,HDC hdc,int minenum, LEVEL level)
{
	int sx = startX, sy = startY;

	m_backbufferDC = hdc;
	m_MineCheck = false;

	switch (level)
	{
	case BEGINNER:
		sy *= 0.01;
		sx *= 0.002;
		break;
	case INTERMEDIATE:
		sy *= 0.03;
		sx *= 0.013;
		break;
	case ADVANCED:
		sy *= 0.04;
		sx *= 0.02;
		break;
	case CUSTOM:
		if (minenum == 10)
		{
			sy *= 0.01;
			sx *= 0.002;
		}
		else if (minenum > 10 && minenum <= 40)
		{
			sy *= 0.03;
			sx *= 0.013;
		}
		else if (minenum > 40)
		{
			sy *= 0.04;
			sx *= 0.02;
		}
		break;
	default:
		break;
	}

	SetSize(level,minenum);

	m_iNoneCount = m_iWidth * m_iHeight;
	m_iMineCount = 0;

	for (int x = 1; x <= m_iWidth; x++)
	{
		for (int y = 1; y <= m_iHeight; y++)
		{
			Block* block;
			block = m_pFactory->MakeNone();

			float sizeX = sx + BitmapManager::GetSingleton()->GetImg(block->GetType())->GetSize().cx  * x ;
			float sizeY = sy + BitmapManager::GetSingleton()->GetImg(block->GetType())->GetSize().cy * y;

			block->Setpos(sizeX, sizeY);
			block->SetRect();
			m_pMap.push_back(block);
		}
	}

	SetMine(sx, sy, minenum);
}

void Map::SetMine(int startX, int startY, int minenum)
{
	while (m_iMineCount != minenum)
	{
		int randx = startX + BitmapManager::GetSingleton()->GetImg(IMG_MINE)->GetSize().cx * (rand() % m_iWidth);
		int randy = startY + BitmapManager::GetSingleton()->GetImg(IMG_MINE)->GetSize().cy * (rand() % m_iHeight);

		if ((randx >= m_pMap.front()->GetPos().m_fX && randx <= m_pMap.back()->GetPos().m_fX)
			&& (randy >= m_pMap.front()->GetPos().m_fY && randy <= m_pMap.back()->GetPos().m_fY))
		{
			if (!SearchMine(randx, randy))
			{
				Block* block;
				block = m_pFactory->MakeMine();
				block->Setpos(randx, randy);
				ChageBlock(block);
				m_iMineCount++;
			}
		}
	}
}

void Map::SetSize(LEVEL level,int minenum)
{
	switch (level)
	{
	case BEGINNER:
		m_iHeight = 10;
		m_iWidth = 19;
		break;
	case INTERMEDIATE:
		m_iHeight = 13;
		m_iWidth = 25;
		break;
	case ADVANCED:
		m_iHeight = 16;
		m_iWidth = 30;
		break;
	case CUSTOM:
		if (minenum == 10)
		{
			m_iHeight = 10;
			m_iWidth = 19;
		}
		else if (minenum > 10 && minenum <= 40)
		{
			m_iHeight = 13;
			m_iWidth = 25;
		}
		else if (minenum > 40)
		{
			m_iHeight = 16;
			m_iWidth = 30;
		}
		break;
	default:
		break;
	}
}

void Map::ChageBlock(Block* block)
{
	vector<Block*>::iterator iter = m_pMap.begin();
	vector<Block*>::iterator end = m_pMap.end();

	if (!m_pMap.empty())
	{
		while (iter != end)
		{
			if ((*iter)->GetPos().m_fX == block->GetPos().m_fX &&
				(*iter)->GetPos().m_fY == block->GetPos().m_fY)
			{
				(*iter) = block;
				(*iter)->SetRect();
				break;
			}
			iter++;
		}
	}

}



void Map::CheckBlock(int x, int y)
{
	if (x < m_pMap.front()->GetPos().m_fX || x > m_pMap.back()->GetPos().m_fX
		|| y < m_pMap.front()->GetPos().m_fY || y > m_pMap.back()->GetPos().m_fY)
		return;

	

	for (int i = 0; i < m_pMap.size(); i++)
	{
		if (m_pMap[i]->GetPos().m_fX == x && m_pMap[i]->GetPos().m_fY == y)
		{
			if (m_pMap[i]->GetType() == IMG_MINE)
			{
				break;
				return;
			}
			else
			{
				sizeX = BitmapManager::GetSingleton()->GetImg(m_pMap.at(i)->GetType())->GetSize().cx;
				sizeY = BitmapManager::GetSingleton()->GetImg(m_pMap.at(i)->GetType())->GetSize().cy;

				if (!m_pMap[i]->GetClick())
				{
					m_iNoneCount--;
					if (MineNumber(x, y) == 0)
					{
						for (int k = -1; k <= 1; k++)
						{
							for (int j = -1; j <= 1; j++)
							{
								m_pMap[i]->SetClick(true);
								 CheckBlock(x + k * sizeX, y + j * sizeY);

							}
						}
					}
					break;
				}
			}
			return;

		}
	}
}

int Map::MineNumber(int x, int y)
{

	int mineNum = 0;

	for(int i=0; i<m_pMap.size(); i++)
	{
		if (m_pMap.at(i)->GetPos().m_fX == x - sizeX && m_pMap.at(i)->GetPos().m_fY == y + sizeY && m_pMap.at(i)->GetType() == IMG_MINE) mineNum++; //ºÏ¼­
		if (m_pMap.at(i)->GetPos().m_fX == x && m_pMap.at(i)->GetPos().m_fY == y + sizeY && m_pMap.at(i)->GetType() == IMG_MINE) mineNum++; //ºÏ
		if (m_pMap.at(i)->GetPos().m_fX == x + sizeX && m_pMap.at(i)->GetPos().m_fY == y + sizeY && m_pMap.at(i)->GetType() == IMG_MINE) mineNum++; //ºÏµ¿
		if (m_pMap.at(i)->GetPos().m_fX == x - sizeX && m_pMap.at(i)->GetPos().m_fY == y && m_pMap.at(i)->GetType() == IMG_MINE) mineNum++; //¼­
		if (m_pMap.at(i)->GetPos().m_fX == x + sizeX && m_pMap.at(i)->GetPos().m_fY == y && m_pMap.at(i)->GetType() == IMG_MINE) mineNum++; //µ¿
		if (m_pMap.at(i)->GetPos().m_fX == x - sizeX && m_pMap.at(i)->GetPos().m_fY == y - sizeY && m_pMap.at(i)->GetType() == IMG_MINE) mineNum++; //³²¼­
		if (m_pMap.at(i)->GetPos().m_fX == x && m_pMap.at(i)->GetPos().m_fY == y - sizeY && m_pMap.at(i)->GetType() == IMG_MINE) mineNum++; //³²
		if (m_pMap.at(i)->GetPos().m_fX == x + sizeX && m_pMap.at(i)->GetPos().m_fY == y - sizeY && m_pMap.at(i)->GetType() == IMG_MINE)//³²µ¿
		{
			mineNum++;
		}
	}
	
	
	if (mineNum != 0)
	{
		Block* block;
		block = m_pFactory->MakeNumber((IMG)mineNum);
		block->Setpos(x, y);
		block->SetClick(true);
		ChageBlock(block);
	}
	return mineNum;
	
}

bool Map::SearchMine(int x, int y)
{
	for (int i = 0; i < m_pMap.size(); i++)
	{
		if (m_pMap.at(i)->GetPos().m_fX == x && m_pMap.at(i)->GetPos().m_fY == y)
		{
			if (m_pMap.at(i)->GetType() == IMG_MINE)
			{
				return true;
			}
		}
	}
	return false;
}

bool Map::Collision(POINT pos, MOUSE button)
{
	for (int i = 0; i < m_pMap.size(); i++)
	{
		if (PtInRect(&m_pMap.at(i)->GetRct(), pos))
		{
			if (button == LBUTTONDOWN)
			{
				if (m_pMap.at(i)->GetType() == IMG_MINE)
				{
					m_pMap.at(i)->SetClick(true);
					return false;
				}
				else
				{
					CheckBlock(m_pMap.at(i)->GetPos().m_fX, m_pMap.at(i)->GetPos().m_fY);
				}	return true;
			}
			else
			{
				if (!m_pMap.at(i)->GetClick())
				{
					m_BlockPos = m_pMap.at(i)->GetPos();
					return true;
				}
				else
					return false;
			}
		}
	}
}

void Map::OpenMine()
{
	for (int i = 0; i < m_pMap.size(); i++)
	{
		if(m_pMap.at(i)->GetType() == IMG_MINE)
			m_pMap.at(i)->SetClick(true);
	}
}

void Map::CloseBlock()
{
	for (int i = 0; i < m_pMap.size(); i++)
	{
		m_pMap.at(i)->SetClick(false);
	}


	m_iNoneCount = m_iWidth * m_iHeight;

}

void Map::Render()
{

	for (int i = 0; i < m_pMap.size(); i++)
	{
		m_pMap.at(i)->DrawBlock(m_backbufferDC);
	}
}

void Map::Release()
{
	for (vector<Block*>::iterator it = m_pMap.begin(); it != m_pMap.end(); it++)
	{
		delete (*it);
	}
	m_pMap.clear();
}


Map::~Map()
{
}
