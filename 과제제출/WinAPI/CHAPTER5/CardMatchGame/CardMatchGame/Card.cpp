#include "Card.h"



Card::Card()
{
	m_eCardState = CARDSTATE_CLOSE;
}

void Card::SetImg(IMG_TYP type)
{
	m_pBitmap[CARDSTATE_OPEN] = BitmapManager::GetSingleton()->GetImg(type);
	m_pBitmap[CARDSTATE_MATCH] = BitmapManager::GetSingleton()->GetImg(type);
	m_pBitmap[CARDSTATE_CLOSE] = BitmapManager::GetSingleton()->GetImg(IMG_TYP_BLACK);
	m_eImgtyp = type;
}


void Card::SetPos(int x, int y, float spX, float spY)
{
	m_ix = x;
	m_iy = y;
	m_fSpX = spX;
	m_fSpY = spY;
	m_CardRect.left = x;
	m_CardRect.top = y;
	m_CardRect.right = m_CardRect.left + m_pBitmap[m_eCardState]->Getsize().cx * m_fSpX;
	m_CardRect.bottom = m_CardRect.top + m_pBitmap[m_eCardState]->Getsize().cy * m_fSpY;
}

void Card::DrawCard(HDC hdc)
{
	m_pBitmap[m_eCardState]->Draw(hdc, m_ix, m_iy, m_fSpX, m_fSpY);
}

bool Card::CardCheck(POINT pos)
{
	if (PtInRect(&m_CardRect, pos) == true)
		return true;
	else
		return false;

}

void Card::SetState(CARDSTATE state)
{
	m_eCardState = state;
}

Card::~Card()
{
}
