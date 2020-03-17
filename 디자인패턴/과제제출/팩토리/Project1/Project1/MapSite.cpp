#include "MapSite.h"



MapSite::MapSite()
{
}


MapSite::~MapSite()
{
}

Room::Room()
{

}

Room::Room(int roomNumber)
{
	this->_roomNumber = roomNumber;

}

void Room::SetSide(Direction direction, MapSite* ms)
{
	int index;
	switch (direction)
	{
	case North: index = 0; break;
	case East: index = 1; break;
	case South: index = 2; break;
	case West: index = 3; break;
	default:
		break;
	}
	_sides[index] = ms;
}

MapSite* Room::GetSide(Direction direction)
{
	return _sides[direction];
}

int Room::GetRoomNumber()
{
	return _roomNumber;
}

void Room::print()
{
	for (int i = 0; i < 4; i++) {
		MapSite* temp = _sides[i];
		temp->print();
	}
}

Room::~Room()
{
}

Wall::Wall()
{
}


Wall::~Wall()
{
}

Door::Door(Room* room1, Room* room2)
{
	_room1 = room1;
	_room2 = room2;
}

void Door::print()
{
	cout << "		" << "Door : " << endl;
	if (_room1)
		cout << "			" << "room1 : " << _room1->GetRoomNumber() << endl;
	else
		cout << "			" << NULL<< endl;
	if (_room2)
		cout << "			" << "room2 : " << _room2->GetRoomNumber() << endl;
	else
		cout << "			" << NULL << endl;
	if (_isOpen)
		cout << "			" << "door Open"<< endl;
	else
		cout << "			" << "door lock " << endl;
}

Door::~Door()
{
}

