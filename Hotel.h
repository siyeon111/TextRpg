#pragma once

class Player;

class Hotel
{
public:
	Hotel();
	Hotel(Player* player);
	~Hotel();
public:
	void Initialize();
	void Progress();
	void CureHp();


private:
	Player* pPlayer;


};


