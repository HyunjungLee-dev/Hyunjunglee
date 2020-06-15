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

	int m_iHeight;
	int m_iWidth;

	int m_SecTime;
	DWORD	m_dwLastTime;
	DWORD	m_dwCurTime;
	float	m_fDeltaTime;

	GAMESTATE m_eState;
	bool m_bBestSec;
	int m_ibestSec;
	GameRecord m_Record;
	LEVEL m_level;

	BlockFactory*  m_factory;
	vector<Block*> m_FlagList;

	Map m_Map;
public:
	//Init
	void Init(HWND hWnd);
	void ReStart(GAMESTATE state);
	void SetMinenum(); 
	void SetMinenum(int num) { m_iMineCount = num; }

	//Update
	void Update();
	void Collision(POINT pos);
	void PutFlag(POINT pos);
	GAMESTATE StateCheck();
	void BestSec();

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
	void Setlevel(LEVEL level) { m_level = level; }
	int GetBestSec() { return m_ibestSec; }
	GameManager();
	~GameManager();
};

