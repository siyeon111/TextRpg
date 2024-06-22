#pragma once

#ifndef  __PLAYER__H__
#define  __PLAYER__H__

#include "Obj.h"


class Item;

class Player :
	public CObj
{
public:
	explicit Player();
	explicit Player(INFO& pInfo);
	virtual ~Player();

public:
	// CObj을(를) 통해 상속됨
	void Initialize() override;
	void Render() override;

public:
	Item* Get_Item(int Itemidx);

public:
	void Set_Info(INFO& tInfo);
	void Set_Ability(int atk, int maxhp);
	void Set_Gold(int Gold);
	void ResetHp();
	void ExpUp(int exp);

	void Equip_Item(Item* item);
	void UnEquip_Item(Item* item);
	void LoadItem(Item* item);
private:
	Item* pItem[ITEM::ITEM_END];
};

#endif // ! __PLAYER__H__
