#include"MazeFactory.h"
#include "MazeGame.h"

void main()
{
	Maze* maze;
	MazeGame* game = new MazeGame();
	DefaultMaze* factory = new DefaultMaze();
	//BombedMaze* Bfactory = new BombedMaze();

	maze = game->CreateMaze(factory);
	//maze = game->CreateMaze(Bfactory);
	maze->print();

	delete game;
	delete factory;
//	delete Bfactory;
}