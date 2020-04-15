#include "Card.h"



Card::Card()
{
	m_pBitMap = new BitMap;
}

void Card::Init(HDC hdc, HINSTANCE hInst, CARDTYPE type)
{
	m_eCardType = type;
	m_pBitMap->Init(hdc, hInst, type + 101);
}

void Card::SetPos(int x, int y, float spX, float spY)
{
	m_ix = x;
	m_iy = y;
	m_fSpX = spX;
	m_fSpY = spY;
	m_CardRect.left = x;
	m_CardRect.top = y;
	m_CardRect.right = m_CardRect.left + m_pBitMap->Getsize().cx * m_fSpX;
	m_CardRect.bottom = m_CardRect.top + m_pBitMap->Getsize().cy * m_fSpY;
}

void Card::DrawCard(HDC hdc)
{
	m_pBitMap->Draw(hdc, m_ix, m_iy, m_fSpX, m_fSpY);
}

bool Card::cardCheck(POINT pos)
{
	// 영역 내에 점이 위치해있다면 true 아니면 false
	if (PtInRect(&m_CardRect, pos) == true)
		return true;
	else
		return false;

}

Card::~Card()
{
	delete m_pBitMap;
}
