#include"stdafx.h"
#include"Casino.h"
#include"Player.h"
#include<time.h>
#include <windows.h>

#define TIMER_END 150


Casino::Casino() {

}

Casino::Casino(Player* Player) {
	pPlayer = Player;
}

void Casino::Progress() {
	int iSelect;

	while (true) {

		system("cls");
		pPlayer->Render();
		logo();
		std::cout << "                 1.게임 시작 0.나가기" << endl;
		std::cout << "========================================================" << endl;
		std::cout << "입력: ";
		cin >> iSelect;

		switch (iSelect)
		{
		case 1:
			Start();
			break;
		case 0:
			return;
		default:
			break;
		}
	}

}

bool Casino::Start() {
	int iSelect;

		while (true) {
			system("cls");
			pPlayer->Render();
			logo();
			std::cout << "배팅금액    1. 100   2. 200   3. 300   4. 400   0.나가기" << endl;
			std::cout << "========================================================" << endl;
			cin >> iSelect;

			if (pPlayer->Get_Info().iGold >= iSelect * 100)
			{
				switch (iSelect)
				{
				case 1:
					SoonStart(iSelect);
					break;
				case 2:
					SoonStart(iSelect);
					break;
				case 3:
					SoonStart(iSelect);
					break;
				case 4:
					SoonStart(iSelect);
					break;
				case 0:
					return false;
				default:
					break;
				}
			}
			else {
				std::cout << "플레이어의 소지금이 부족합니다." << endl;
				system("pause");
			}
		}

		return false;
}

bool Casino::SoonStart(int beting) {
		int iSelect;
		int bet = beting * 3;

		do {
			system("cls");
			pPlayer->Render();
			logo();
			std::cout << "배팅할 숫자를 골라주세요 (1 ~ " << bet << " )  0. 나가기" << endl;
			std::cout << "========================================================" << endl;
			std::cout << "배팅할 수 :"<< endl;
			cin >> iSelect;

			if (iSelect == 0) return false;
		} while (0 > iSelect || bet < iSelect);

		Game(bet, iSelect);	
}

bool Casino::Game(int bating, int pbating) {
	int bat = 1 + (rand() % bating);
	int coin = pPlayer->Get_Info().iGold;
	int LOL = (bating / 3) * 100;
	int timer = 0;

	system("cls");
	for (; timer <= TIMER_END;) {
		for (int i = 1; i <= 3; i++) {
			RullRat(i);	
			for (int r = 0; r < timer * 1000000; r++) {}
			timer++;
			system("cls");
			
		}
	}

	std::cout << "배팅한 수 : " << pbating << endl;
	std::cout << "나온 수 : " << bat << endl;
	std::cout << endl;

	if (bat == pbating) {
		pPlayer->Set_Gold(LOL);
		std::cout << "+" << LOL << "골드" << endl;
	}
	else {
		pPlayer->Set_Gold(-LOL);
		std::cout << "-" << LOL << "골드" << endl;
	}

	system("pause");

	return false;
	
}

void Casino::logo() {
	std::cout << endl;
	std::cout << "      =$  *#   !#$   =$  *$ ~##, ~###  ~, $#: $=      " << endl;
	std::cout << "     !#$   $  :###! ;#$:  * -##.  :##$   .##: $#!     " << endl;
	std::cout << "     !#$   !  :!$#! ~$##$:  -##. -;*##!  $##: $#!     " << endl;
	std::cout << "     !#$     .~.$#!  ;####; -##. -:-$#=, $##: $#!     " << endl;
	std::cout << "     !#$     -: $#$~,.~#### -##. -: $##: $##: $#!     " << endl;
	std::cout << "     !#$   = -=*###:!= .;## -##. -: .##: .##: $#!     " << endl;
	std::cout << "      =$  !!.-. .##;*#..;$, ~##, ~;  *#:  $#: $=      " << endl;
	std::cout << endl;
}

