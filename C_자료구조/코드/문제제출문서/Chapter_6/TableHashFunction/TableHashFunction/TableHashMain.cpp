#include<stdio.h>
#include<stdlib.h>
#include"Animal.h"
#include"Table.h"

int HashF(int k)
{
	return k % 100;
}

int main(void)
{
	Table tb;
	Animal * na;
	Animal * sa;
	Animal * da;

	TBLInit(&tb, HashF);

	// �Է�
	na = MakeAnimalData(11250005, "����", "��Ƽ��");
	TBLInsert(&tb, GetSSN(na), na);

	na = MakeAnimalData(12360083, "����", "Ǫ��");
	TBLInsert(&tb, GetSSN(na), na);

	// Ž��
	sa = TBLSearch(&tb, 11250005);
	ShowAniInfo(sa);

	sa = TBLSearch(&tb, 12360083);
	ShowAniInfo(sa);


	//����
	da = TBLDelete(&tb, 11250005);
	if (da != NULL)
		free(da);

	da = TBLDelete(&tb, 12360083);
	if (da != NULL)
		free(da);



	return 0;

}