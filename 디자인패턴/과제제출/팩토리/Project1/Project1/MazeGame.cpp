#include "MazeGame.h"



MazeGame::MazeGame()
{
}

Maze* MazeGame::CreateMaze(MazeFactory* factory)
{
	Maze* maze;
	maze = factory->makeMaze();
	Room* r1,*r2;
	r1 = factory->makeRoom(1);
	r2 = factory->makeRoom(2);
	Door* door;
	door = factory->makeDoor(r1, r2);

	maze->AddRoom(r1);
	maze->AddRoom(r2);

	r1->SetSide(North, factory->makeWall());
	r1->SetSide(East, door);
	r1->SetSide(South, factory->makeWall());
	r1->SetSide(West, factory->makeWall());

	r2->SetSide(North, factory->makeWall());
	r2->SetSide(East, factory->makeWall());
	r2->SetSide(South, factory->makeWall());
	r2->SetSide(West, door);

	return maze;
}

MazeGame::~MazeGame()
{
}
