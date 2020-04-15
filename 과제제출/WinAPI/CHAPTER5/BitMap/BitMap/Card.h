#pragma once
#include"BitMap.h"
#include<string>
using namespace std;

enum CARDTYPE
{
	CARDTYPE_DOG = 0,
	CARDTYPE_TIGER,
	CARDTYPE_DUCK,
	CARDTYPE_ELEPHANT,
	CARDTYPE_COW,
	CARDTYPE_HORSE,
	CARDTYPE_CAT,
	CARDTYPE_MONKEY,
	CARDTYPE_FROG,
	CARDTYPE_CHICKEN,
};


class Card
{
private:
	int m_ix;
	int m_iy;
	float   m_fSpX;
	float   m_fSpY;
	BitMap* m_pBitMap;
	CARDTYPE m_eCardType;
	RECT m_CardRect;
public:
	void Init(HDC hdc, HINSTANCE hInst, CARDTYPE type);
	void SetPos(int x, int y, float spX = 0.5 , float spY =0.5);
	bool cardCheck(POINT pos);
	void DrawCard(HDC hdc);
	inline CARDTYPE GetType() {
		return m_eCardType
			;
	}
	Card();
	~Card();
};

