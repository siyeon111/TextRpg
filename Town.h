#pragma once

class Player;
class Hotel;
class Smithy;
class Inven;
class Shop;
class GameLoby;

class Town
{
public:
	Town();
	~Town();


public:
	void Initialize();
	void Progress();
	void Set_Player(Player* player);

	void Set_Inven(Inven* inven);





private:
	Player* pPlayer;
	Hotel* pHotel;
	Smithy* pSmithy;
	Inven* pInven;
	Shop* pShop;
	GameLoby* pGameLoby;
};

