#include "GameManager.h"



GameManager::GameManager()
{
}

void GameManager::TitleDraw()
{
	m_DrawManager.DrawMidText("☆★ RPG ★☆", WIDTH, HEIGHT* 0.3);
	m_DrawManager.DrawMidText("Character Info", WIDTH, HEIGHT* 0.3 + 3);
	m_DrawManager.DrawMidText("inventory", WIDTH, HEIGHT* 0.3 + 6);
	m_DrawManager.DrawMidText("Game Exit", WIDTH, HEIGHT* 0.3 + 9);
}

void GameManager::Item(int x, int y)
{
	sword.SetPoint("듀란달",10, 5, 3);
	shield.SetPoint("카이트 실드",1, 15, 8);

	sword.View(x,y);
	shield.View(x,y+5);
	
}



void GameManager::wrngItems()
{
	int y = HEIGHT * 0.3;
	int Select;
	while (1)
	{
		m_DrawManager.BoxErase(WIDTH, HEIGHT);
		Item(WIDTH - 20, HEIGHT * 0.3);
		m_DrawManager.DrawMidText("나가기", WIDTH, HEIGHT * 0.65);
		Select = m_DrawManager.MenuSelectCursor(ITEMCOUNT+1, 5, 4, y);
		if (Select == ITEMCOUNT + 1)
			return;
		else
		{
			if (!chracter.GetItemListempty())
			{
				m_DrawManager.BoxErase(WIDTH, HEIGHT);
				m_DrawManager.DrawMidText("이미 착용한 아이템이 있습니다.", WIDTH, HEIGHT * 0.3);
				getch();
				break;
			}
			else
			{
				 if (Select == 1)
					chracter.AddItem(&sword);
				else if (Select == 2)
					chracter.AddItem(&shield);

			}
		}
	}
}

void GameManager::GameTitleScene()
{
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", HEIGHT + 1, WIDTH * 2);
	system(buf);
	m_DrawManager.BoxDraw(0, 0, WIDTH, HEIGHT);
	m_DrawManager.DrawMidText("캐릭터 이름 입력 : ", WIDTH, HEIGHT* 0.5);
	string name;
	cin >> name;
	chracter.SetName(name);
	while (1)
	{
		m_DrawManager.BoxErase(WIDTH, HEIGHT);
		TitleDraw();
		switch (m_DrawManager.MenuSelectCursor(3, 3, (WIDTH - strlen("Character Info") / 2 - 3) / 2, HEIGHT* 0.3 + 3 ))
		{
		case 1:
			m_DrawManager.BoxErase(WIDTH, HEIGHT);
			chracter.View(WIDTH - 15, HEIGHT * 0.4);
			getch();
			break;
		case 2:
			m_DrawManager.BoxErase(WIDTH, HEIGHT);
			wrngItems();
			break;
		case 3:
			return;
		}
	}
}

GameManager::~GameManager()
{
}
