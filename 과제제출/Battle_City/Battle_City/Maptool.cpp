﻿#include "Maptool.h"


Maptool* Maptool::_Singleton = NULL;

Maptool::Maptool()
{
}

void Maptool::Init()
{
	m_dwLastTime = GetTickCount();
	m_dwCurTime = GetTickCount();

	SetMap();
	m_Cursor = { 0,0 };
	m_bConstruction = false;
	m_bItemFlag = false;
	m_iID = 0;
	m_iCollisionIndex = -1;
}

void Maptool::SetMap()
{
	for (int i = 0; i < TILEY; i++)
	{
		for (int j = 0; j < TILEX; j++)
		{
			m_Map.push_back(new Tile);
			m_Map.back()->eTileID = MAP_NONE;
			m_Map.back()->fX = j * TILESIZEX;
			m_Map.back()->fY = i * TILESIZEY;
			m_Map.back()->fSizeX = TILESIZEX;
			m_Map.back()->fSizeY = TILESIZEY;
			m_Map.back()->Rct = {
				long(m_Map.back()->fX),long(m_Map.back()->fY),long(m_Map.back()->fX + TILESIZEX),long(m_Map.back()->fY + TILESIZEY)
			};
			if (j == 5 && i == 12 || j == 5 && i == 11)
			{
				m_Map.back()->eTileID = MAP_BLOCKR;
				m_Map.back()->Rct.left = long(m_Map.back()->fX + TILESIZEX * 0.5);
			}
			else if(j == 6 && i == 12)
				m_Map.back()->eTileID = MAP_EAGLE;
			else if(j == 6 && i ==11)
				m_Map.back()->eTileID = MAP_BLOCK;
			else if (j == 7 && i == 12 || j == 7 && i == 11)
			{
				m_Map.back()->eTileID = MAP_BLOCKL;
				m_Map.back()->Rct.right = long(m_Map.back()->fX + TILESIZEX * 0.5);
			}
		}
	}
}

void Maptool::ItemTileChange()
{
	if (m_bItemFlag)
	{
		m_Map[161]->eTileID = MAP_GBLOCKR;
		m_Map[148]->eTileID = MAP_GBLOCKR;
		m_Map[149]->eTileID = MAP_GBLOCK;
		m_Map[150]->eTileID = MAP_GBLOCKL;
		m_Map[163]->eTileID = MAP_GBLOCKL;
	}
	else
	{
		m_Map[161]->eTileID = MAP_BLOCKR;
		m_Map[148]->eTileID = MAP_BLOCKR;
		m_Map[149]->eTileID = MAP_BLOCK;
		m_Map[150]->eTileID = MAP_BLOCKL;
		m_Map[163]->eTileID = MAP_BLOCKL;
	}
}


void Maptool::Create()
{
	static POS checkpos = m_Cursor;

	int index = (m_Cursor.m_iY / TILESIZEY) * TILEX + (m_Cursor.m_iX / TILESIZEX);

	if ((m_Cursor.m_iX < TILESIZEX * 13 && m_Cursor.m_iX >= 0) && (m_Cursor.m_iY < TILESIZEY * 13 && m_Cursor.m_iY >= 0))
	{

			if (checkpos.m_iX == m_Cursor.m_iX && checkpos.m_iY == m_Cursor.m_iY)
			{
				m_Map[index]->eTileID++;
				if (m_Map[index]->eTileID >= MAP_GBLOCKR)
					m_Map[index]->eTileID = MAP_NONE;
				m_iID = m_Map[index]->eTileID;
			}
			else
				m_Map[index]->eTileID = m_iID;
			m_Map[index]->Rct = {long(m_Map[index]->fX),long(m_Map[index]->fY),long(m_Map[index]->fX + TILESIZEX),long(m_Map[index]->fY + TILESIZEY) };

			if (m_Map[index]->eTileID == MAP_BLOCKT || m_Map[index]->eTileID == MAP_GBLOCKT)
				m_Map[index]->Rct.bottom = long(m_Map[index]->fY + TILESIZEY * 0.5);
			else if (m_Map[index]->eTileID == MAP_BLOCKL || m_Map[index]->eTileID == MAP_GBLOCKL)
			{
				m_Map[index]->Rct.right = long(m_Map[index]->fX + TILESIZEX * 0.5);
			}
			else if (m_Map[index]->eTileID == MAP_BLOCKB || m_Map[index]->eTileID == MAP_GBLOCKB)
			{
				m_Map[index]->Rct.top = long(m_Map[index]->fY + TILESIZEY * 0.5);
			}
			else if (m_Map[index]->eTileID == MAP_BLOCKR || m_Map[index]->eTileID == MAP_GBLOCKR)
			{
				m_Map[index]->Rct.left = long(m_Map[index]->fX + TILESIZEX * 0.5);

			}
			checkpos = m_Cursor;
	}
}

