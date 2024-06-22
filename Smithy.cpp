#include "stdafx.h"
#include "Smithy.h"
#include "Item.h"
#include "Player.h"
#include "MainGame.h"
Smithy::Smithy()
{
}

Smithy::Smithy(Player* player)
{
	pPlayer = player;
}

Smithy::~Smithy()
{
}

void Smithy::Initialize()
{
}

void Smithy::Progress()
{
	int iSelect = 0;

	while (true)
	{
		system("cls");
		CMainGame::Logo();
		pPlayer->Render();
		for (int i = 0; i < ITEM::ITEM_END; ++i)
		{
			if (pPlayer->Get_Item(i) != nullptr)
			{
				cout << i + 1 << "��������" << endl;
				pPlayer->Get_Item(i)->Render();
			}

		}
		cout << "1.��ȭ 2.������" << endl;
		cout << "========================================================" << endl;
		cout << "�Է�: ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			Enhancement();
			break;
		case 2:
			return;
		default:
			break;
		}
	}

}

void Smithy::Enhancement()
{
	int iSelect = 0;
	while (true)
	{
		system("pause");
		system("cls");
		CMainGame::Logo();

		Item* pItem = nullptr;
		pPlayer->Render();
		for (int i = 0; i < ITEM::ITEM_END; ++i)
		{
			if (pPlayer->Get_Item(i) != nullptr)
			{
				cout << i + 1 << "��������" << endl;
				pPlayer->Get_Item(i)->Render();
			}

		}

		cout << "��ȭ�� ������ ����!  3�� ������" << endl;
		cout << "========================================================" << endl;
		cout << "�Է�: ";
		cin >> iSelect;
		if (iSelect == 3)
			return;
		system("cls");
		CMainGame::Logo();
		pPlayer->Render();
		pItem = pPlayer->Get_Item(iSelect - 1);
		if (pItem == nullptr)
			continue;
		pItem->Render();
		cout << "��ȭ���:" << pItem->Get_Info().iGold << endl;
		cout << "��ȭ�Ͻðڽ��ϱ�?  1.Yes 2.No  " << endl;
		int foren = 0;
		cin >> foren;

		switch (foren)
		{
		case 1:
			if (pPlayer->Get_Info().iGold < pItem->Get_Info().iGold)
			{
				cout << "��� ����..!" << endl;
				continue;
			}
			pPlayer->Set_Gold(pItem->Get_Info().iGold * -1);
			if ((rand() % 4) <= 1)
			{
				cout << "��ȭ����" << endl;
				pPlayer->Set_Ability(pItem->Get_Info().iAtt*-1, pItem->Get_Info().iHp*-1);
				pItem->LvUp();
				pPlayer->Set_Ability(pItem->Get_Info().iAtt, pItem->Get_Info().iHp);
			}
			else 
			{
				cout << "��ȭ����" << endl;
			}
			break;
		default:
			continue;
		}



	}
}





