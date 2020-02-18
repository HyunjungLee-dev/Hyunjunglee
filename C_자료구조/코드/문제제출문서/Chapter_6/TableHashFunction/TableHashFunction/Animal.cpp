#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Animal.h"

int GetSSN(Animal* a)
{
	return a->ssn;;
}

void ShowAniInfo(Animal* a)
{
	if (a == NULL)
		printf("��� ���� ���� �����Դϴ�.");
	else
	{
		printf("������Ϲ�ȣ: %d \n", a->ssn);
		printf("�̸�: %s \n", a->name);
		printf("ǰ��: %s \n\n", a->breed);
	}
}

Animal* MakeAnimalData(int ssn, const char* name, const char* breed)
{
	Animal* newA = (Animal*)malloc(sizeof(Animal));
	newA->ssn = ssn;
	strcpy(newA->name, name);
	strcpy(newA->breed, breed);

	return newA;
}