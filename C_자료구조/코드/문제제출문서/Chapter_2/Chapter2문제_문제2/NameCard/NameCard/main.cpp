#include"ArrayList.h"
#include"NameCard.h"

int main(void)
{
	List list;
	NameCard* NCard;

	ListInit(&list);

	/*총 3명의 전화번호 정보를, ArrayList에 저장한다. */

		NCard = MakeNameCard("고하늘", "010-1234-4567");
		Linsert(&list, NCard);

		NCard = MakeNameCard("박성순", "010-5588-9966");
		Linsert(&list, NCard);

		NCard = MakeNameCard("김이분", "010-7755-3366");
		Linsert(&list, NCard);
	
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
			ChangePhoneNum(NCard, "010-2323-4545");
		}
		else
		{
			while (LNext(&list, &NCard))
			{
				if (!NameCompare(NCard, "김이분"))
				{
					ChangePhoneNum(NCard, "010-2323-4545");
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
	

