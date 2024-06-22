#include "stdafx.h"
#include "Player.h"
#include "Item.h"

Player::Player()
{
	for (int i = 0; i < ITEM::ITEM_END; ++i)
		pItem[i] = nullptr;
}

Player::Player(INFO& pInfo)
	:CObj(pInfo)
{
	for (int i = 0; i < ITEM::ITEM_END; ++i)
		pItem[i] = nullptr;
}

Player::~Player()
{
}

void Player::Initialize()
{

}

void Player::Render()
{
	cout << "직업: " << m_tInfo.szName << endl;
	cout << "공격력: " << m_tInfo.iAtt << endl;
	cout << "체력: " << m_tInfo.iHp << " / " << m_tInfo.iMaxHp << endl;
	cout << "레벨: " << m_tInfo.iLevel << '\t' << "( " << m_tInfo.iExp << " / " << m_tInfo.iMaxExp << " )" << endl;
	cout << "소지금: " << m_tInfo.iGold << endl;
	cout << "========================================================" << endl;
}

Item* Player::Get_Item(int Itemidx)
{
	if (pItem[Itemidx] == nullptr)
		return nullptr;

	return pItem[Itemidx];
}


void Player::Set_Info(INFO& tInfo)
{
	strcpy(m_tInfo.szName, tInfo.szName);
	m_tInfo.iAtt = tInfo.iAtt;
	m_tInfo.iExp = tInfo.iExp;
	m_tInfo.iGold = tInfo.iGold;
	m_tInfo.iHp = tInfo.iHp;
	m_tInfo.iLevel = tInfo.iLevel;
	m_tInfo.iMaxExp = tInfo.iMaxExp;
	m_tInfo.iMaxHp = tInfo.iMaxHp;
}


void Player::Set_Ability(int atk, int maxhp)
{
	m_tInfo.iAtt += atk;
	m_tInfo.iMaxHp += maxhp;
}

void Player::Set_Gold(int Gold)
{
	m_tInfo.iGold += Gold;
}

void Player::ResetHp()
{
	m_tInfo.iHp = m_tInfo.iMaxHp;
}

void Player::ExpUp(int exp)
{
	m_tInfo.iExp += exp;

	if (m_tInfo.iExp >= m_tInfo.iMaxExp)
	{
		cout << "레벨업!!" << m_tInfo.iLevel << "->";
		m_tInfo.iLevel += 1;
		cout << m_tInfo.iLevel << endl;

		cout << "공격력 up: " << m_tInfo.iAtt << "->";
		m_tInfo.iAtt += 3;
		cout << m_tInfo.iAtt << endl;


		cout << "MaxHp up: " << m_tInfo.iMaxHp << "->";
		m_tInfo.iMaxHp += 5;
		cout << m_tInfo.iMaxHp << endl;

		m_tInfo.iExp = 0;
		m_tInfo.iMaxExp += 5;
		m_tInfo.iHp = m_tInfo.iMaxHp;
	}
}

void Player::Equip_Item(Item* item)
{
	item->BEquip();
	pItem[item->GetType()] = item;
	Set_Ability(item->Get_Info().iAtt, item->Get_Info().iHp);
}

void Player::UnEquip_Item(Item* item)
{
	if (pItem[(item->GetType())] == nullptr)
		return;
	pItem[(item->GetType())]->BEquip();
	Set_Ability(pItem[item->GetType()]->Get_Info().iAtt*-1, pItem[item->GetType()]->Get_Info().iHp*-1);
	pItem[(item->GetType())] = nullptr;
}

void Player::LoadItem(Item* item)
{
	pItem[item->GetType()] = item;
	item->Set_Eq(true);
}



