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
	
	cout << "�̸�: " << m_tInfo.szName << endl;
	cout << "���ݷ�:" << m_tInfo.iAtt << endl;
	cout << "ü��: " << m_tInfo.iHp << " / " << m_tInfo.iMaxHp << endl;
	cout << "����: " << m_tInfo.iLevel << endl;
	cout << "����: " << m_tInfo.iExp << endl;
	cout << "���: " << m_tInfo.iGold << endl;
	cout << "========================================================" << endl;
}