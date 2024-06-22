#pragma once
#include"Obj.h"
class Monster:public CObj
{
public:
	explicit Monster();
	explicit Monster(INFO& _rInfo);
	~Monster();
public:
	virtual void Initialize();
	virtual void Render();
};