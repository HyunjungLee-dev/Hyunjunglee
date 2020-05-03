#include "Block.h"




Block::Block()
{
}


Block::~Block()
{
}


/*Board Block*/

Light::Light()
{
	m_brdbckType = BOARDBLOCK_LIGHT;
	m_pBitmap = BitmapManager::GetSingleton()->GetBrdBImg(m_brdbckType);
}

void Light::SetPos(int x, int y)
{
	pos.x = x;
	pos.y = y;
	m_brdBckRect.left = x*0.5;
	m_brdBckRect.top = y*0.5;
	m_brdBckRect.right = m_brdBckRect.left + m_pBitmap->GetSize().cx*0.5;
	m_brdBckRect.bottom = m_brdBckRect.top + m_pBitmap->GetSize().cy*0.5;
}

void Light::Draw(HDC hdc)
{
	m_pBitmap->Draw(hdc, pos.x, pos.y);
}

Dark::Dark()
{
	m_brdbckType = BOARDBLOCK_DARK;
	m_pBitmap = BitmapManager::GetSingleton()->GetBrdBImg(m_brdbckType);

}

void Dark::SetPos(int x, int y)
{
	pos.x = x;
	pos.y = y;

	m_brdBckRect.left = x;
	m_brdBckRect.top = y;
	m_brdBckRect.right = m_brdBckRect.left + m_pBitmap->GetSize().cx*0.5;
	m_brdBckRect.bottom = m_brdBckRect.top + m_pBitmap->GetSize().cy*0.5;
}

void Dark::Draw(HDC hdc)
{
	m_pBitmap->Draw(hdc, pos.x, pos.y);
}

/*Select Line*/


Line::Line()
{
	m_brdbckType = BOARDBLOCK_LINE;
	m_pBitmap = BitmapManager::GetSingleton()->GetBrdBImg(m_brdbckType);

}

void Line::SetPos(int x, int y)
{
	pos.x = x;
	pos.y = y;

	m_brdBckRect.left = x;
	m_brdBckRect.top = y;
	m_brdBckRect.right = m_brdBckRect.left + m_pBitmap->GetSize().cx*0.5;
	m_brdBckRect.bottom = m_brdBckRect.top + m_pBitmap->GetSize().cy*0.5;
}

void Line::Draw(HDC hdc)
{
	m_pBitmap->Draw(hdc, pos.x, pos.y);
}