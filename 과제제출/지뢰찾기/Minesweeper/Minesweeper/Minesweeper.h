#pragma once
#include"Player.h"


enum SELECT_TYPE	 
{
	TYPE_BEGINNER = 1,
	TYPE_INTERMEDIATE,
	TYPE_ADVANCED,
	TYPE_CUSTOM,
	TYPE_EXIT
};

enum GAMEEND
{
	WIN,
	LOSE
};



class Minesweeper
{
	Draw draw;
	Player player;
	Map* map;
	MapFactory* factory;
	SELECT_TYPE m_eType;
	bool Gameover;
	 int m_iWidth;
	 int m_iHeight;
	 int m_iMineNum;
public:
	void Display();	  
	void Tilte();
	void Init();
	void CreateMap();
	void PrintMap();
	void PrintInfo();
	void PrintCustom();
	void PrintGameEnd(GAMEEND endtype);
	void Play();
	Minesweeper();
	~Minesweeper();
};

