#include "stdafx.h"
#include "Slot.h"
#include "MainGame.h"
#include "GameLoby.h"
#include "Player.h"

Slot::Slot()
{
}

Slot::Slot(Player* player)
{
	pPlayer = player;
	for (int i = 0; i < 3; ++i)
	{
		num[i] = 0;
		end[i] = 0;
	}
}

Slot::~Slot()
{
}

void Slot::Progress()
{
	cout << "100Gold�Ҹ�Ǿ����ϴ�..." << endl;
	cout << pPlayer->Get_Info().iGold << "->";
	pPlayer->Set_Gold(-100);
	cout << pPlayer->Get_Info().iGold << endl;
	system("pause");



	int idx = 0;
	while (idx < 3)
	{
		while (true)
		{
			system("cls");
			GameLoby::GameLogo();
			cout << endl;
			cout << endl;
			if (idx == 1)
				Render(num[0]);
			if (idx == 2)
			{
				Render(num[0]);
				Render(num[1]);
			}
			int rands = rand() % 6 + 4;
			Render(rands);
			Sleep(99);
			++end[idx];
			if (end[idx] == 15)
			{
				num[idx] = rands;
				break;
			}
		}
		++idx;
	}

	system("pause");
	system("cls");
	GameLoby::GameLogo();
	cout << "�������" << endl;

	for (int i = 0; i < 3; ++i)
		Render(num[i]);
	cout << endl;

	Check(num[0], num[1], num[2]);

	cout << endl;

	system("pause");

	

}

void Slot::Render(int i)
{
	if (i == 4)
		cout << "��";
	else if (i== 5)
		cout << "��";
	else if (i== 6)
		cout << "��";
	else if (i== 7)
		cout << 7;
	else if (i== 8)
		cout << "��";
	else if (i == 9)
		cout << "��";
}

void Slot::Check(int a, int b, int c)
{
	if (a == b && b == c)
	{
		if (a == 7)
		{
			eResult = SEVEN;
			cout << "!!!!!!!!!!!!!!!JACKPOT!!!!!!!!!!!!!!!" << endl;
			cout << endl;
			cout << "777Goldȹ��!!!!" << endl;
			cout << pPlayer->Get_Info().iGold << "->";
			pPlayer->Set_Gold(777);
			cout << pPlayer->Get_Info().iGold << endl;

		}
		else
		{
			cout << "!!JACKPOT!!" << endl;
			cout << endl;
			cout << "300Goldȹ��!!!!" << endl;
			cout << pPlayer->Get_Info().iGold << "->";
			pPlayer->Set_Gold(300);
			cout << pPlayer->Get_Info().iGold << endl;
			eResult = JACKPOT;

		}
	}
	else if (a == b || b == c || a == c)
	{
		cout << "!SoSo!" << endl;
		cout << endl;
		cout << "150Goldȹ��!!!!" << endl;
		cout << pPlayer->Get_Info().iGold << "->";
		pPlayer->Set_Gold(150);
		cout << pPlayer->Get_Info().iGold << endl;
		eResult = SOSO;
	}
	else
	{
		cout << "BAD!" << endl;
		cout << "100��带 ���ȴ�..." << endl;
		eResult = BAD;
	}

}
