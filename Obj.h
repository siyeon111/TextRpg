#pragma once

#ifndef __OBJ_H__
#define __OBJ_H__


class CObj
{
public:
	explicit CObj();
	explicit CObj(INFO& _rInfo);
	virtual ~CObj();

public:
	virtual void Initialize() = 0;
	virtual void Render() = 0;

public:
	void Set_Damage(int _iAtt);

public:
	const INFO& Get_Info();

protected:
	INFO	m_tInfo;
};

#endif // !__OBJ_H__