#include"Minesweeper.h"

void main()
{
	char buf[256];
	sprintf(buf, "mode con: lines=%d cols=%d", CONSOLE_H, CONSOLE_W);
	system(buf);
	srand((unsigned)time(NULL));
	Minesweeper minesweeper;
	minesweeper.Display();

}