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
		cout << "1.HPȸ��(10gold) 2.������" << endl;
		cout << "========================================================" << endl;
		cout << "�Է�: ";
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
		cout << "��� ����!!!" << endl;
		return;
	}

	if (pPlayer->Get_Info().iHp == pPlayer->Get_Info().iMaxHp)
	{
		cout << "Hp�� �̹� �� ���ֽ��ϴ�..." << endl;
		return;
	}

	pPlayer->Set_Gold(-10);
	cout << "10��� ����!!!"<<endl<< "Hp�� ȸ���մϴ�..." << endl;

	cout << "Hp:" << pPlayer->Get_Info().iHp << "->";
	pPlayer->ResetHp();
	cout << pPlayer->Get_Info().iHp << endl;

}





