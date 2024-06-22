#include "stdafx.h"
#include "Town.h"
#include "Player.h"
#include "Hotel.h"
#include "Smithy.h"
#include "Shop.h"
#include "MainGame.h"
#include "GameLoby.h"

Town::Town()
{
}

Town::~Town()
{
	SAFE_DELETE(pHotel);
	SAFE_DELETE(pShop);
	SAFE_DELETE(pSmithy);
	SAFE_DELETE(pGameLoby);
}

void Town::Set_Player(Player* player)
{
	pPlayer = player;
}

void Town::Set_Inven(Inven* inven)
{
	pInven = inven;
}

void Town::Initialize()
{
	pHotel = new Hotel(pPlayer);
	pHotel->Initialize();
	
	pSmithy = new Smithy(pPlayer);
	pSmithy->Initialize();

	pShop = new Shop(pPlayer);
	pShop->Initialize();
	pShop->Set_Inven(pInven);

	pGameLoby= new GameLoby(pPlayer);
	pGameLoby->Initialize();


}

void Town::Progress()
{
	int iSelect = 0;

	while (true)
	{
		system("cls");
		CMainGame::Logo();

		pPlayer->Render();
		cout << "1.여관 2.상점 3.대장간 4.미니게임 5.종료" << endl;
		cout << "========================================================" << endl;
		cout << "입력: ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			pHotel->Progress();
			break;
		case 2:
			pShop->Progress();
			break;
		case 3:
			pSmithy->Progress();
			break;
		case 4:
			pGameLoby->Progress();
				break;
		case 5:
			return;
		default:
			break;
		}
	}
}