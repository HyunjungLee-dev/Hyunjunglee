#include "Minesweeper.h"



Minesweeper::Minesweeper():m_iHeight(0),m_iWidth(0),m_iMineNum(0)
{
}											 

void Minesweeper::Init()
{
	system("cls");
	Gameover = false;
	map = factory->makeMap();
	player.PlayerInit();

	if (m_eType == TYPE_BEGINNER)
	{
		m_iWidth = 9; m_iHeight = 9; m_iMineNum = 10;
	}
	else if (m_eType == TYPE_INTERMEDIATE)
	{
		m_iWidth = 16; m_iHeight = 16; m_iMineNum = 40;
	}
	else if (m_eType == TYPE_ADVANCED)
	{
		m_iWidth = 30; m_iHeight = 16; m_iMineNum = 99;
	}
	else if (m_eType == TYPE_CUSTOM)
	{
		PrintCustom();
	}
	CreateMap();
	PrintMap();
}

void Minesweeper::Tilte()
{
	int Select;

	int x = CONSOLE_W * 0.5;  
	int y = CONSOLE_H * 0.2;// °¡µ¶¼º

	draw.DrawMidText("[Mineswweeper]", x, y);
	draw.DrawMidText("select a difficulty level", x, y+2);
	draw.DrawMidText("1.beginner", x, y+4);
	draw.DrawMidText("2.intermediate", x, y+6);
	draw.DrawMidText("3.advanced", x, y+8);
	draw.DrawMidText("4.user custom", x, y+10);
	draw.DrawMidText("5.exit", x, y + 12);
	draw.DrawMidText("select : ", x, y + 14);
	cin >> Select;
	m_eType = (SELECT_TYPE)Select;

}

void  Minesweeper::CreateMap()
{
	for (int x = 0; x < m_iWidth; x++)
	{
		for (int y = 0; y < m_iHeight; y++)
		{
			Block* block;
			block = factory->makeNone();
			block->SetBlock(x,y);
			map->AddBlock(block);
		}
	}

	for (int i = 0; i < m_iMineNum; i++)
	{
		int randx = rand() % m_iWidth;
		int randy = rand() % m_iHeight;
		Block* block;
		block = factory->makeMine();
		block->SetBlock(randx, randy);
		map->ChageBlock(block);
	}
}

void Minesweeper::PrintMap()
{
	map->Print(false);
	PrintInfo();
}

void Minesweeper::PrintCustom()
{
	system("cls");
	int x = CONSOLE_W * 0.5;
	int y = CONSOLE_H * 0.2;


	while (1)
	{
		system("cls");
		draw.DrawMidText("Width(9-30) : ", x, y);
		gotoxy(x, y + 1);
		cin >> m_iWidth;
		draw.DrawMidText("Heigh (9-24): ", x, y + 2);
		gotoxy(x, y + 3);
		cin >> m_iHeight;
		draw.DrawMidText("Mine (10-668): ", x, y + 4);
		gotoxy(x, y + 5);
		cin >> m_iMineNum;
		if ((m_iWidth >= 9 && m_iWidth <= 30) && (m_iHeight >= 9 && m_iHeight <= 24) && (m_iMineNum >= 10 && m_iMineNum <= 668))
			break;
	}
	system("cls");

}

void  Minesweeper::PrintInfo()
{
	int x = CONSOLE_W * 0.89 ;
	int y = CONSOLE_H * 0.2;

	draw.DrawMidText("[Key]", x, y);
	draw.DrawMidText("UP : ¡è ", x, y + 2);
	draw.DrawMidText("DOWN : ¡é", x, y + 3);
	draw.DrawMidText("LEFT: ¡ç ", x, y + 4);
	draw.DrawMidText(" RIGHT : ¡æ", x, y + 5);
	draw.DrawMidText("SELECT : ENTER ", x, y + 6);
	draw.DrawMidText(" FLAG : SPACE", x, y + 7);
	draw.DrawMidText("MINE : ¡Ý  ", x, y + 8);
	draw.DrawMidText("FLAG : ¡Ú", x, y + 9);
}

void  Minesweeper::PrintGameEnd(GAMEEND endtype)
{
	system("cls");
	int x = CONSOLE_W * 0.5;
	int y = CONSOLE_H * 0.2;

	if (endtype == WIN)
	{
		draw.DrawMidText("You Won, Congratulations!", x, y);
	}
	else
	{
		draw.DrawMidText("You lost the game, Better luck next time!", x, y);
	}
	getch();
	Gameover = true;
}

void Minesweeper::Play()
{
	bool End;

	while (!Gameover)
	{
		if (player.GetGOvert()== true )
		{
			PrintGameEnd(LOSE);
		}
		else if(player.GetFlagCount() == map->GetMineCount() && map->GeNoneCount() == 0)
			PrintGameEnd(WIN);
		else
			player.Control(m_iWidth, m_iHeight, map);
	}
}



void Minesweeper::Display()
{
	while (1)
	{
		system("cls");
		Tilte();
		switch (m_eType)
		{
		case TYPE_BEGINNER:
		case TYPE_INTERMEDIATE:
		case TYPE_ADVANCED:
		case TYPE_CUSTOM:
			Init();
			Play();
			break;
		case TYPE_EXIT:
			return;
		default:
			break;
		}
	}
}



Minesweeper::~Minesweeper()
{	
	delete map;
}
