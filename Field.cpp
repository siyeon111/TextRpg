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
		cout << " 1.�縷2.�ؾ�3.����4.����" << endl;
		cout << "------------------------" << endl;
		cout << "�Է�" << endl;
		cin >> select;

		switch (select)
		{
		case 1:
			m_pMonster = new Monster((INFO&)INFO("����-�Ƿ��", 1, 1, 1));
			break;
		case 2:
			m_pMonster = new Monster((INFO&)INFO("ũ����", 10, 10, 10));
			break;
		case 3:
			m_pMonster = new Monster((INFO&)INFO("��Ȧ��", 100, 100, 100));
			break;
		case 4:
			return;
		default:
			cout << "�ùٸ� �Է��� �ƴմϴ�." << endl;;
			system("pause");
			continue;
		}
		m_pMonster->Initialize();

		switch (Battle())
		{
		case 1:
			pPlayer->ExpUp(m_pMonster->Get_Info().iExp);
			pPlayer->Set_Gold(m_pMonster->Get_Info().iGold);

			cout << "Exp���! :  +" << m_pMonster->Get_Info().iExp << endl;
			cout << "Gold���! :  +" << m_pMonster->Get_Info().iGold << endl;
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
		cout << " 1.����2.����" << endl;
		cout << "------------------------" << endl;
		cout << "�Է�" << endl;
		cin >> select;
		switch (select) {
		case 1:
			m_pMonster->Set_Damage(pPlayer->Get_Info().iAtt);
			cout << " ���� HP��" << pPlayer->Get_Info().iAtt << "����" << endl;
			system("pause");

			if (m_pMonster->Get_Info().iHp <= 0)
			{
				cout << "�¸��߽��ϴ�." << endl;
				system("pause");
				return 1;
			}
			else
			{
				pPlayer->Set_Damage(m_pMonster->Get_Info().iAtt);
				cout << " �÷��̾� HP��" << m_pMonster->Get_Info().iAtt << "����" << endl;
				system("pause");

				if (pPlayer->Get_Info().iHp <= 0)
				{
					cout << "�й��߽��ϴ�." << endl;
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
			cout << "�ùٸ� �Է��� �ƴմϴ�." << endl;
			system("pause");
			continue;

		}

	}

	return 0;
}
