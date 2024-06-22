#pragma once


#ifndef __FIELD_H__
#define __FIELD_H__

class Monster;
class Player;

class Field {
public:
	Field();
	~Field();

public:

void Progress();
void Relese();

void set_player(Player* _pPlayer);	
int Battle();
			

private:

	Monster* m_pMonster;
	Player* pPlayer;

};
#endif