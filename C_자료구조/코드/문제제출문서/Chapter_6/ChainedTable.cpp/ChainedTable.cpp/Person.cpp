#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Person.h"

int GetSSN(Person * p)
{
	return p->ssn;
}

void ShowPerInfo(Person * p)
{
	if (p == NULL)
		printf("등록된 회원이 없습니다.");
	else
	{
		//printf("회원번호: %d \n", p->ssn);
		printf("이름: %s \n", p->name);
		printf("휴대폰번호: %s \n\n", p->number);
	}
}

Person * MakePersonData(int ssn, const char * name, const char *  num)
{
	Person * newP = (Person*)malloc(sizeof(Person));

	newP->ssn = ssn;
	strcpy(newP->name, name);
	strcpy(newP->number, num);
	return newP;
}
