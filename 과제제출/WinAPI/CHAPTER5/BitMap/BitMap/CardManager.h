#pragma once
#include"Card.h"
#include <vector>
#define CARD_MAX 9

class CardManager 
{
	vector<Card*>Cardlist;

public:
	void Init(HWND hWnd, HINSTANCE hInst);
	void SetCardListPos();
	void DrawCardList(HDC hdc);
	int AllCardCheck(POINT pos);
	string CardName(int typenum);
	CardManager();
	~CardManager();
};

