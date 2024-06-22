#include "Dino.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

#define DINO_X 0
#define DINO_Y 15
#define TREE_X 94
#define TREE_Y 25

int treeX = TREE_X;
int dinoX = DINO_X;
int dinoY = DINO_Y;

int key = 0; //Ű���� �Է� �ޱ�

Dino::Dino()
{
}
void Dino::setting()
{
	//�ܼ�â ����
	system("Title.EsterEgg.By.Lim");
	system("mode con:cols=100 lines=30");

	//Ŀ�� ����
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.dwSize = 1;
	ConsoleCursor.bVisible = 0; //Ŀ�� ����
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);
}

void Dino::gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Dino::start()
{
	//���� ȭ��
	while (1) {
		gotoxy(30, 10);
		printf("Press 'Space bar' to start the game");
		draw_dino(0);

		if (_kbhit()) {
			key = _getch();
			if (key == 32) { //'�����̽� ��' �Է� Ȯ��
				system("cls");
				break;
			}
		}
	}
}

int Dino::game(int tic)
{
	score(tic);
	tree();
	draw_dino(tic);

	Sleep(20); //0.02��		//������ ����
	tic++;
	return tic;
}

void Dino::score(int tic)
{
	//���� ���
	gotoxy(45, 1);
	printf("score : %4d", tic / 5 * 10); // tic/5 �� 10��		//�ʵ� �� 4ĭ Ȯ�� (nõ������)
}

void Dino::end(int tic)
{
	//���� ȭ��
	system("cls");
	int a = 10;
	gotoxy(a, a);		printf(" #####      ##    ##   ##  #######            #####    ##  ##  #######   ######  \n");
	gotoxy(a, a + 1);	printf("##   ##    ####   ### ###   ##  ##           ##   ##   ##  ##   ##  ##   ##  ##  \n");
	gotoxy(a, a + 2);	printf("##        ##  ##  #######   ##               ##   ##   ##  ##   ##       ##  ##  \n");
	gotoxy(a, a + 3);	printf("##        ######  ## # ##   ####             ##   ##   ##  ##   ####     #####   \n");
	gotoxy(a, a + 4);	printf("##  ###   ##  ##  ##   ##   ##               ##   ##   ##  ##   ##       ####    \n");
	gotoxy(a, a + 5);	printf("##   ##   ##  ##  ##   ##   ##  ##           ##   ##    ####    ##  ##   ## ##   \n");
	gotoxy(a, a + 6);	printf(" #####    ##  ##  ##   ##  #######            #####      ##    #######   ###  ## \n");

	gotoxy(40, 20);
	printf("final score : %4d", tic / 5 * 10); //���� ����
}

int Dino::progress()
{
	int tic = 0; //���� �� �ð� �������� ���� ���� ���
	int crash = 0; //�浹 üũ

	setting();
	start();

	while (1) {

		tic = game(tic);

		//'�����̽� ��' ������ ����
		if (_kbhit()) {
			key = _getch();
			if (key == 32 && dinoY - 15 == 0) { //'�����̽� ��'�� ������ ������ �ٴڿ� ���� ��

				int h = 0; //���� ���� �ʱ�ȭ

				while (h < 8) { //y������ 8ĭ ���
					earase_dino();
					dinoY--;
					tic = game(tic);
					crash = crashing();
					if (crash == -1)
						break;
					h++;
				}

				while (h > 0) { //y������ 8ĭ �ϰ�
					tic = game(tic);
					crash = crashing();
					if (crash == -1)
						break;
					dinoY++;
					earase_dino();
					h--;
				}
			}
		}
		crash = crashing();
		if (crash == -1) //�浹 �� Ż��
			break;
	}

	end(tic);

	system("pause>>null");
	return 0;
}

