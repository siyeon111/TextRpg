#pragma once

class Player;

class Slot
{
public:
	enum SLOTRESULT {SEVEN,JACKPOT,SOSO,BAD,SLOTRESULTEND};

public:
	Slot();
	Slot(Player* player);
	~Slot();

public:

	void Progress();
	void Render(int i);
	void Check(int a, int b, int c);
private:
	
	Player* pPlayer;
	int num[3];
	int end[3];
	SLOTRESULT eResult;
};

