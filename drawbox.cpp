#include"stdafx.h"


void drawbox()
{
	textbackground(WHITE);

	gotoxy(2,2);
	for(int i=0;i<=49;i++)	
		printf(" ");

	gotoxy(2,35);
	for(int i=0;i<=49;i++)
		printf(" ");
	
	int verti;
    
    for(verti=2;verti<=35;verti++)
	{
		gotoxy(2,verti);
		printf(" ");
	}

	for(verti=2;verti<=35;verti++)
	{
		gotoxy(51,verti);
		printf(" ");
	}

	textbackground(BLACK);
}

