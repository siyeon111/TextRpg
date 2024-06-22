#pragma once

#include "Obj.h"

class Inven;
class Item;
class Player;

class Shop : public CObj
{

public:
	vector<CObj*> Sell_List;

public:
	Shop();
	Shop(Player* player);
	~Shop();
	
	void Render();
	void Initialize();
	void sellct();
	void ButSell(int _iSelect, ITEM _Wepon);
	void Equip_Buy(int _iSelect, ITEM _Wepon);
	void Equip_Sell();
	void Butcheck(int _iSelect, vector<Item*> Wepon);
	void Sword();
	void Armor();
	void Progress();

	void Set_Inven(Inven* inven)
	{
		pInven = inven;
	}

	CObj* m_pPlayer;
	Player* pPlayer;
	Inven* pInven;

	vector<Item*> SwordList;
	vector<Item*> ArmorList;
};