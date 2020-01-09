#include"ArrayList.h"
#include"NameCard.h"

int main(void)
{
	List list;
	NameCard* NCard;
	int Num;
	char name[10], phone[12];

	ListInit(&list);

	/*1. 입력 받은 수만큼의 전화번호 정보를 ArrayList에 저장한다 */


	cout << "몇명을 저장하겠습니까 : " << endl;
	cin >> Num;
	for (int i = 0; i < Num; i++)
	{
		cout << i + 1 << "번째 사람의 이름을 입력해주세요 :  ";
		cin >> name;
		cout << i + 1 << "번째 사람의 번호를 입력해주세요(11자리,- 제외) :   ";
		cin >> phone;
		NCard = MakeNameCard(name, phone);
		Linsert(&list, NCard);
	}
	/*2. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 출력한다.*/
	if (LFirst(&list, &NCard))
	{
		if (!NameCompare(NCard, "고하늘"))
			ShowNameCardInfo(NCard);
		else
		{
			while (LNext(&list, &NCard))
			{
				if (!NameCompare(NCard, "고하늘"))
				{
					ShowNameCardInfo(NCard);
					break;
				}
			}
		}
	}
	/*3. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 전화번호 정보를 변경한다.*/
	if (LFirst(&list, &NCard))
	{
		if (!NameCompare(NCard, "김이분"))
		{
			ChangePhoneNum(NCard, "01023234545");
		}
		else
		{
			while (LNext(&list, &NCard))
			{
				if (!NameCompare(NCard, "김이분"))
				{
					ChangePhoneNum(NCard, "01023234545");
					break;
				}
			}
		}
	}
	/*4. 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 삭제한다.*/
	if (LFirst(&list, &NCard))
	{
		if (!NameCompare(NCard, "박성순"))
		{
			NCard = LRemove(&list);
			free(NCard);
		}
		else
		{
			while (LNext(&list, &NCard))
			{
				if (!NameCompare(NCard, "박성순"))
				{
					NCard = LRemove(&list);
					free(NCard);
					break;
				}
			}
		}
	}
	/*5. 끝으로 남아있는 모든 사람의 전화번호 정보를 출력한다.*/
	cout << "현재 남아있는 전화번호 정보 수 : " << LCount(&list) << endl;
	if (LFirst(&list, &NCard))
	{
			ShowNameCardInfo(NCard);
			while (LNext(&list, &NCard))
			{
					ShowNameCardInfo(NCard);
			}
		
	}
}
	

