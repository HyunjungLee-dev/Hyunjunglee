#pragma once
#include"Card.h"


class CardManager
{
	vector<Card*>Cardlist;
	Card* MatchIndex[MATCH_END];
public:
	void Init();
	void SetList();
	void RandCard();
	void SetCardListPos();
	void shuffle(int *data, int size);
	void DrawCardList(HDC hdc);
	bool AllCardCheck(POINT pos, MATCH count);
	bool MatchCard();
	void MatchCardClose();
	bool AllMatchClear();
	void MatchIndexInit();
	bool MatchNullCheck(MATCH index);
	Card* GetMatchIndex(MATCH index) { return MatchIndex[index]; }
	CardManager();
	~CardManager();
};

