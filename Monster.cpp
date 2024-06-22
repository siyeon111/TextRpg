#include "stdafx.h"
#include "Monster.h"

Monster::Monster()
{
}

Monster::Monster(INFO& _rInfo)
	:CObj(_rInfo)
{
}

Monster::~Monster()
{
}

void Monster::Initialize()
{
	m_tInfo.iExp = (rand() % 10 + 1);
	m_tInfo.iGold = (rand() % 20 + 1);
};

void Monster::Render()
{
	
	cout << "이름: " << m_tInfo.szName << endl;
	cout << "공격력:" << m_tInfo.iAtt << endl;
	cout << "체력: " << m_tInfo.iHp << " / " << m_tInfo.iMaxHp << endl;
	cout << "레벨: " << m_tInfo.iLevel << endl;
	cout << "경험: " << m_tInfo.iExp << endl;
	cout << "골드: " << m_tInfo.iGold << endl;
	cout << "========================================================" << endl;
}