void Maptool::CursorRender(HDC hdc)
{

	m_dwCurTime = GetTickCount();
	m_fDeltaTime = (m_dwCurTime - m_dwLastTime) / 1000.0f;


	if (m_bConstruction)
	{	
		if (m_fDeltaTime > 0.2f)
		{
			BitMapManager::GetSingleton()->GetImg(T_PLAYER_UP_0)->Draw(hdc, STARTX + m_Cursor.m_iX, STARTY + m_Cursor.m_iY, 1, 1);
		}
		if (m_fDeltaTime > 0.4f)
		{
			m_dwLastTime = m_dwCurTime;
		}

	}
}

void Maptool::layerRender(HDC hdc)
{
	for (int i = 0; i < m_Map.size(); i++)
	{
		if (m_Map[i]->eTileID == MAP_FOREST)
		{
			BitMapManager::GetSingleton()->GetImg((MAP)m_Map[i]->eTileID)->Draw(hdc, STARTX + m_Map[i]->fX, STARTY + m_Map[i]->fY, 1, 1);

		}
	}
}

void Maptool::Render(HDC hdc)
{


	RECT ret = { STARTX ,STARTY, TILESIZEX * TILEX , TILESIZEY * TILEY };
	PatBlt(hdc, ret.left, ret.top, ret.right, ret.bottom, BLACKNESS);

	for (int i = 0; i < m_Map.size(); i++)
	{
		if (m_Map[i]->eTileID == MAP_NONE)
		{
			//Rectangle(hdc, STARTX + m_Map[i]->fX, STARTY + m_Map[i]->fY, STARTX + m_Map[i]->fX + TILESIZEX, STARTY + m_Map[i]->fY + TILESIZEY);

		}
		else
		{
			if (m_iCollisionIndex != -1)
			{
				Effect(hdc);
			}
		
				BitMapManager::GetSingleton()->GetImg((MAP)m_Map[i]->eTileID)->Draw(hdc, STARTX + m_Map[i]->fX, STARTY + m_Map[i]->fY, 1, 1);
		}
		//Rectangle(hdc, STARTX + m_Map[i]->Rct.left, STARTY + m_Map[i]->Rct.top, STARTX + m_Map[i]->Rct.right, STARTY + m_Map[i]->Rct.bottom);
	}
}

void Maptool::Save()
{
	HANDLE hFile = CreateFile(L"Construction", GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, 0);
	for (int i = 0; i < m_Map.size(); i++)
	{

		DWORD writeB;
		WriteFile(hFile, &m_Map[i]->fX, sizeof(float), &writeB, NULL);
		WriteFile(hFile, &m_Map[i]->fY, sizeof(float), &writeB, NULL);
		WriteFile(hFile, &m_Map[i]->eTileID, sizeof(int), &writeB, NULL);
		WriteFile(hFile, &m_Map[i]->fSizeX, sizeof(float), &writeB, NULL);
		WriteFile(hFile, &m_Map[i]->fSizeY, sizeof(float), &writeB, NULL);
		WriteFile(hFile, &m_Map[i]->Rct, sizeof(RECT), &writeB, NULL);

	}
	CloseHandle(hFile);
}

void Maptool::Load(LPCWSTR Flie)
{
	Clear();
	SetMap();
	HANDLE hFile = CreateFile(Flie, GENERIC_READ, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0);
	for (int i = 0; i < m_Map.size(); i++)
	{
		DWORD readB;
		ReadFile(hFile, &m_Map[i]->fX, sizeof(float), &readB, NULL);
		ReadFile(hFile, &m_Map[i]->fY, sizeof(float), &readB, NULL);
		ReadFile(hFile, &m_Map[i]->eTileID, sizeof(int), &readB, NULL);
		ReadFile(hFile, &m_Map[i]->fSizeX, sizeof(float), &readB, NULL);
		ReadFile(hFile, &m_Map[i]->fSizeY, sizeof(float), &readB, NULL);
		ReadFile(hFile, &m_Map[i]->Rct, sizeof(RECT), &readB, NULL);
	}
	CloseHandle(hFile);
}

