#pragma once

#ifndef __STRUCT_H__
#define __STRUCT_H__

typedef struct tagInfo
{
	tagInfo() {}
	// 플레이어 생성
	tagInfo(const char * _pName, int _iAtt, int _iMaxHp)
		: iAtt(_iAtt), iMaxHp(_iMaxHp), iHp(_iMaxHp), iLevel(1), iMaxExp(10)
		, iGold(1000) , iExp(0)
	{
		strcpy_s(szName, 16, _pName);
	}

	// 몬스터 생성
	tagInfo(const char * _pName, int _iAtt, int _iMaxHp, int _iLevel)
		: iAtt(_iAtt), iMaxHp(_iMaxHp), iHp(_iMaxHp)
		, iLevel(_iLevel), iMaxExp(0), iGold(0) , iExp(0)
	{
		strcpy_s(szName, 16, _pName);
	}

	// 아이템 생성
	tagInfo(const char * _pName, int _iAtt, int _iMaxHp, int _iLevel, int _iGold)
		: iAtt(_iAtt), iMaxHp(_iMaxHp), iHp(_iMaxHp)
		, iLevel(_iLevel), iMaxExp(0), iGold(_iGold), iExp(0)
	{
		strcpy_s(szName, 16, _pName);
	}
	~tagInfo() {}

	char	szName[16];
	int		iAtt;
	int		iMaxHp;
	int		iHp;
	int		iLevel;
	int		iMaxExp;
	int		iExp;
	int		iGold;
}INFO;

#endif // !__STRUCT_H__
