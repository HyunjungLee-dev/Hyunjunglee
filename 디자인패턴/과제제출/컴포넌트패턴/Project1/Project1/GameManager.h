#pragma once
#include"MapDraw.h"
#include"Character.h"

#define ITEMCOUNT 2

class GameManager
{
	MapDraw m_DrawManager;
	Character chracter;
	Sword sword;
	Shield shield;

	
	void TitleDraw();
	void Item(int x, int y);
	void wrngItems();
public:
	void GameTitleScene();
	GameManager();
	~GameManager();
};

