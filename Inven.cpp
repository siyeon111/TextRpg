#include "stdafx.h"
#include "Inven.h"
#include "Player.h"
#include "Item.h"
#include "MainGame.h"
Inven::Inven()
{
}

Inven::~Inven()
{
	vector<Item*>::iterator iter = m_vecInv.begin();
	
	for (; iter != m_vecInv.end();)
	{
		SAFE_DELETE(*iter);
		++iter;
	}

	m_vecInv.clear();

}

void Inven::Initialize()
{
	m_vecInv.reserve(5);
}

void Inven::Progress()
{
	int iSelect = 0;
	while (true)
	{
		system("pause");
		system("cls");
		CMainGame::Logo();
		pPlayer->Render();
		Render();
		cout << "1.아이템 장착 2.아이템 해제 3.나가기" << endl;
		cout << "========================================================" << endl;
		cout << "입력: ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			Equip_Item();
			break;
		case 2:
			UnEquip_Item();
			break;
		case 3:
			return;
		default:
			break;
		}
	}
}

void Inven::Render()
{
	if (m_vecInv.size() <= 0)
	{
		cout << "인벤토리가 비었습니다..." << endl;
	}
	else
	{
		for (int i = 0; i < m_vecInv.size(); ++i)
		{
			cout << i + 1 << "번장비" << endl;
			m_vecInv[i]->Render();
		}
	}
}

void Inven::Gain_Item(Item* Item)
{
	if (m_vecInv.size() == 5)
	{
		cout << "인벤토리가 꽉 찼습니다!" << endl;
	}
	else
	{
		m_vecInv.emplace_back(Item);
	}
}

void Inven::Sell_Item(int idx)
{

	if (m_vecInv.size() <= 0)
	{
		cout << "인벤토리가 비었습니다..." << endl;
	}
	else if (m_vecInv.size() < idx)
	{
		cout << "없는 장비 번호 입니다." << endl;
	}
	else
	{
		Item* temp = m_vecInv[idx - 1];

		vector<Item*>::iterator iter = m_vecInv.begin();
		for (; iter != m_vecInv.end(); ++iter)
		{
			if ((*iter) == temp)
				break;
		}

		if ((*iter)->GetEquip() == true)
		{
			cout << "장착된 장비라 판매가 불가능합니다." << endl;
			system("pause");
		}
		else
		{
			pPlayer->Set_Gold((*iter)->Get_Info().iGold >> 1);
			m_vecInv.erase(iter);
			cout << "판매완료..." << endl;
			system("pause");
		}

	}
}

void Inven::Equip_Item()
{
	int iSelect = 0;
	while (true)
	{
		system("cls");
		CMainGame::Logo();
		Render();
		cout << "장착할 장비번호를 선택하세요... 6을 누르면 나가기" << endl;
		cout << "========================================================" << endl;
		cout << "입력: ";
		cin >> iSelect;
		if (iSelect == 6)
			return;

		if (m_vecInv.size() < iSelect && m_vecInv.size()==0)
		{
			continue;
		}
		
		if (pPlayer->Get_Item(m_vecInv[iSelect - 1]->GetType()) == nullptr)
		{
			pPlayer->Equip_Item(m_vecInv[iSelect - 1]);
			cout << "장착되었습니다." << endl;
		}
		else
		{
			cout << "이미 장착되있는 타입!." << endl;
		}
		return;

	}

}

void Inven::UnEquip_Item()
{
	int iSelect = 0;
	while (true)
	{
		system("cls");
		CMainGame::Logo();
		Render();
		cout << "해제할 장비번호를 선택하세요... 6을 누르면 나가기" << endl;
		cout << "========================================================" << endl;
		cout << "입력: ";
		cin >> iSelect;
		if (iSelect == 6)
			return;
		if (m_vecInv.size() < iSelect && m_vecInv.size() == 0)
		{
			continue;
		}
		if (m_vecInv[iSelect - 1]->GetEquip() == true)
		{
			pPlayer->UnEquip_Item(m_vecInv[iSelect - 1]);
			cout << "해제되었습니다." << endl;
			return;
		}
	}
}

void Inven::Set_Player(Player* player)
{
	pPlayer = player;
}


