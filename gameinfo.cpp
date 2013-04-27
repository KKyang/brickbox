#include"stdafx.h"

char PlayerName[10];
extern int speed;

void Getmousexy(int *x, int *y, int *button);

void gameinfo(int *hit, int ballLife)       //
{
	gotoxy(58, 5);
	printf("Player:");
	for(int i=0;i<=10;i++)
		printf("%c",PlayerName[i]);

	gotoxy(58,6);
	printf("score:%i", *hit);

	gotoxy(58,7);
	printf("Life:%i", ballLife);
}

int selectmode()
{
	int x=0;
	int y=0;

	gotoxy(58,10);
	printf("Enter your name:");
	gotoxy(58,11);
		scanf("%10s", &PlayerName);

	gotoxy(58,10);
	printf("                 ");
	gotoxy(58,11);
	printf("                 ");



	gotoxy(58,15);
	printf("Slect your game speed");
	gotoxy(60,16);
	printf("1.Slow");
	gotoxy(60,17);
	printf("2.Medium");
	gotoxy(60,18);
	printf("3.Quick");

	while(1)
	{
		int key;
		Getmousexy(&x, &y, &key);
		if(key==0x1 && (y==15 || y==16 || y==17) && (x>=59 && x<=65))
			 break;
	}

	if(y==15){
		gotoxy(60,17);
		printf("        ");
		gotoxy(60,18);
		printf("        ");
		speed=100;
	}
	else if(y==16){
		gotoxy(60,16);
		printf("        ");
		gotoxy(60,18);
		printf("        ");	
		speed=80;
	}
	else if(y==17){
		gotoxy(60,16);
		printf("        ");
		gotoxy(60,17);
		printf("        ");
		speed=65;
	}


	gotoxy(58,20);
	printf("Select your difficulty");
    gotoxy(60,21);
	printf("1.Hard");
	gotoxy(60,22);
	printf("2.Normal");

	while(1)
	{
		int key;
		Getmousexy(&x, &y, &key);
		if(key==0x1 && (y==20 || y==21) && (x>=59 && x<=65))
			 break;
	}




	if(y==20){
		gotoxy(60,22);
		printf("        ");
		return 1;
	}
	else if(y==21){
		gotoxy(60,21);
		printf("        ");
		return 2;
	}
	return 2;
}

void Getmousexy(int *x, int *y, int *button)
{
  INPUT_RECORD Buffer;
  DWORD        NumberOfEventsRead;

  ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &Buffer, 1, &NumberOfEventsRead);    
  *x = Buffer.Event.MouseEvent.dwMousePosition.X;
  *y = Buffer.Event.MouseEvent.dwMousePosition.Y;
  *button = Buffer.Event.MouseEvent.dwButtonState;
}