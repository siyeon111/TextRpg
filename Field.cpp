#include"stdafx.h"
#include "Field.h"
#include"Monster.h"
#include"Player.h"
#include "MainGame.h"

Field::Field()
{
	pPlayer = nullptr, m_pMonster = nullptr;
}

Field::~Field()
{
	Relese();
}

void Field::Progress()
{
	int select = 0;

	while (true) {
		system("cls");
		CMainGame::Logo();
		pPlayer->Render();
		cout << " 1.사막2.해안3.정글4.종료" << endl;
		cout << "------------------------" << endl;
		cout << "입력" << endl;
		cin >> select;

		switch (select)
		{
		case 1:
			m_pMonster = new Monster((INFO&)INFO("샤이-훌루드", 1, 1, 1));
			break;
		case 2:
			m_pMonster = new Monster((INFO&)INFO("크라켄", 10, 10, 10));
			break;
		case 3:
			m_pMonster = new Monster((INFO&)INFO("비홀더", 100, 100, 100));
			break;
		case 4:
			return;
		default:
			cout << "올바른 입력이 아닙니다." << endl;;
			system("pause");
			continue;
		}
		m_pMonster->Initialize();

		switch (Battle())
		{
		case 1:
			pPlayer->ExpUp(m_pMonster->Get_Info().iExp);
			pPlayer->Set_Gold(m_pMonster->Get_Info().iGold);

			cout << "Exp상승! :  +" << m_pMonster->Get_Info().iExp << endl;
			cout << "Gold상승! :  +" << m_pMonster->Get_Info().iGold << endl;
			system("pause");

			break;

		case 2:
			pPlayer->ResetHp();
			system("pause");
			break;
		default:
			break;
		}

	}

}

void Field::Relese()
{
	SAFE_DELETE(m_pMonster);
}

void Field::set_player(Player* _pPlayer)
{
	pPlayer = _pPlayer;
}

int Field::Battle()
{
	int select = 0;

	while (true) {
		system("cls");
		CMainGame::Logo();
		pPlayer->Render();
		m_pMonster->Render();
		cout << " 1.공격2.도망" << endl;
		cout << "------------------------" << endl;
		cout << "입력" << endl;
		cin >> select;
		switch (select) {
		case 1:
			m_pMonster->Set_Damage(pPlayer->Get_Info().iAtt);
			cout << " 몬스터 HP가" << pPlayer->Get_Info().iAtt << "줄음" << endl;
			system("pause");

			if (m_pMonster->Get_Info().iHp <= 0)
			{
				cout << "승리했습니다." << endl;
				system("pause");
				return 1;
			}
			else
			{
				pPlayer->Set_Damage(m_pMonster->Get_Info().iAtt);
				cout << " 플레이어 HP가" << m_pMonster->Get_Info().iAtt << "줄음" << endl;
				system("pause");

				if (pPlayer->Get_Info().iHp <= 0)
				{
					cout << "패배했습니다." << endl;
					system("pause");
					return 2;
				}
				else
				{
					continue;
				}
			}
			break;

		case 2:
			return 0;

		default:
			cout << "올바른 입력이 아닙니다." << endl;
			system("pause");
			continue;

		}

	}

	return 0;
}
