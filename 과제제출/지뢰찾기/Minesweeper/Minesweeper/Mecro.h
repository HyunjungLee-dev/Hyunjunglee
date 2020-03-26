#pragma once

#include<iostream>
#include<string>
#include<Windows.h>
#include<conio.h>
#include<list>
#include<time.h>
using namespace std;
inline void gotoxy(int x, int y)
{
	COORD Pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
#define CONSOLE_W  80
#define CONSOLE_H  30
