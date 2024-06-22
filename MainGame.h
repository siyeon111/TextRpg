#pragma once

#ifndef __MAINGAME_H__
#define __MAINGAME_H__

class CObj;
class Player;
class Town;
class Inven;
class Field;

class CMainGame
{
public:
	CMainGame();
	~CMainGame();

public:
	bool Initialize();
	void Progress();
	void Release();

public:
	void Select_Job();

	void Load_Data();
	void Save_Data();
	static void Logo();
	static void colorText(int colorSet);
private:
	Town* m_pTown;
	Inven* m_Inven;
	Player*		m_pPlayer;
	Field* m_pField;
};

#endif // !__MAINGAME_H__