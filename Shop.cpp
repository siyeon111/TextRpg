#include"stdafx.h"
#include "Shop.h"
#include"Enum.h"
#include"Obj.h"
#include"Inven.h"
#include"Item.h"
#include"Player.h"
#include "MainGame.h"


Shop::Shop() {
}

Shop::Shop(Player* player) {
	pPlayer = player;
}

Shop::~Shop() {

	vector<Item*>::iterator iter = SwordList.begin();
	vector<Item*>::iterator iter1 = ArmorList.begin();

	for (; iter != SwordList.end();)
	{
		SAFE_DELETE(*iter);
		++iter;
	}
	for (; iter1 != ArmorList.end();)
	{
		SAFE_DELETE(*iter1);
		++iter1;
	}

	SwordList.clear();
	ArmorList.clear();
}

void Shop::Initialize() {
	Item* Wepon_List;

	Wepon_List = new Item((INFO&)INFO("�����ũ", 1, 0, 0, 30));
	SwordList.push_back(Wepon_List);
	Wepon_List->Set_Type(ITEM::SWORD);

	Wepon_List = new Item((INFO&)INFO("��������", 0, 5, 0, 30));
	ArmorList.push_back(Wepon_List);
	Wepon_List->Set_Type(ITEM::ARMOR);

	Wepon_List = new Item((INFO&)INFO("���󰡶���", 7, 0, 0, 80));
	SwordList.push_back(Wepon_List);
	Wepon_List->Set_Type(ITEM::SWORD);

	Wepon_List = new Item((INFO&)INFO("Ǯũ����Ż �Ƹ�", 0, 32, 0, 80));
	ArmorList.push_back(Wepon_List);
	Wepon_List->Set_Type(ITEM::ARMOR);

	Wepon_List = new Item((INFO&)INFO("����Į����", 68, 0, 0, 250));
	SwordList.push_back(Wepon_List);
	Wepon_List->Set_Type(ITEM::SWORD);

	Wepon_List = new Item((INFO&)INFO("�巡�� �Ƹ�", 0, 230, 0, 250));
	ArmorList.push_back(Wepon_List);
	Wepon_List->Set_Type(ITEM::ARMOR);
}

void Shop:: Progress() {

	int iSelect;

	while (true)
	{
		system("cls");
		CMainGame::Logo();
		pPlayer->Render();
		cout << "1.��� 2.�ȱ� 3.������" << endl;
		cout << "========================================================" << endl;
		cout << "�Է�: ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			sellct();
			break;
		case 2:
			Equip_Sell();
			break;
		case 3:
			return;
		default:
			break;
		}
	}	
}

void Shop::sellct() {

	int iSelect;

	system("cls");
	CMainGame::Logo();

	pPlayer->Render();
	cout << "1.���� 2.�� 3.������" << endl;
	cout << "========================================================" << endl;
	cout << "�Է�: ";
	cin >> iSelect;

	switch (iSelect)
	{
	case 1:
		Sword();
		break;
	case 2:
		Armor();
		break;
	case 3:
		return;
	default:
		break;
	}
}

void Shop::Equip_Sell() {
	int iSelect;

	system("cls");
	CMainGame::Logo();
	pInven->Render();

	if (pInven->Get_Inven().size() == 0)
		return;

	cin >> iSelect;

	pInven->Sell_Item(iSelect);
}

void Shop::Sword() {
	int iSelect;

	vector<Item*> ::iterator itr;
	itr = SwordList.begin();

	system("cls");
	CMainGame::Logo();

	pPlayer->Render();
	for (int i = 0; i < SwordList.size(); i++ ) {
		cout << i + 1 << "�� ���� " << endl;;
		SwordList[i]->Render();

		itr++;
		if (itr == SwordList.end()) {
			cout << i + 2 << ".������" << endl;
		}
		
	}

	cout << "========================================================" << endl;
	cout << "�Է�: ";
	cin >> iSelect;

	if (0 < iSelect && iSelect <=  SwordList.size()) {
		ButSell(iSelect - 1, SWORD);
	}
	else{	
		return;
	}		
}

void Shop::Armor() {
	int iSelect;

	vector<Item*> ::iterator itr;
	itr = ArmorList.begin();

	system("cls");
	CMainGame::Logo();

	pPlayer->Render();
	for (int i = 0; i < ArmorList.size(); i++) {
		cout << i + 1 << "�� �� " << endl;;
		ArmorList[i]->Render();

		itr++;
		if (itr == ArmorList.end()) {
			cout << i + 2 << ".������" << endl;
		}

	}

	cout << "========================================================" << endl;
	cout << "�Է�: ";
	cin >> iSelect;

	if (0 < iSelect && iSelect<= ArmorList.size()) {
		ButSell(iSelect - 1, ARMOR);
	}
	else {
		return;
	}
}

void Shop::ButSell(int _iSelect, ITEM _Wepon) {
	int iSelect;

	while (true)
	{
		system("cls");
		CMainGame::Logo();

		pPlayer->Render();

		if (_Wepon == SWORD) {
			SwordList[_iSelect]->Render();
		}
		else {
			ArmorList[_iSelect]->Render();
		}
		
		cout << "1.���� 2.���" << endl;
		cout << "========================================================" << endl;
		cout << "�Է�: ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			Equip_Buy(_iSelect, _Wepon);
			return;
		case 2:
			return;
		default:
			break;
		}
	}
}

void Shop::Equip_Buy(int _iSelect, ITEM _Wepon) {
	if (_Wepon == SWORD) {
		vector<Item*> Wepon(SwordList);
		Butcheck(_iSelect, Wepon);
	}
	else {
		vector<Item*> Wepon(ArmorList);
		Butcheck(_iSelect, Wepon);
	}
}

void Shop::Butcheck(int _iSelect, vector<Item*> Wepon) {
	vector<Item*> ::iterator itr;
	itr = Wepon.begin();
	itr += _iSelect;


	if (pPlayer->Get_Info().iGold >= Wepon.at(_iSelect)->Get_Info().iGold) {

		pPlayer->Set_Gold(-Wepon.at(_iSelect)->Get_Info().iGold);	
		Item* forBuy = new Item(*itr);
		pInven->Gain_Item(forBuy);

		cout << "�������� �����߽��ϴ�." << endl;		
	}
	else {
		cout << "�̹� �����ϰ� �ְų� ��尡 �����մϴ�." << endl;
	}

	system("pause");
}

void Shop::Render() {
}