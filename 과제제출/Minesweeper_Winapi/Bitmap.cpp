#include "Bitmap.h"



Bitmap::Bitmap()
{
}

void Bitmap::Init(HDC hdc,int x, int y) // back buffer
{
	MemDC = CreateCompatibleDC(hdc);
	m_BitMap = CreateCompatibleBitmap(hdc, x, y);
	m_OldBitMap = (HBITMAP)SelectObject(MemDC, m_BitMap);

	BITMAP bit;
	GetObject(m_BitMap, sizeof(BITMAP), &bit);
	m_size.cx = bit.bmWidth;
	m_size.cy = bit.bmHeight;
}

void Bitmap::ImgLoad(HDC hdc, LPCWSTR FileName) 
{
	MemDC = CreateCompatibleDC(hdc);
	m_BitMap = (HBITMAP)LoadImage(NULL, FileName, IMAGE_BITMAP, 0, 0
		, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_OldBitMap = (HBITMAP)SelectObject(MemDC, m_BitMap);

	BITMAP bit;
	GetObject(m_BitMap, sizeof(BITMAP), &bit);
	m_size.cx = bit.bmWidth;
	m_size.cy = bit.bmHeight;
}


void Bitmap::Draw(HDC hdc, int nX, int nY) //ÀüÃ¼
{
	BitBlt(hdc, nX, nY, m_size.cx, m_size.cy, MemDC, 0, 0, SRCCOPY);
}

void Bitmap::Draw(HDC hdc, int nX, int nY, int w,int h) 
{
	SetStretchBltMode(hdc,COLORONCOLOR);
	StretchBlt(hdc, nX, nY,w,h, MemDC, 0, 0, m_size.cx, m_size.cy, SRCCOPY);
}


void Bitmap::Release()
{
	SelectObject(MemDC, m_OldBitMap);
	DeleteObject(m_BitMap);
	DeleteDC(MemDC);
}


Bitmap::~Bitmap()
{
}
