#pragma once


class Player;
class Item;


class Inven
{
public:
	Inven();
	~Inven();

public:
	void Initialize();
	void Progress();
	void Render();
public:
	void Gain_Item(Item* Item);
	void Sell_Item(int idx);

	void Equip_Item();
	void UnEquip_Item();

public://set
	void Set_Player(Player* player);

public://get
	vector<Item*>& Get_Inven()
	{
		return m_vecInv;
	}

private:
	Player* pPlayer;
	vector<Item*> m_vecInv;
};