void Maptool::Clear()
{
	for (vector<Tile*>::iterator it = m_Map.begin(); it != m_Map.end(); it++)

	{
		delete (*it);
	}
	m_Map.clear();
}

bool Maptool::Collision(int index, DIRECTION direct)
{
	if (m_Map.at(index)->eTileID == MAP_BLOCK)
	{
		switch (direct)
		{
		case UP:
			m_Map[index]->eTileID = MAP_BLOCKT;
			m_Map[index]->Rct.bottom = long(m_Map[index]->fY + TILESIZEY * 0.5);
			break;
		case DOWN:
			m_Map[index]->eTileID = MAP_BLOCKB;
			m_Map[index]->Rct.top = long(m_Map[index]->fY + TILESIZEY * 0.5);
			break;
		case LEFT:
			m_Map[index]->eTileID = MAP_BLOCKL;
			m_Map[index]->Rct.right = long(m_Map[index]->fX + TILESIZEX * 0.5);
			break;
		case RIGHT:
			m_Map[index]->eTileID = MAP_BLOCKR;
			m_Map[index]->Rct.left = long(m_Map[index]->fX + TILESIZEX * 0.5);
			break;
		default:
			break;
		}
		return true;
	}
	else
	{
		switch ((MAP)m_Map.at(index)->eTileID)
		{
		case MAP_BLOCKT:
		case MAP_BLOCKL:
		case MAP_BLOCKB:
		case MAP_BLOCKR:
			m_Map[index]->eTileID = MAP_NONE;
			break;
		case MAP_EAGLE:
			m_iCollisionIndex = index;
			return false;
			break;
		case MAP_ENDFALGE:
			break;
		default:
			break;
		}
	}

}

bool Maptool::MapConstruction()
{

	m_bConstruction = true;

		if (GetAsyncKeyState(VK_LEFT) & 0x0001)
		{
			if (m_Cursor.m_iX <= 0)
				return false;
			m_Cursor.m_iX -= TILESIZEX;
		}
		else if (GetAsyncKeyState(VK_UP) & 0x0001)
		{
			if (m_Cursor.m_iY <= 0)
				return false;
			m_Cursor.m_iY -= TILESIZEY;
		}
		else if (GetAsyncKeyState(VK_RIGHT) & 0x0001)
		{
			if (m_Cursor.m_iX >= TILESIZEX * 12)
				return false;
			m_Cursor.m_iX += TILESIZEX;
		}
		else if (GetAsyncKeyState(VK_DOWN) & 0x0001)
		{
			if (m_Cursor.m_iY >= TILESIZEY * 12)
				return false;
			m_Cursor.m_iY += TILESIZEY;
		}
		else if (GetAsyncKeyState('Z') & 0x0001)
		{
			Create();

		}
		 if (GetAsyncKeyState(VK_RETURN) & 0x0001)
		{
			 Save();
			 m_bConstruction = false;

			 return true;
		}

		
	return false;
}

void Maptool::Effect(HDC hdc)
{
	m_dwCurTime = GetTickCount();
	m_fDeltaTime = (m_dwCurTime - m_dwLastTime) / 1000.0f;

	static bool check = false;
	static float TextTime = 0.0f;
	static int tmptype = OBJE_EXPLOSION00;

	if (m_fDeltaTime > 0.1f)
	{
		if (check)
		{
			tmptype--;
			if (tmptype < OBJE_EXPLOSION00)
			{
				tmptype = OBJE_EXPLOSION00;
				check = false;
				m_Map[m_iCollisionIndex]->eTileID = MAP_ENDFALGE;
				m_iCollisionIndex = -1;
			}
		}
		else
		{
			tmptype++;
			if (tmptype >= OBJE_EXPLOSION04)
			{

				check = true;
			}
		}
		m_dwLastTime = m_dwCurTime;
	}
	if (m_iCollisionIndex > -1)
	{
		SIZE size = BitMapManager::GetSingleton()->GetImg((OBJECT)tmptype)->GetSize();
		BitMapManager::GetSingleton()->GetImg((OBJECT)tmptype)->Draw(hdc, m_Map[m_iCollisionIndex]->fX - size.cx * 0.5 + STARTX, m_Map[m_iCollisionIndex]->fY - size.cy* 0.5 + STARTY, 1, 1);
	}
}


Maptool::~Maptool()
{

}
