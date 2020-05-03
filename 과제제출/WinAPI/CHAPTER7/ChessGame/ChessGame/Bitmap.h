#pragma once
#include "Mecro.h"

class Bitmap
{
private:
	HDC     MemDC;
	HBITMAP m_BitMap;
	HBITMAP m_OldBitMap;
	SIZE    m_size;
public:
	void Init(HDC hdc, LPCWSTR FileName);
	void Draw(HDC hdc, int nX, int nY);
	inline SIZE GetSize()
	{
		return m_size;
	}
	Bitmap();
	~Bitmap();
};

