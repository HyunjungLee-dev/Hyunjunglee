#pragma once
#include"BitmapManager.h"



class Piece
{
protected:
	POINT pos;
	RECT m_PieceRect;
	Bitmap* m_pBitmap;
	PIECE m_ePieceType;
	vector<POINT> MoveRange;
	vector<POINT> MovableRange;
	COLOR m_eColor;
public:
	void SetPos(int x, int y) ;
	void Draw(HDC hdc) ; 
	POINT GetPos() { return pos; }
	RECT GetRect() { return m_PieceRect; }
	vector<POINT> GetRange(){ return MovableRange; }
	COLOR GetColor() { return m_eColor; }
	POINT RangePoint(int x, int y);
	PIECE GetPieceType() {return m_ePieceType;}
	void RangelengthWidth(vector<Piece*> v);
	void RangediagonalLine(vector<Piece* > v);
	virtual void SetImgColor(COLOR color) = 0;
	virtual void SetMoveRange(vector<Piece*> v) = 0;
	virtual void SetMovableRange(vector<Piece*> v ) = 0;
	Piece();
	virtual ~Piece();
};

/*Piece*/	 

class King : public Piece
{
public:
	virtual void SetImgColor(COLOR color);
	virtual void SetMoveRange(vector<Piece*> v);
	virtual void SetMovableRange(vector<Piece*> v);
	King();
	virtual ~King() {};

};

class Queen : public Piece
{
public:
	virtual void SetImgColor(COLOR color);
	virtual void SetMoveRange(vector<Piece*> v);
	virtual void SetMovableRange(vector<Piece*> v);
	Queen();
	virtual ~Queen() {};

};

class Rook : public Piece
{
public:
	virtual void SetImgColor(COLOR color);
	virtual void SetMoveRange(vector<Piece*> v);
	virtual void SetMovableRange(vector<Piece*> v);
	Rook();
	virtual ~Rook() {};
};

class Bishop : public Piece
{
public:
	virtual void SetImgColor(COLOR color);
	virtual void SetMoveRange(vector<Piece*> v);
	virtual void SetMovableRange(vector<Piece*> v);
	Bishop();
	virtual ~Bishop() {};
};

class Knight : public Piece
{
public:
	virtual void SetImgColor(COLOR color);
	virtual void SetMoveRange(vector<Piece*> v);
	virtual void SetMovableRange(vector<Piece*> v);
	Knight();
	virtual ~Knight() {};
};

class Pawn : public Piece
{
public:
	bool FirstCheck();
	virtual void SetImgColor(COLOR color);
	virtual void SetMoveRange(vector<Piece*> v);
	virtual void SetMovableRange(vector<Piece*> v);
	Pawn();
	virtual ~Pawn() {};
};