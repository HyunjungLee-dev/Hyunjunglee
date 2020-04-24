#include "BitMap.h"



BitMap::BitMap()
{
}

void BitMap::Init(HDC hdc)
{
	hMemDC = CreateCompatibleDC(hdc);

	hImage = (HBITMAP)LoadImage(NULL, TEXT("image.bmp"),
		IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

	hOldBitmap = (HBITMAP)SelectObject(hMemDC, hImage);

	BITMAP bit;
	GetObject(hImage, sizeof(BITMAP), &bit);
	m_bitsize.cx = bit.bmWidth;
	m_bitsize.cy = bit.bmHeight;

}

void BitMap::Draw(HDC hdc,int nX, int nY, int nFW, int nFH)
{
	TransparentBlt(hdc, nX, nY, m_bitsize.cx / 4, m_bitsize.cy / 4,
		hMemDC, (m_bitsize.cx / 4) * nFW, (m_bitsize.cy / 4) * nFH, m_bitsize.cx / 4, m_bitsize.cy / 4, RGB(255, 0, 255));
}

BitMap::~BitMap()
{
	SelectObject(hMemDC, hOldBitmap);
	DeleteObject(hImage);
	DeleteDC(hMemDC);
}
