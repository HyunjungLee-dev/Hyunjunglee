#pragma once
#include<windows.h>
class BitMap
{
private:
	HDC MemDC;
	HBITMAP m_pBitMap;
	HBITMAP m_pBitOld;
	SIZE m_size;
public:
	BitMap();
	void Init(HDC hdc, LPCWSTR FileName);
	void Draw(HDC hdc, int nX, int nY, int nFX, int nFH);
	void Draw(HDC hdc, int nWSrc, int nHSrc);
	~BitMap();
};

