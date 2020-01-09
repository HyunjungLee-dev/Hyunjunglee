#include"ArrayList.h"
#include<iostream>
using namespace std;

int main(void)
{
	List list;
	LData data;
	int multi = 1;
	int Num[5];

	/*조건 1. 리스트를 생성 및 초기화 한 다음, 5개를 입력 받는다 . 입력 받은 수를 리스트에 저장한다.*/
	ListInit(&list);
	cout << "5개의 수를 입력하시오 : ";
	cin >> Num[0] >> Num[1] >> Num[2]>>Num[3]>>Num[4];
	for (int i = 0; i < 5; i++)
	{
		Linsert(&list, Num[i]);
	}
	/*조건 2. 리스트에 저장된 값을 순차적으로 참조하여 짝수의 곱을 출력한다.*/
	if (LFirst(&list, &data))
	{
		if(data % 2 == 0)
			multi *= data;
		while (LNext(&list, &data))
			if (data % 2 == 0)
				multi *= data;
	}
	cout << "List에 저장된 값 중 짝수의 곱 : " << multi <<endl;
	/*조건 3. 리스트에 저장된 값들 중 홀수에 해당하는 값을 모두 삭제한다.*/
	cout << "삭제 된 홀수 값 : ";
	if(LFirst(&list, &data))
	{
		if (data % 2 != 0)
		{
			cout << data << " ";
			LRemove(&list);
		}
	}
	while (LNext(&list, &data))
	{
		if (data % 2 != 0)
		{
			cout << data << " ";
			LRemove(&list);
		}
	}
	cout << endl;
	/*조건 4. 마지막으로 리스트에 저장된 데이터를 순서대로 출력한다.*/
	if (LFirst(&list, &data))
	{
		cout <<"List에 저장된 데이터 : "<< data << " ";
		while (LNext(&list, &data))
			cout << data << " ";
	}
	cout << endl;
	
}