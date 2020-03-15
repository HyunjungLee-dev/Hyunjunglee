#pragma once
#include"Item.h"
#include"Mecro.h"


class Character : public Item
{
	string name;
	list<Item*> ItemList;
	int attack;
	int defence;
	int health;

public:
	Character();
	~Character();

	void AddItem(Item* item);
	void RemoveItem(Item* item);
	void View(int x, int y) override;
	void SetName(string n) { name = n; }
	void unworn(int x, int y);

	int GetAttackPoint() override; // 아이템들의 공격력 합산 반환
	int GetDefencePoint() override;
	int GetHealthPoint() override;
	string GetName() override { return name; }
	void GetItemName(int x, int y);
	bool GetItemListempty();
};

