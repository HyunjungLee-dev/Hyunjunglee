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
		printf("등록 되지 않은 동물입니다.");
	else
	{
		printf("동물등록번호: %d \n", a->ssn);
		printf("이름: %s \n", a->name);
		printf("품종: %s \n\n", a->breed);
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