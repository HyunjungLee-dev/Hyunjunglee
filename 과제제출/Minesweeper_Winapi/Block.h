#pragma once
#include"BitmapManager.h"

class Block	
{
protected:
	POS m_pos;
	IMG m_eblockType;
	RECT m_blockRect;
	bool m_bClick;
public:
	void Setpos(int x, int y);
	void SetRect();
	virtual void DrawBlock(HDC hdc) = 0;
	IMG GetType() { return m_eblockType; }
	POS GetPos() { return m_pos; }
	RECT GetRct() { return m_blockRect; }
	bool GetClick() { return m_bClick; }
	void SetClick(bool click) { m_bClick = click; }
	Block();
	virtual ~Block();
};

class None : public Block
{
public:
	virtual void DrawBlock(HDC hdc);


	None() { m_eblockType = IMG_BLOCK; }
	virtual ~None() {};
};


class Number : public Block
{
public:
	virtual void DrawBlock(HDC hdc);

	Number() {};
	Number(IMG type) { m_eblockType = (IMG)(type + IMG_BLOCK_START); }
	virtual ~Number() {};
};

class Flag : public Block
{
public:
	virtual void DrawBlock(HDC hdc);


	Flag() { m_eblockType = IMG_FLAG; }
	virtual ~Flag() {};
};

class Mine : public Block
{
public:
	virtual void DrawBlock(HDC hdc);


	Mine() { m_eblockType = IMG_MINE; }
	virtual ~Mine() {};
};


