#pragma once
class Dino
{
public:
	Dino();
	void setting();
	void gotoxy(int x, int y);
	void start();
	int game(int);
	void score(int);
	int crashing();
	void end(int);
	void draw_dino(int);
	void earase_foot();//발 지우기
	void earase_dino();
	void tree();
	void draw_tree();
	void erase_tree();
	int progress();
};

