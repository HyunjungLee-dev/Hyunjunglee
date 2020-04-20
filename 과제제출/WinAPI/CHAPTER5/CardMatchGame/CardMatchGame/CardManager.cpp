#include "CardManager.h"



CardManager::CardManager()
{
	MatchIndexInit();
}

void CardManager::Init()
{
	SetList();
	RandCard();
	SetCardListPos();

}

void CardManager::SetList()
{
	for (int i = 0; i < CARD_MAX; i++)
	{
		Cardlist.push_back(new Card);
	}
}

void CardManager::shuffle(int *data, int size)
{

	int temp = 0;
	for (int i = 0; i < size; i++)
	{
		int randNum = rand() % size;
		temp = data[randNum];
		data[randNum] = data[i];
		data[i] = temp;
	}
}

void CardManager::RandCard()
{
	const int size = CARD_MAX;
	int arrCardNum[size];
	for (int i = 0; i < size; i++)
	{
		arrCardNum[i] = i;
	}
	shuffle(arrCardNum, size);

	for (int i = 0; i < size; i++)
	{
		if (arrCardNum[i] >= CARD_MAX * 0.5)
		{
			arrCardNum[i] = arrCardNum[i] - CARD_MAX * 0.5;
		}
		Cardlist[i]->SetImg((IMG_TYP)arrCardNum[i]);
	}

}

void CardManager::SetCardListPos()
{
	for (int i = 0; i < 5; i++)
		Cardlist[i]->SetPos(50 + (100 * i), 40);
	for (int i = 0; i < 5; i++)
		Cardlist[i + 5]->SetPos(50 + (100 * i), 170);
	for (int i = 0; i < 5; i++)
		Cardlist[i + 10]->SetPos(50 + (100 * i), 300);
	for (int i = 0; i < 5; i++)
		Cardlist[i + 15]->SetPos(50 + (100 * i), 430);
}

void CardManager::DrawCardList(HDC hdc)
{
	for (int i = 0; i < CARD_MAX; i++)
	{
		Cardlist[i]->DrawCard(hdc);
	}
}

bool CardManager::AllCardCheck(POINT POS, MATCH count)
{
	for (int i = 0; i < CARD_MAX; i++)
	{
		if (Cardlist[i]->CardCheck(POS) == true)
		{
			if (Cardlist[i]->GetCardState() != CARDSTATE_OPEN)
			{
				Cardlist[i]->SetState(CARDSTATE_MATCH);
				MatchIndex[count] = Cardlist[i];
				return true;
			}
		}
	}
	return false;
}

bool CardManager::MatchCard()
{
	if (MatchIndex[MATCH_FIRST]->GetCardImg() == MatchIndex[MATCH_SECOND]->GetCardImg())
	{
		MatchIndex[MATCH_FIRST]->SetState(CARDSTATE_OPEN);
		MatchIndex[MATCH_SECOND]->SetState(CARDSTATE_OPEN);
		MatchIndexInit();
		return true;
	}
	else
		return false;
}

void CardManager::MatchCardClose()
{
	MatchIndex[MATCH_FIRST]->SetState(CARDSTATE_CLOSE);
	MatchIndex[MATCH_SECOND]->SetState(CARDSTATE_CLOSE);
}


bool CardManager::AllMatchClear()
{
	for (int i = 0; i < CARD_MAX; i++)
	{
		if (Cardlist[i]->GetCardState() == CARDSTATE_CLOSE)
			return false;
	}
	return true;

}

void CardManager::MatchIndexInit()
{
	for(int i = 0; i < MATCH_END; i++)
	{
		MatchIndex[i] = NULL;
	}
}

bool CardManager::MatchNullCheck(MATCH index)
{
	if (MatchIndex[index] != NULL)
		return false;
	else
		return true;
}

CardManager::~CardManager()
{
}
