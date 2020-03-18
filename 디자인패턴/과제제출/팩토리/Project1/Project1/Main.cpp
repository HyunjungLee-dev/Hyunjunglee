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

/*maze, wall, door, room 
room은 wall이나 door로 되어 있음
room과 room은 door로 이어져있다
maze는 복수의 room을 가짐*/