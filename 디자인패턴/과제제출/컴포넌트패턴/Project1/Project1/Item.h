#pragma once
#include"MapDraw.h"
#include"Mecro.h"

class Item
{
protected: 
	MapDraw m_DrawManager;
public:
	Item();
	virtual~Item();
	virtual void View(int x, int y) = 0;
	virtual int GetAttackPoint() = 0;  // 공격력, 방어력, 생명력 일반화를 위한 추상 클래스
	virtual int GetDefencePoint() = 0;
	virtual int GetHealthPoint() = 0;
	virtual string GetName() =0;

};


class Sword : public Item
{
	string Name;
	int attackPoint;
	int defencePoint;
	int healthPoint;

public:
	Sword();
	~Sword();
	void View(int x, int y) override;
	void SetPoint(string name,int ap, int dp, int hp);
	int GetAttackPoint() override;  
	int GetDefencePoint() override;
	int GetHealthPoint() override;
	string GetName() override;


};

class Shield : public Item
{
	string Name;
	int attackPoint;
	int defencePoint;
	int healthPoint;

public:
	Shield();
	~Shield();
	void View(int x, int y) override;
	void SetPoint(string name, int ap, int dp, int hp);
	int GetAttackPoint() override;
	int GetDefencePoint() override;
	int GetHealthPoint() override;
	string GetName() override;
};