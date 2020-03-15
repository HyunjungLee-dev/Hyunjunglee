#include"GameManager.h"

void main()
{
	GameManager gm;
	gm.GameTitleScene();
}

// RPG 같은 게임에서 캐릭터가 착용하는 아이템의 교체에 따라 능력치 갱신 되는 것 구현
// Character Info : 캐릭터 정보 확인과 착용 아이템 해제 가능
// inventory : 캐릭터가 가진 아이템, 2개 추가 되어 있음
// Component (Item) , Leaf(Shield,Sword) , Composite (Character)