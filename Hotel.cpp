#include "stdafx.h"
#include "Hotel.h"
#include "Player.h"
#include "MainGame.h"

Hotel::Hotel()
{
}

Hotel::Hotel(Player* player)
{
	pPlayer = player;
}

Hotel::~Hotel()
{
}

void Hotel::Initialize()
{
}

void Hotel::Progress()
{
	int iSelect = 0;
	while (true)
	{
		system("pause");
		system("cls");
		CMainGame::Logo();
		pPlayer->Render();
		cout << "1.HP회복(10gold) 2.나가기" << endl;
		cout << "========================================================" << endl;
		cout << "입력: ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			CureHp();
			break;
		case 2:
			pPlayer->Set_Damage(10);
			return;
		default:
			break;
		}
	}


}

void Hotel::CureHp()
{
	if (pPlayer->Get_Info().iGold < 10)
	{
		cout << "골드 부족!!!" << endl;
		return;
	}

	if (pPlayer->Get_Info().iHp == pPlayer->Get_Info().iMaxHp)
	{
		cout << "Hp가 이미 꽉 차있습니다..." << endl;
		return;
	}

	pPlayer->Set_Gold(-10);
	cout << "10골드 차감!!!"<<endl<< "Hp를 회복합니다..." << endl;

	cout << "Hp:" << pPlayer->Get_Info().iHp << "->";
	pPlayer->ResetHp();
	cout << pPlayer->Get_Info().iHp << endl;

}





