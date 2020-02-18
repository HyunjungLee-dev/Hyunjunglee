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

	// 입력
	na = MakeAnimalData(11250005, "콩이", "말티즈");
	TBLInsert(&tb, GetSSN(na), na);

	na = MakeAnimalData(12360083, "초코", "푸들");
	TBLInsert(&tb, GetSSN(na), na);

	// 탐색
	sa = TBLSearch(&tb, 11250005);
	ShowAniInfo(sa);

	sa = TBLSearch(&tb, 12360083);
	ShowAniInfo(sa);


	//삭제
	da = TBLDelete(&tb, 11250005);
	if (da != NULL)
		free(da);

	da = TBLDelete(&tb, 12360083);
	if (da != NULL)
		free(da);



	return 0;

}