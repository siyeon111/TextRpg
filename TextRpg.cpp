// TextRPG.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "MainGame.h"

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand(unsigned(time(NULL)));

	CMainGame	MainGame;

	//bool bCheck = MainGame.Initialize();

	if(MainGame.Initialize())
		MainGame.Progress();

    return 0;
}

