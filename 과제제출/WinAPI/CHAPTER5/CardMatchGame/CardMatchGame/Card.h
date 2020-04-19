#pragma once
#include"BitmapManager.h"

class Card
{
private:
	int m_ix;
	int m_iy;
	float   m_fSpX;
	float   m_fSpY;
	CARDSTATE m_eCardState;
	IMG_TYP m_eImgtyp;
	Bitmap* m_pBitmap[CARDSTATE_END];
	RECT m_CardRect;
public:
	void SetImg(IMG_TYP type);
	void SetPos(int x, int y, float spx = 0.5, float spy = 0.5);
	bool CardCheck(POINT pos);
	void DrawCard(HDC hdc);
	void SetState(CARDSTATE state);
	CARDSTATE GetCardState() {	return m_eCardState;}
	RECT GetCardRect() { return m_CardRect; }
	IMG_TYP GetCardImg() { return m_eImgtyp; }
	Card();
	~Card();
};
