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
	cout << pcard->name << " : ";
	str = pcard->phone;
	str.insert(str.length() - 4, 1, '-');
	str.insert(str.length() - 9, 1, '-');
	cout << str << endl;

}

int NameCompare(NameCard * pcard, const char * name)
{
	return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard * pcard, const char * phone)
{
	strcpy(pcard->phone, phone);
}