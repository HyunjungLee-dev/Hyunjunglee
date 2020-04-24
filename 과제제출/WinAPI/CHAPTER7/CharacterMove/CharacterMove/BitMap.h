#pragma once
#include<Windows.h>
class BitMap
{
private:
	HDC hMemDC;
	HBITMAP hImage, hOldBitmap;
	SIZE    m_bitsize;
public:
	void Init(HDC hdc);
	void Draw(HDC hdc,int nX, int nY, int nFX,int nFH );
	BitMap();
	~BitMap();
};

