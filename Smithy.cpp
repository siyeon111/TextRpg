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
				cout << i + 1 << "번아이템" << endl;
				pPlayer->Get_Item(i)->Render();
			}

		}
		cout << "1.강화 2.나가기" << endl;
		cout << "========================================================" << endl;
		cout << "입력: ";
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
				cout << i + 1 << "번아이템" << endl;
				pPlayer->Get_Item(i)->Render();
			}

		}

		cout << "강화할 아이템 선택!  3번 나가기" << endl;
		cout << "========================================================" << endl;
		cout << "입력: ";
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
		cout << "강화비용:" << pItem->Get_Info().iGold << endl;
		cout << "강화하시겠습니까?  1.Yes 2.No  " << endl;
		int foren = 0;
		cin >> foren;

		switch (foren)
		{
		case 1:
			if (pPlayer->Get_Info().iGold < pItem->Get_Info().iGold)
			{
				cout << "골드 부족..!" << endl;
				continue;
			}
			pPlayer->Set_Gold(pItem->Get_Info().iGold * -1);
			if ((rand() % 4) <= 1)
			{
				cout << "강화성공" << endl;
				pPlayer->Set_Ability(pItem->Get_Info().iAtt*-1, pItem->Get_Info().iHp*-1);
				pItem->LvUp();
				pPlayer->Set_Ability(pItem->Get_Info().iAtt, pItem->Get_Info().iHp);
			}
			else 
			{
				cout << "강화실패" << endl;
			}
			break;
		default:
			continue;
		}



	}
}





