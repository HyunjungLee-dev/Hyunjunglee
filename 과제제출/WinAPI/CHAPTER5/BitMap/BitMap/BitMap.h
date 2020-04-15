#pragma once
#include<Windows.h>
class BitMap
{
private:
	HDC MemDC;
	HBITMAP  m_myBitmap, m_oldBitmap;
	SIZE m_size;
public:
	void Init(HDC hdc, HINSTANCE hInst, int ResID);
	void Draw(HDC hdc, int x, int y, float sx, float sy);
	inline SIZE Getsize() { return m_size; }
	BitMap();
	~BitMap();
};

