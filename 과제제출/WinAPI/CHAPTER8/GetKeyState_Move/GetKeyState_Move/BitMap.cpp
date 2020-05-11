#include "BitMap.h"



BitMap::BitMap()
{
}

void BitMap::Init(HDC hdc, LPCWSTR FileName)
{
	MemDC = CreateCompatibleDC(hdc);

	m_pBitMap = (HBITMAP)LoadImage(NULL, FileName, IMAGE_BITMAP, 0, 0
		, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);

	m_pBitOld = (HBITMAP)SelectObject(MemDC, m_pBitMap);

	BITMAP bit;
	GetObject(m_pBitMap, sizeof(BITMAP), &bit);
	m_size.cx = bit.bmWidth;
	m_size.cy = bit.bmHeight;

}

void BitMap::Draw(HDC hdc, int nX, int nY, int nFW, int nFH)
{
	TransparentBlt(hdc, nX, nY, m_size.cx / 4, m_size.cy / 4,
		MemDC, (m_size.cx / 4) * nFW, (m_size.cy / 4) * nFH, m_size.cx / 4, m_size.cy / 4, RGB(255, 0, 255));
}

void BitMap::Draw(HDC hdc, int nWSrc, int nHSrc)
{
	StretchBlt(hdc, 0, 0, m_size.cx, m_size.cy, MemDC, 0, 0, nWSrc, nHSrc, SRCCOPY);
}


BitMap::~BitMap()
{
}
