#pragma once
#include"Draw.h"

enum BLOCKTYPE
{
	BLOCKTYPE_NONE,
	BLOCKTYPE_FLAG,
	BLOCKTYPE_QMARK,
	BLOCKTYPE_MINE,
};

class Block		  
{
protected:
	Draw Bdraw;
public:
   virtual void DrawBlock(bool benter)= 0;
	virtual void SetBlock(int x, int y) =0;
	virtual inline BLOCKTYPE GetType() = 0;
	virtual inline int GetX() = 0;
	virtual inline int GetY() = 0;

	Block();
	virtual ~Block();
};

class None : public Block
{
private:
	int m_ix;
	int m_iy;
	BLOCKTYPE m_eblockType;
public:
	virtual void DrawBlock(bool benter);
	virtual void SetBlock(int x, int y);
	virtual inline BLOCKTYPE GetType() {	return m_eblockType;	}
	virtual inline int GetX() {	return m_ix;	}
	virtual inline int GetY() {	return m_iy;	}

	None();
	virtual ~None();
};

class Flag : public Block
{
private:
	int m_ix; 
	int m_iy;
	BLOCKTYPE m_eblockType;
public:
	virtual void DrawBlock(bool benter);
	virtual void SetBlock(int x, int y);
	virtual inline BLOCKTYPE GetType() { return m_eblockType; }
	virtual inline int GetX() { return m_ix; }
	virtual inline int GetY() { return m_iy; }

	Flag();
	virtual ~Flag();
};

class Mine : public Block
{
private:
	int m_ix;
	int m_iy;
	BLOCKTYPE m_eblockType;
public:
	virtual void DrawBlock(bool benter);
	virtual void SetBlock(int x, int y);
	virtual inline BLOCKTYPE GetType() { return m_eblockType; }
	virtual inline int GetX() { return m_ix; }
	virtual inline int GetY() { return m_iy; }

	Mine();
	virtual ~Mine();
};


