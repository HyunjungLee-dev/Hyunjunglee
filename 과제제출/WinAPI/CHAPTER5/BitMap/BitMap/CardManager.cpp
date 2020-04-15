#include "CardManager.h"



CardManager::CardManager()
{
}

void CardManager::Init(HWND hWnd, HINSTANCE hInst)
{
	HDC hdc = GetDC(hWnd);
	for (int i = 0; i < CARD_MAX; i++)
	{
		Card* m_Cardtmp = new Card;
		Cardlist.push_back(m_Cardtmp);
		Cardlist[i]->Init(hdc, hInst, (CARDTYPE)i);
	}
	SetCardListPos();
	ReleaseDC(hWnd, hdc);
}

void CardManager::SetCardListPos()
{
	for (int i = 0; i < 3; i++)
		Cardlist[i]->SetPos(50 + (100 * i), 10);
	for (int i = 0; i < 3; i++)
		Cardlist[i + 3]->SetPos(50 + (100 * i), 140);
	for (int i = 0; i < 3; i++)
		Cardlist[i + 6]->SetPos(50 + (100 * i), 270);
}

void CardManager::DrawCardList(HDC hdc)
{
	for (int i = 0; i < CARD_MAX; i++)
	{
		Cardlist[i]->DrawCard(hdc);
	}
}

int CardManager::AllCardCheck(POINT POS)
{
	for (int i = 0; i < CARD_MAX; i++)
	{
		if (Cardlist[i]->cardCheck(POS) == true)
			return i;
	}
	return -1;
}

string CardManager::CardName(int typenum)
{
	CARDTYPE type = Cardlist[typenum]->GetType();
	if (type == CARDTYPE_DOG)
		return "������";
	else if (type == CARDTYPE_TIGER)
		return "ȣ����";
	else if (type == CARDTYPE_DUCK)
		return "����";
	else if (type == CARDTYPE_ELEPHANT)
		return "�ڳ���";
	else if (type == CARDTYPE_COW)
		return "��";
	else if (type == CARDTYPE_HORSE)
		return "��";
	else if (type == CARDTYPE_CAT)
		return "�����";
	else if (type == CARDTYPE_MONKEY)
		return "������";
	else if (type == CARDTYPE_FROG)
		return "������";
	else if (type == CARDTYPE_CHICKEN)
		return "��";

}


CardManager::~CardManager()
{
}
