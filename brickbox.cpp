// brickbox.cpp : 定義主控台應用程式的進入點。
//

#include "stdafx.h"
extern int hit;
int mode;

void intro();

int _tmain(int argc, _TCHAR* argv[])
{

	int game=1;
	int x;
	int y;

	srand(time(NULL));


	while(game){

	setsizexy(80,40);
	_setcursortype(1);
	
	intro();
	drawbox();
	mode=selectmode();
	gamesystem(mode);

	highscore();

	gotoxy(54,25);
	printf("DO YOU WANT TO PLAY AGAIN?");
	gotoxy(58,26);
	printf("YES");
	gotoxy(58,27);
	printf("NO");

	while(1)
	{
		int key;
		Getmousexy(&x, &y, &key);
		if(key==0x1 && (y==25 || y==26) && (x>=57 && x<=60))
			 break;
	}

	if(y==25)
		game=1;
	else if(y==26)
		game=0;
	gotoxy(54,25);
	printf("                           ");
	gotoxy(58,26);
	printf("    ");
	gotoxy(58,27);
	printf("    ");

	for(int i=3;i<35;i++){
		gotoxy(3,i);
	for(int j=3;j<51;j++)
		printf(" ");
	}

	hit=0;


	}

	return 0;
}


void intro(){
	gotoxy(3,37);
	printf("BUTTON A-LEFT    BUTTON D-RIGHT    SPACE-SERVICE");
	gotoxy(3,38);
	printf("USE THE MOUSE TO CHOOSE THE SELECTIONS");
}



