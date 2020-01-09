#include"ArrayList.h"
#include<iostream>
using namespace std;

int main(void)
{
	List list;
	LData data;
	int Sum = 0;

	/*조건 1*/
	ListInit(&list);
	for (int i = 0; i < 9; i++)
	{
		Linsert(&list, i);
	}
	/*조건2*/
	if (LFirst(&list, &data))
	{
		Sum += data;
		while (LNext(&list, &data))
			Sum += data;
	}
	cout << "List에 저장된 값의 합 : " << Sum<<endl;
	/*조건3_2의 배수와 3의 배수 삭제*/
	if(LFirst(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			LRemove(&list);
	}
	while (LNext(&list, &data))
	{
		if (data % 2 == 0 || data % 3 == 0)
			 LRemove(&list);
	}
	/*조건4*/
	if (LFirst(&list, &data))
	{
		cout <<"List에 저장된 데이터 : "<< data << " ";
		while (LNext(&list, &data))
			cout << data << " ";
	}
	cout << endl;
	
}