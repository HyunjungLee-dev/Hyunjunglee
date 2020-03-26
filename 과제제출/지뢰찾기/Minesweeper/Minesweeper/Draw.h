#pragma once
#include"Mecro.h"
class Draw
{
public:
	void DrawMidText(string str, int x, int y);
	void ErasePoint(int x, int y);
	void DrawPoint(string str, int x, int y);
	Draw();
	~Draw();
};

