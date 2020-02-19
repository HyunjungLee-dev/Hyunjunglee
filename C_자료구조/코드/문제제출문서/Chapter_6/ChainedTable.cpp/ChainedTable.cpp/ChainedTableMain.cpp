#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include<windows.h>
#include<conio.h>
#include "Person.h"
#include "Table.h"

int MyHashFunc(int k)
{
	return k % 100;
}

void MakeNumber(Table * t)
{
	char  UserNum[STR_LEN] = {'\0'};
	char tmp[STR_LEN] = { '\0' };
	char PNumber[STR_LEN];
	char Name[STR_LEN];
	Person * np;

	 
	srand(time(NULL));
	for (int i = 0; i < 5; i++)
	{
		int random = rand() % 10;
		itoa(random, tmp, 10);
		strcat(UserNum, tmp);
	}

	printf("\n�̸� �Է� : ");
	scanf("%s", &Name);

	printf("�޴��� ��ȣ �Է� : ");
	scanf("%s", &PNumber);

	printf("ȸ�� ��ȣ�� ���� �Ǿ����ϴ� :  %s \n \n", UserNum);

	np = MakePersonData(atoi(UserNum), Name, PNumber);
	TBLInsert(t, GetSSN(np), np);

}


int main(void)
{
	Table myTbl;
	Person * sp;
	Person * rp;

	int Select = 0;
	int num = 0;


	TBLInit(&myTbl, MyHashFunc);

	while (Select >= 0)
	{
		system("cls");

		printf("1. ȸ�����\n");
		printf("2. ȸ�� ���� ��ȸ\n");
		printf("3. ȸ�� ����\n");
		printf("�Է� : ");
		scanf("%d", &Select);


		switch (Select)
		{
		case 1: 
			MakeNumber(&myTbl);
			getch();
			break;
		case 2:
			printf("\n�˻� ȸ����ȣ�� �Է��Ͻÿ� : \n");
			scanf("%d", &num);
			sp = TBLSearch(&myTbl, num);
			ShowPerInfo(sp);
			getch();
			break;
		case 3:
			printf("\n���� ȸ����ȣ�� �Է��Ͻÿ� : \n");
			scanf("%d", &num);
			rp = TBLDelete(&myTbl, num);
			if (rp != NULL)
				free(rp);
			break;
		default:
			break;
		}
	}

	return 0;
}