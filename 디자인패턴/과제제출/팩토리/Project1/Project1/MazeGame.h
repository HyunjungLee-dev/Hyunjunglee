#pragma once
#include"MazeFactory.h"

class MazeGame
{
public:
	MazeGame();
	~MazeGame();

	Maze* CreateMaze(MazeFactory* factory);
};

