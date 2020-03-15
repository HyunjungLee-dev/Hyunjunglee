#include "Item.h"



Item::Item()
{
}


Item::~Item()
{
}

Sword::Sword()
{
}

void Sword::SetPoint(string name,int ap, int dp, int hp)
{
	Name = name;
	attackPoint = ap;
	defencePoint = dp;
	healthPoint = hp;
}

void Sword::View(int x, int y)
{
	m_DrawManager.gotoxy(x, y);
	cout << "Sword " << endl;
	m_DrawManager.gotoxy(x, y+1);
	cout<<  Name <<" 공격력 : "+ to_string(attackPoint)<<" 방어력 : " + to_string(defencePoint) +" 체력 : " + to_string(healthPoint);
}

int Sword::GetAttackPoint()
{
	return attackPoint;
}

int Sword::GetDefencePoint()
{
	return defencePoint;
}

int Sword::GetHealthPoint()
{
	return healthPoint;
}

string Sword::GetName()
{
	return Name;
}

Sword::~Sword()
{
}

Shield::Shield()
{
}

void Shield::View(int x, int y)
{
	m_DrawManager.gotoxy(x, y);
	cout << "Shield " << endl;
	m_DrawManager.gotoxy(x, y+1);
	cout<< Name << " 공격력 : " + to_string(attackPoint) << " 방어력 : " + to_string(defencePoint) + " 체력 : " + to_string(healthPoint);
}


void Shield::SetPoint(string name,int ap, int dp, int hp)
{
	Name = name;
	attackPoint = ap;
	defencePoint = dp;
	healthPoint = hp;
}

int Shield::GetAttackPoint()
{
	return attackPoint;
}

int Shield::GetDefencePoint()
{
	return defencePoint;
}

int Shield::GetHealthPoint()
{
	return healthPoint;
}

string Shield::GetName()
{
	return Name;
}

Shield::~Shield()
{

}