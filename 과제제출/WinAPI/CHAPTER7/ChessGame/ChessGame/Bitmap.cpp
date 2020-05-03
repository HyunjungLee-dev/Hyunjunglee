#include "BitMap.h"



Bitmap::Bitmap()
{
}

void Bitmap::Init(HDC hdc, LPCWSTR FileName)
{
	MemDC = CreateCompatibleDC(hdc);

	m_BitMap = (HBITMAP)LoadImage(NULL, FileName, IMAGE_BITMAP, 0, 0
		, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);

	m_OldBitMap = (HBITMAP)SelectObject(MemDC, m_BitMap);

	BITMAP BitMap_Info;
	GetObject(m_BitMap, sizeof(BitMap_Info), &BitMap_Info);
	m_size.cx = BitMap_Info.bmWidth;
	m_size.cy = BitMap_Info.bmHeight;
}

void Bitmap::Draw(HDC hdc, int nX, int nY)
{
	TransparentBlt(hdc, nX*0.5, nY*0.5, m_size.cx*0.5, m_size.cy*0.5,
		MemDC, 0, 0, m_size.cx , m_size.cy, RGB(255, 0, 255));
}

Bitmap::~Bitmap()
{
	SelectObject(MemDC, m_OldBitMap);
	DeleteObject(m_BitMap);
	DeleteDC(MemDC);
}
