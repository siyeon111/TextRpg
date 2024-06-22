#pragma once

class Player;

class Casino {

public:
	Casino();
	Casino(Player* player);


public:
	void Progress();
	bool Start();
	bool SoonStart(int beting);
	bool Game(int bating, int pbating);
	void logo();
	void RullRat(int roll);


private:
	Player* pPlayer;

};