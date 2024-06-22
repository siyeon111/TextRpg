#include "stdafx.h"
#include "Obj.h"


CObj::CObj()
{
}

CObj::CObj(INFO& _rInfo)
	: m_tInfo(_rInfo)
{

}

CObj::~CObj()
{
}

void CObj::Set_Damage(int _iAtt)
{
	m_tInfo.iHp -= _iAtt;
}

const INFO & CObj::Get_Info()
{
	return m_tInfo;
}