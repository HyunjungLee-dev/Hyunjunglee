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
		printf("��ϵ� ȸ���� �����ϴ�.");
	else
	{
		//printf("ȸ����ȣ: %d \n", p->ssn);
		printf("�̸�: %s \n", p->name);
		printf("�޴�����ȣ: %s \n\n", p->number);
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
