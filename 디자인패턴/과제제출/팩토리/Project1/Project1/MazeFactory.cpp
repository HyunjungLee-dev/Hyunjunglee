#include "MazeFactory.h"



MazeFactory::MazeFactory()
{
}


MazeFactory::~MazeFactory()
{
}

/*Default*/

Maze* DefaultMaze::makeMaze()
{
	return new Maze();
}

Wall* DefaultMaze::makeWall()
{
	return new Wall();
}

Room* DefaultMaze::makeRoom(int n)
{
	return new Room(n);
}

 Door * DefaultMaze::makeDoor( Room * r1,  Room * r2)
{
	return new Door(r1, r2);
}

 /*Bombed*/

 Maze* BombedMaze::makeMaze()
 {
	 return new Maze();
 }

 Wall* BombedMaze::makeWall()
 {
	 return new BombedWall();
 }

 Room* BombedMaze::makeRoom(int n)
 {
	 return new Room(n);
 }

 Door * BombedMaze::makeDoor(Room * r1, Room * r2)
 {
	 return new Door(r1, r2);
 }
