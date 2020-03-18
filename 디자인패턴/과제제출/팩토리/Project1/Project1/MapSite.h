#pragma once
#include<iostream>
#include<list>
using namespace std;

enum Direction {
	North, South, East, West
}; //4개의 벽의 방을 만들기 위한 방향 구분용

class MapSite
{
public:
	MapSite();
	virtual ~MapSite();
	//virtual void Enter() = 0; //방에 들어갔을 때와 같은 상황에 맞는 관련 기능 추가 가능
	virtual void print() = 0;
};

/*Room*/

class Room : public MapSite
{
	MapSite* _sides[4];
	int _roomNumber;
public:
	Room();
	Room(int roomNumber);
	virtual  ~Room();
	
	//virtual void Enter() {};
	void SetSide(Direction direction, MapSite* ms);
	MapSite* GetSide(Direction direction);
	int GetRoomNumber();
	virtual void print();
};

/*Wall*/

class Wall : public MapSite
{
public:
	Wall();
	virtual ~Wall();
	//virtual void Enter() {};
	virtual void print() {};
};

class BombedWall : public Wall
{
public:
	BombedWall() {};
	~BombedWall() {};
};

/*Door*/

class Door :public MapSite
{
	bool _isOpen;
	Room* _room1;
	Room* _room2;
public:
	Door(Room* room1, Room* room2);
	virtual ~Door();
//	virtual void Enter() {};
	virtual void print();
};

