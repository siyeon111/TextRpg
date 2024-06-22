#pragma once

class Player;

class Smithy
{
public:
	Smithy();
	Smithy(Player* player);
	~Smithy();

public:
	void Initialize();
	void Progress();
	void Enhancement();

public:
	Player* pPlayer;
	
};

