#pragma once
#include"Map.h"
class GameManager
{
private:
	HWND m_hWnd;
	HDC m_backbufferDC;
	RECT m_ClientRct;

	int m_iFlagCount;
	int  m_iMineCount;

	int m_SecTime;
	DWORD	m_dwLastTime;
	DWORD	m_dwCurTime;
	float	m_fDeltaTime;

	GAMESTATE m_eState;
	bool m_bBestSec;
	GameRecord m_Record;

	BlockFactory*  m_factory;
	vector<Block*> m_FlagList;

	Map m_Map;
public:
	//Init
	void Init(HWND hWnd);
	void ReStart(GAMESTATE state);

	//Update
	void Update();
	void Collision(POINT pos);
	void PutFlag(POINT pos);
	GAMESTATE StateCheck();

	//Render
	void Render();
	void FlagRender();
	void Text();

	//Release
	void Release();

	void inFile();
	void OutFile();
	int GetSecTime() { return m_SecTime; }
	GameRecord GetRecord() { return m_Record; }
	bool Getbestsec() { return m_bBestSec; }
	GameManager();
	~GameManager();
};

