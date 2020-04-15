#include "BitMap.h"



BitMap::BitMap()
{
}

void BitMap::Init(HDC hdc, HINSTANCE hInst,int ResID)
{
	MemDC = CreateCompatibleDC(hdc);
	m_myBitmap = LoadBitmap(hInst, MAKEINTRESOURCE(ResID));
	m_oldBitmap = (HBITMAP)SelectObject(MemDC, m_myBitmap);


	BITMAP bm;
	GetObject(m_myBitmap, sizeof(BITMAP), &bm);
	m_size.cx = bm.bmWidth;
	m_size.cy = bm.bmHeight;
}

void BitMap::Draw(HDC hdc, int x, int y, float sx, float sy)
{
	StretchBlt(hdc, x, y, m_size.cx* sx, m_size.cy * sy, MemDC, 0, 0, 	m_size.cx, m_size.cy, SRCCOPY);
}


BitMap::~BitMap()
{
	SelectObject(MemDC, m_oldBitmap);
	DeleteObject(m_myBitmap);
	DeleteDC(MemDC);
}
