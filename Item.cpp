#include "stdafx.h"
#include "Item.h"

Item::Item()
{
}

Item::Item(INFO& info)
	:CObj(info)
{
	bEquip = false;
}

Item::Item(Item* item)
{
	if (item == nullptr)
		return;
	m_tInfo = item->Get_Info();
	bEquip = item->GetEquip();
	eItemType = item->GetType();
}

Item::~Item()
{
}

void Item::Initialize()
{
}

void Item::Render()
{
	if (bEquip == true)
		cout << "<착용중>" << endl;
	cout << "이름: " << m_tInfo.szName << endl;
	cout << "공격력 +" << m_tInfo.iAtt << endl;
	cout << "체력 +" << m_tInfo.iHp << endl;
	cout << "강화 +" << m_tInfo.iLevel << endl;
	cout << "가격: " << m_tInfo.iGold << endl;
	cout << "========================================================" << endl;
}
void Item::LvUp()
{
	Set_Value(m_tInfo.iAtt, m_tInfo.iHp);
	++m_tInfo.iLevel;
}
void Item::BEquip()
{
	bEquip = !bEquip;
}

void Item::Set_Type(ITEM type)
{
	eItemType = type;
}

void Item::Set_Value(int atk, int hp)
{
	m_tInfo.iAtt += atk;
	m_tInfo.iHp += hp;
}

void Item::Set_Lv(int lv)
{
	m_tInfo.iLevel += lv;
}

bool Item::GetEquip()
{
	return bEquip;
}

ITEM Item::GetType()
{
	return eItemType;
}

