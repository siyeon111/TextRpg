#include "MainGame.h"
#include "stdafx.h"
#include "Obj.h"
#include "Player.h"
#include "Town.h"
#include "Inven.h"
#include "Item.h"
#include "Field.h"


CMainGame::CMainGame()
{
	m_pPlayer = nullptr;
}


CMainGame::~CMainGame()
{
	Release();
}

bool CMainGame::Initialize()
{
	Select_Job();

	if (nullptr == m_Inven)
	{
		m_Inven = new Inven;
		m_Inven->Set_Player(m_pPlayer);
		m_Inven->Initialize();
	}
	if (nullptr == m_pTown)
	{
		m_pTown = new Town;
		m_pTown->Set_Player(m_pPlayer);
		m_pTown->Set_Inven(m_Inven);
		m_pTown->Initialize();
	}
	if (nullptr == m_pField) {
		m_pField = new Field;
		m_pField->set_player(m_pPlayer);

	}

	if (nullptr == m_pPlayer)
		return false;
	if (nullptr == m_pTown)
		return false;
	if (nullptr == m_pField)
		return false;

	return true;
}

void CMainGame::Progress()
{
	int iSelect = 0;

	while (true)
	{
		system("cls");
		Logo();
		m_pPlayer->Render();
		cout << "1.���� 2.�κ� 3.���� 4.���� 5.����" << endl;
		cout << "========================================================" << endl;
		cout << "�Է�: ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			m_pField->Progress(); 
			break;
		case 2:
			m_Inven->Progress();
			break;
		case 3:
			m_pTown->Progress();
			break;
		case 4:
			Save_Data();
			break;
		case 5:
			return;
		default:
			break;
		}
	}
}

void CMainGame::Release()
{
	SAFE_DELETE(m_pPlayer);
	SAFE_DELETE(m_Inven);
	SAFE_DELETE(m_pTown);
	SAFE_DELETE(m_pField);
}

void CMainGame::colorText(int colorSet) {
	/*
		���� 0
		��ο� �Ķ� 1
		��ο� �ʷ� 2
		��ο� �ϴ� 3
		��ο� ���� 4
		��ο� ���� 5
		��ο� ��� 6
		ȸ�� 7
		��ο� ȸ�� 8
		�Ķ� 9
		�ʷ� 10
		�ϴ� 11
		���� 12
		���� 13
		��� 14
		�Ͼ� 15
	*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorSet);
}

void CMainGame::Select_Job()
{
	int iSelect = 0;

	while (true)
	{
		system("cls");

		Logo();

		cout << "           1.���� 2.������ 3.���� 4.�ҷ����� 5.����" << endl;
		cout << "==================================================================" << endl;
		cout << "�Է�: ";
		cin >> iSelect;
		INFO temp;
		switch (iSelect)
		{
		case 1:
			temp = INFO("����", 10, 500);
			m_pPlayer = new Player(temp);
			break;
		case 2:
			temp = INFO("������", 30, 200);
			m_pPlayer = new Player(temp);
			break;
		case 3:
			temp = INFO("����", 20, 300);
			m_pPlayer = new Player(temp);
			break;
		case 4:
			Load_Data();
			break;
		case 5:
			return;
		default:
			continue;
		}

		if (nullptr != m_pPlayer)
		{
			m_pPlayer->Initialize();
			break;
		}

	}
}

void CMainGame::Load_Data()
{
	FILE* fp = nullptr;

	errno_t err = fopen_s(&fp, "Save.txt", "rb");

	if (0 == err)
	{
		INFO tTemp;
		fread(&tTemp, sizeof(INFO), 1, fp);
		m_pPlayer = new Player;
		m_pPlayer->Set_Info(tTemp);

		m_Inven = new Inven;
		m_Inven->Initialize();
		m_Inven->Set_Player(m_pPlayer);

		Item* pItem = nullptr;
		bool	bEq = false;
		ITEM		eType = ITEM_END;

		size_t iSize = 0;
		fread(&iSize, sizeof(size_t), 1, fp);

		for (size_t i = 0; i < iSize; ++i)
		{
			fread(&tTemp, sizeof(INFO), 1, fp);
			fread(&bEq, sizeof(bool), 1, fp);
			fread(&eType, sizeof(ITEM), 1, fp);

			pItem = new Item(tTemp);
			pItem->Initialize();
			pItem->Set_Eq(bEq);
			pItem->Set_Type(eType);

			m_Inven->Get_Inven().push_back(pItem);

			if (bEq == true)
				m_pPlayer->LoadItem(pItem);
		}
		cout << "�ҷ����� ����" << endl;
		fclose(fp);
		system("pause");
	}
	else
	{
		cout << "�ҷ����� ����" << endl;
		system("pause");
	}


}

void CMainGame::Save_Data()
{
	FILE* fp = nullptr;                                                                                                                                                                                                                                                                                                 

	errno_t err = fopen_s(&fp, "Save.txt", "wb");

	if (0 == err)
	{
		fwrite(&m_pPlayer->Get_Info(), sizeof(INFO), 1, fp);

		const vector<Item*>& rInven = m_Inven->Get_Inven();
		size_t iSize = rInven.size();
		fwrite(&iSize, sizeof(size_t), 1, fp);

		for (size_t i = 0; i < iSize; ++i)
		{
			bool tt = rInven[i]->GetEquip();
			ITEM t = rInven[i]->GetType();
			fwrite(&(rInven[i]->Get_Info()), sizeof(INFO), 1, fp);
			fwrite(&tt, sizeof(bool), 1, fp);
			fwrite(&t, sizeof(ITEM), 1, fp);
		}
		cout << "���� ����" << endl;
		fclose(fp);
		system("pause");
	}
	else
	{
		cout << "���� ����" << endl;
		system("pause");
	}

}

void CMainGame::Logo()
{
	colorText(1);
	printf("\n ######   ######   ##  ##   ######     #####    #####     #####\n");
	printf("   ##     ##       ##  ##     ##       ##  ##   ##  ##   ##    \n");
	colorText(3);
	printf("   ##     #####     ####      ##       ##  ##   ##  ##   ##    \n");
	printf("   ##     ##        ####      ##       #####    #####    ## ###\n");
	colorText(11);
	printf("   ##     ##       ##  ##     ##       ## ##    ##       ##  ##\n");
	printf("   ##     ######   ##  ##     ##       ##  ##   ##        #####\n\n");
	printf("=================================================================");
	cout << endl;
	colorText(15);
}




