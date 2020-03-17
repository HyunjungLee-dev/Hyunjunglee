#pragma once
#include"MapSite.h"
#include<list>


class Maze
{
	list<Room*> rooms;
public:
	Maze();
	 ~Maze();
	 void AddRoom(Room* room);
	 Room* RoomNo(int num);
	 void print();
;};

