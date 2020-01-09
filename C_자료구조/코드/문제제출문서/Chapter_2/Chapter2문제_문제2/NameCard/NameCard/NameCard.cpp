#include "NameCard.h"

NameCard * MakeNameCard(const char * name, const char * phone)
{
	NameCard* NCard;
	NCard = (NameCard*)malloc(sizeof(NameCard));
	strcpy(NCard->name, name);
	strcpy(NCard->phone, phone);

	return NCard;
}

void ShowNameCardInfo(NameCard * pcard)
{
	string str;
	cout << pcard->name << " : "<< pcard->phone<<endl;
}

int NameCompare(NameCard * pcard, const char * name)
{
	return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard * pcard, const char * phone)
{
	strcpy(pcard->phone, phone);
}