void Casino::RullRat(int roll) {
	if (roll == 1) {
		std::cout << "                        . - ~~~~~~~~~,                       " << endl;
		std::cout << "                  ,.:==.      !      :== -.                 " << endl;
		std::cout << "              ..#             !            *=.              " << endl;
		std::cout << "           -#-                !               .@            " << endl;
		std::cout << "          !. $                !              ~   ~;         " << endl;
		std::cout << "        ~.    ,=              !            =,      -!       " << endl;
		std::cout << "      !-        -!            !          !-          ,      " << endl;
		std::cout << "     ~            -~          !        ~,             :     " << endl;
		std::cout << "    -               -,        !       :,               ;    " << endl;
		std::cout << "   :                  ~-      !     ,,                  ;   " << endl;
		std::cout << "  .                     *-    !   -=                     ~  " << endl;
		std::cout << "  .                       =-  ! .=                       *  " << endl;
		std::cout << "  =                         !.!~                          . " << endl;
		std::cout << "  #**************************$#,..........................- " << endl;
		std::cout << "  !                         ~ - ~                           " << endl;
		std::cout << "  ,                       *.  -  .-                      =  " << endl;
		std::cout << "   ;                    !~    -    -;.                   ,  " << endl;
		std::cout << "   .                  .~      -      ~:,                ;   " << endl;
		std::cout << "    !               .:        -        ~~              ;    " << endl;
		std::cout << "     ;-            .~         -          -.           *     " << endl;
		std::cout << "       ,         ,;           -            ,        -!      " << endl;
		std::cout << "        ::     .$             -              -,    *        " << endl;
		std::cout << "          ,*  !               -                :*;          " << endl;
		std::cout << "            .,=               -              .#.            " << endl;
		std::cout << "               ,.!=           -          := ,               " << endl;
		std::cout << "                    ~~..***!~-:-!!**: -~.                   " << endl;
	}
	else if(roll == 2) {
		std::cout << "                            ....                            " << endl;
		std::cout << "                   ,- *==~        .*==-.-,                  " << endl;
		std::cout << "               .!# -               ,      -#..              " << endl;
		std::cout << "             @      :                         -$            " << endl;
		std::cout << "          $.         ~            .             ..:         " << endl;
		std::cout << "       .!-            ~           ~                ,:       " << endl;
		std::cout << "      ~-               :.        ~                   ~~     " << endl;
		std::cout << "     $~                 ;.       :                 -:.!~    " << endl;
		std::cout << "    *  .=;--             ;.     !              -,!=    .-   " << endl;
		std::cout << "   $         #! .         ~,    ~          . $~          ,  " << endl;
		std::cout << "  ~               #$        ;  ;        *#                . " << endl;
		std::cout << " ..                  . !$.   = ,    #,.                   ~ " << endl;
		std::cout << " -                        -,-==;*.-                       ! " << endl;
		std::cout << "                           ;:~:#~,!-                        " << endl;
		std::cout << "                      .: !.     ;   !! :-                   " << endl;
		std::cout << " -                -.;!       *   ;       :* -,            = " << endl;
		std::cout << "  ,           ..#,          ,     !           -#-..       . " << endl;
		std::cout << "           *$               $      ;               .@;   ~  " << endl;
		std::cout << "   $   #-..                ~        -                  . ,  " << endl;
		std::cout << "    *,                     ;         ,,                .-   " << endl;
		std::cout << "     --                   --          ~-              ~~    " << endl;
		std::cout << "      --                  :            ~-           -~      " << endl;
		std::cout << "        !-                ~             -,        -;,       " << endl;
		std::cout << "          -~.            !               -.     .$          " << endl;
		std::cout << "             ;=          ~                .   @             " << endl;
		std::cout << "               ..*$,    =                !$..               " << endl;
		std::cout << "                    ,-. :===*****==*, --.                   " << endl;
	}
	else if(roll == 3) {
		std::cout << "                   ,-, *==!;....;!==* ,-,                   " << endl;
		std::cout << "               .-#,    $             .,  -$ .               " << endl;
		std::cout << "            .@          .            .        @             " << endl;
		std::cout << "          $.            ;           :           .$          " << endl;
		std::cout << "       ,=-              ,,         ;              -!        " << endl;
		std::cout << "      -- .-;             :        ;                 -:      " << endl;
		std::cout << "    -:      --:          ~.      ;                    ;     " << endl;
		std::cout << "   -.          .*-        :     !                ,- *=.~    " << endl;
		std::cout << "  .               .*.     :    *           .. ;#-       ~   " << endl;
		std::cout << "  #                  ,#    *  #         :@:              #  " << endl;
		std::cout << " -                     . $ ~ !    ,#: .                   - " << endl;
		std::cout << " :                        ,,$=:.-,                          " << endl;
		std::cout << " =                     !:.:;~-,;                          : " << endl;
		std::cout << " =               :~.;;    ,~ *  ~~:                       : " << endl;
		std::cout << " ,         ,- **         ,~        ,!-                    . " << endl;
		std::cout << " -   .. =$.             .-    -       ~;.                ., " << endl;
		std::cout << "  ,@~                   ,                -#              *  " << endl;
		std::cout << "   !                  ..       .           . =          $   " << endl;
		std::cout << "   .;                .,        ,              ,-!      *    " << endl;
		std::cout << "     ;               -          ,                - !  ;     " << endl;
		std::cout << "      :~            ~           ~                   *-      " << endl;
		std::cout << "        !-         ;             :                -*        " << endl;
		std::cout << "          $,.     *              :             .,!          " << endl;
		std::cout << "             =!  #                *          *;             " << endl;
		std::cout << "               . *$.              -     ,#:..               " << endl;
		std::cout << "                    ,-, :*========*, ,-,                    " << endl;
	}

}