void Dino::draw_dino(int tic)
{
	//���� �׸���

	int toc = tic % 8;
	//����
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	gotoxy(dinoX, dinoY);			printf("              @@@@@@@@\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	gotoxy(dinoX, dinoY + 1);		printf("             @@@@@@@@@@@\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	gotoxy(dinoX, dinoY + 2);		printf("             @@@ @@@@@@@\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	gotoxy(dinoX, dinoY + 3);		printf("             @@@@@@@@@@@\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gotoxy(dinoX, dinoY + 4);		printf("             @@@@@@\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	gotoxy(dinoX, dinoY + 5);		printf("     *      @@@@@@@@@@\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
	gotoxy(dinoX, dinoY + 6);		printf("     @     @@@@@@\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	gotoxy(dinoX, dinoY + 7);		printf("     @@  @@@@@@@@@@@@\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	gotoxy(dinoX, dinoY + 8);		printf("     @@@@@@@@@@@@   @\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	gotoxy(dinoX, dinoY + 9);		printf("     @@@@@@@@@@@@\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	gotoxy(dinoX, dinoY + 10);		printf("      @@@@@@@@@@\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
	gotoxy(dinoX, dinoY + 11);		printf("       @@@@@@@@\n");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(dinoX, dinoY + 12);		printf("         @@@@@@\n");


	//�� ������ ����
	if (toc >= 0 && toc <= 3) //4tic ���� ����
	{
		earase_foot();
		gotoxy(dinoX, dinoY + 13); //�� �׸���
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("         @    @@@\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("         @@");
	}
	else
	{
		earase_foot();
		gotoxy(dinoX, dinoY + 13); //�� �׸���
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		printf("         @@@  @\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		printf("              @@");
	}
}

void Dino::earase_foot()
{
	//�� �����
	gotoxy(dinoX, dinoY + 13);
	printf("                 \n");
	printf("                 ");
}

void Dino::earase_dino()
{
	//���� �����
	for (int i = 0; i < 24; i++) {
		gotoxy(dinoX, 6 + i);
		printf("                              ");
	}
	earase_foot();
}

void Dino::tree()
{
	//���� �����ʿ��� �������� �̵�
	treeX--; //�������� �� ĭ �̵�
	erase_tree(); //�����
	draw_tree(); //�׸���

	if (treeX == 0)
		treeX = TREE_X; //������ ���� ������ �̵��ϸ� �ʱ�ȭ
}

void Dino::draw_tree()
{
	//���� �׸���
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gotoxy(treeX + 2, TREE_Y);			printf("##\n");
	gotoxy(treeX, TREE_Y + 1);		  printf("# ## #\n");
	gotoxy(treeX, TREE_Y + 2);		  printf("######\n");
	gotoxy(treeX + 2, TREE_Y + 3);		printf("##\n");
	gotoxy(treeX + 2, TREE_Y + 4);		printf("##");
}

void Dino::erase_tree()
{
	//���� �����
	gotoxy(treeX + 3, TREE_Y);		  printf("  \n");
	gotoxy(treeX + 1, TREE_Y + 1);	printf("      \n");
	gotoxy(treeX + 1, TREE_Y + 2);	printf("      \n");
	gotoxy(treeX + 3, TREE_Y + 3);	  printf("  \n");
	gotoxy(treeX + 3, TREE_Y + 4); 	  printf("  ");
}

int Dino::crashing()
{
	//�浹 ����	//���̵� '��'
   // (����1 && ����2) && ����
   // ����1: ������ ���� 11ĭ���� �ڿ� ����
   // ����2: ������ ���� 15ĭ���� �տ� ����
   // ����1 && ����2: ������ ���� 11ĭ�� 15ĭ ���̿� ����
   // ����: ���� �� 3ĭ�� ���� 5ĭ ���� ���̰� ���ų� ���� ��
	if ((dinoX + 6 <= treeX + 2 && dinoX + 10 >= treeX + 2) && dinoY + 12 >= TREE_Y + 2)
		return -1;
	else
		return 0;
}
