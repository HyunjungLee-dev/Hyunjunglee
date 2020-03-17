#include "Maze.h"



Maze::Maze()
{
}

void Maze::AddRoom(Room* room)
{
	rooms.push_back(room);
}

Room* Maze::RoomNo(int roomNumber)
{
	list<Room*>::iterator begin = rooms.begin();
	list<Room*>::iterator end = rooms.end();
	while (begin != end)
	{
		if ((*begin)->GetRoomNumber() == roomNumber)
			return (*begin);
		else
			begin++;
	}
}

void Maze::print()
{
	cout << "Maze : " << endl;

	list<Room*>::iterator begin = rooms.begin();
	list<Room*>::iterator end = rooms.end();
	if (!rooms.empty())
	{
		while (begin != end)
		{
			cout << "	" << "Room Number : " << (*begin)->GetRoomNumber() << endl;
			(*begin)->print();
			begin++;
		}
	}
}


Maze::~Maze()
{
}
