#pragma once
#include"BitmapManager.h"



class Block
{
public:
	virtual void SetPos(int x, int y) = 0;// 좌표
	virtual void Draw(HDC hdc) = 0; // 이미지 그리기
	Block();
	virtual ~Block();
};

/*Board Block*/

class Light : public Block
{
private:
	POINT pos;
	Bitmap* m_pBitmap;
	BOARDBLOCK m_brdbckType;
	RECT m_brdBckRect;
public:
	virtual void SetPos(int x, int y);
	virtual void Draw(HDC hdc);
	Light();
	virtual ~Light() {};
};

class Dark : public  Block
{
private:
	POINT pos;
	Bitmap* m_pBitmap;
	BOARDBLOCK m_brdbckType;
	RECT m_brdBckRect;
public:
	virtual void SetPos(int x, int y);
	virtual void Draw(HDC hdc);
	Dark();
	virtual ~Dark() {};
};

/*Select Line*/

class Line : public Block
{
private:
	POINT pos;
	Bitmap* m_pBitmap;
	BOARDBLOCK m_brdbckType;
	RECT m_brdBckRect;
public:
	virtual void SetPos(int x, int y);
	virtual void Draw(HDC hdc);
	Line();
	virtual ~Line() {};
};

