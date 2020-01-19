#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include"CLinkedList.h"
#include"Employee.h"


Employee * pEmp;
void EmployeeInfo(Employee * emp);
Employee * WhoDutyEmployee(List * plist, const char * name, int day);

int main(void)
{
	List list;
	ListInit(&list);

	/* 직원 정보 등록*/
	pEmp = (Employee*)malloc(sizeof(Employee));
	strcpy(pEmp->name, "이수정");
	pEmp->empIDnum = 1234;
	LInsert(&list, pEmp);

	pEmp = (Employee*)malloc(sizeof(Employee));
	strcpy(pEmp->name, "김하나");
	pEmp->empIDnum = 5678;
	LInsert(&list, pEmp);

	pEmp = (Employee*)malloc(sizeof(Employee));
	strcpy(pEmp->name, "도하나");
	pEmp->empIDnum = 9012;
	LInsert(&list, pEmp);

	pEmp = (Employee*)malloc(sizeof(Employee));
	strcpy(pEmp->name, "고하늘");
	pEmp->empIDnum = 3456;
	LInsert(&list, pEmp);

	// 전체 데이터 1회 출력 ///////
	printf("직원 목록  \n");
	if (LFirst(&list, &pEmp))
	{
		EmployeeInfo(pEmp);

		for (int i = 0; i < LCount(&list) - 1; i++)
		{
			if (LNext(&list, &pEmp))
				EmployeeInfo(pEmp);
		}
	}

	/*당직자 출력*/
	printf("\n당직자 출력\n");
	pEmp = WhoDutyEmployee(&list, "이수정", 7);
	EmployeeInfo(pEmp);

	/*삭제*/
	if (LCount(&list) != 0)
	{
		LFirst(&list, &pEmp);
		for (int i = 0; i < LCount(&list) - 1; i++)
		{
			LNext(&list, &pEmp);
				LRemove(&list);
		}
	}

}

Employee * WhoDutyEmployee(List * plist, const char * name, int day)
{
	int i;
	int EmpNum = LCount(plist);
	Employee *remp;

	if (EmpNum != 0)
	{
		LFirst(plist, &remp);
		if (strcmp(remp->name, name) != 0)
		{
			for (i = 0; i < EmpNum - 1; i++)
			{
				LNext(plist, &remp);
				if (strcmp(remp->name, name) == 0)
					break;
			}
			if (i >= EmpNum - 1)
				return NULL;
		}
	}
	for (i = 0; i < day; i++)
	{
		LNext(plist, &remp);
	}
	return remp;
}

void EmployeeInfo(Employee * emp)
{
	printf("직원 이름 : %s ", emp->name);
	printf("직원 번호 : %d \n", emp->empIDnum);
	
}