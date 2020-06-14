#pragma once
#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<time.h>
#include <fstream>
#include<vector>
using namespace std;


#define DEFULTMINE 50
#define HEIGHT 16
#define WIDTH 30

struct POS
{
	float m_fX;
	float m_fY;
};

struct GameRecord
{
	int bestSec;
	int PlayNum;
	int WinNum;
	int winrate;
};


enum MOUSE
{
	LBUTTONDOWN,
	RBUTTONDOWN
};

enum IMG
{
	IMG_START,

	IMG_BACK = 0,
	IMG_BLOCK,
	IMG_BLOCK_CLICK,
	IMG_BLOCK_START = 2,
	IMG_BLOCK1,
	IMG_BLOCK2,
	IMG_BLOCK3,
	IMG_BLOCK4,
	IMG_BLOCK5,
	IMG_BLOCK6,
	IMG_BLOCK7,
	IMG_BLOCK8,
	IMG_FLAG,
	IMG_MINE,

	IMG_END = 13,
};



enum GAMESTATE
{
	GAME_WAIT,
	GAME_RESET,
	GAME_START,
	GAME_STOP,
	GAME_DIE,
	GAME_REPLAY,
	GAME_PLAY,
	GAME_WIN
};