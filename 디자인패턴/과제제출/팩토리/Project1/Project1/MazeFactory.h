#pragma once
#include"Maze.h"

class MazeFactory
{
public:
	MazeFactory();
	virtual~MazeFactory();
	virtual Maze* makeMaze() = 0;
	virtual	Wall* makeWall() = 0;
	virtual Room* makeRoom(int n) = 0;
	virtual 	Door* makeDoor(Room* r1, Room* r2) = 0;

};

class DefaultMaze : public MazeFactory
{
public:
	virtual Maze* makeMaze();
	virtual	Wall* makeWall();
	virtual Room* makeRoom(int n);
	virtual 	Door* makeDoor(Room* r1, Room* r2);
};

class BombedMaze :public MazeFactory
{
public:
	virtual Maze* makeMaze();
	virtual	Wall* makeWall();
	virtual Room* makeRoom(int n);
	virtual 	Door* makeDoor(Room* r1, Room* r2);

};