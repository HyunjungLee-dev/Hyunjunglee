#include "BitMap.h"


BitMap* BitMap::_Singleton = NULL;

BitMap::BitMap()
{
}

void BitMap::Init(HDC hdc)
{
	MemDC[IMG_NONE] = CreateCompatibleDC(hdc);
	m_pBitMap[IMG_NONE] = CreateCompatibleBitmap(hdc, 1024, 768);
	m_pBitOld[IMG_NONE] = (HBITMAP)SelectObject(MemDC[IMG_NONE], m_pBitMap[IMG_NONE]);
	ImgLoad(L"back.bmp", IMG_BACKGROUND);
	ImgLoad(L"image.bmp", IMG_CHARACTER);
}

void BitMap::ImgLoad(LPCWSTR FileName, IMG img)
{
	MemDC[img] = CreateCompatibleDC(MemDC[IMG_NONE]);
	m_pBitMap[img] = (HBITMAP)LoadImage(NULL, FileName, IMAGE_BITMAP, 0, 0
		, LR_CREATEDIBSECTION | LR_DEFAULTSIZE | LR_LOADFROMFILE);
	m_pBitOld[img] = (HBITMAP)SelectObject(MemDC[img], m_pBitMap[img]);

	BITMAP bit;
	GetObject(m_pBitMap[img], sizeof(BITMAP), &bit);
	m_size[img].cx = bit.bmWidth;
	m_size[img].cy = bit.bmHeight;

}

void BitMap::Draw(int nX, int nY, int nFW, int nFH)  //캐릭터
{
	TransparentBlt(MemDC[IMG_NONE], nX, nY, m_size[IMG_CHARACTER].cx / 4, m_size[IMG_CHARACTER].cy / 4,
		MemDC[IMG_CHARACTER], (m_size[IMG_CHARACTER].cx / 4) * nFW, (m_size[IMG_CHARACTER].cy / 4) * nFH, m_size[IMG_CHARACTER].cx / 4, m_size[IMG_CHARACTER].cy / 4, RGB(255, 0, 255));
}

void BitMap::Draw()   //배경
{
	BitBlt(MemDC[IMG_NONE], 0, 0, m_size[IMG_BACKGROUND].cx, m_size[IMG_BACKGROUND].cy, MemDC[IMG_BACKGROUND], 0, 0, SRCCOPY);
}

void BitMap::Draw(HDC hdc) //전체
{
	BitBlt(hdc, 0, 0, 1024, 768, MemDC[IMG_NONE], 0, 0, SRCCOPY);
}


BitMap::~BitMap()
{
}
