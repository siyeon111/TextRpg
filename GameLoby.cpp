#include"stdafx.h"
#include"GameLoby.h"
#include"Player.h"
#include"Casino.h"
#include "Slot.h"
#include "Dino.h"

GameLoby::GameLoby() {

}

GameLoby::GameLoby(Player* player) {
	pPlayer = player;
}

GameLoby::~GameLoby()
{
	SAFE_DELETE(pCasino);
	SAFE_DELETE(pSlot);
	SAFE_DELETE(pDino);
}

void GameLoby::Initialize() {

	pCasino = new Casino(pPlayer);
	pSlot = new Slot(pPlayer);
	pDino = new Dino;

}

void GameLoby::Progress() {
	int iSelect;

	while (true) {

		system("cls");
		pPlayer->Render();
		GameLogo();
		cout << "    1.�귿 2.���Ըӽ�(100Gold) 3.������� 0.������" << endl;
		cout << "========================================================" << endl;
		cout << "�Է�: ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			pCasino->Progress();
			break;
		case 2:
			pSlot->Progress();
			break;
		case 3:
			pDino->progress();
			break;
		case 0:
			return;
		default:
			break;
		}
	}
}

void GameLoby::GameLogo() {
	cout << endl;
	cout << "	#####     ###    ##   ##  #######    " << endl;
	cout << "	##   ##   ## ##   ### ###   ##   #		 " << endl;
	cout << "	##       ##   ##  #######   ##			 " << endl;
	cout << "	## ####  ##   ##  ## # ##   ####		 " << endl;
	cout << "	##   ##  #######  ##   ##   ##			 " << endl;
	cout << "	##   ##  ##   ##  ##   ##   ##   #		 " << endl;
	cout << "	#####   ##   ##  ### ###  #######		 " << endl;
	cout << endl;
}