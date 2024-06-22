#pragma once

class Player;
class Casino;
class Slot;
class Dino;

class GameLoby {

public:
	GameLoby();
	GameLoby(Player* player);
	~GameLoby();
	void Initialize();
	void Progress();
	static void GameLogo();

private:
	Player* pPlayer;
	Casino* pCasino;
	Slot* pSlot;
	Dino* pDino;
};