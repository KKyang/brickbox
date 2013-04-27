#include"stdafx.h"

void erasescreen(int, int);
void movepad(int *x, int *length, int padplaceverti, char *inputkey, int mode);
void drawpad(int padplace, int, int, int padplaceverti);
void brickDraw(int x,int y,int *life, int length);
void placebrick(int bricklength);
void checkthings(int x, int y, int life, int thing);

#define brick_x   7
#define brick_y   5
int hit=0;
int speed;


struct Bricks{
	int x;
	int y;
	int life;
	int thing;
}Bricks[brick_x][brick_y];


//3,3~49,33
void gamesystem(int mode)
{
	int ballposition[2];                   //only change the hori
	int verti=1;
	int hori=1;                                   //left or right 
	int padplace=25;
	int padplaceold=padplace;
	int padlength=10;
	int bricklength=6;
	int padplaceverti=33;
	char inputkey=0;


	int ballLife=mode+1;
	int ballLife_1=ballLife;

	int brick_xx;
	int brick_yy;



	gameinfo(&hit, ballLife);
	drawpad(padplace, padplaceold,padlength, padplaceverti);

	ballposition[0]=padplace+padlength/2-1;
	ballposition[1]=padplaceverti-1;
	gotoxy(ballposition[0],ballposition[1]);
	printf("¡³");

	placebrick(bricklength);


	while(!GetAsyncKeyState(27) && ballLife>0){
	
		while(!GetAsyncKeyState(32))
		{
			ballposition[0]=padplace+padlength/2-1;
			ballposition[1]=padplaceverti-1;
			gotoxy(ballposition[0],ballposition[1]);
			printf("¡³");

			inputkey=0;
			padplaceold=padplace;
			movepad(&padplace, &padlength, padplaceverti,&inputkey, mode);

			if(padplaceold!=padplace)
			{
				erasescreen(ballposition[0],ballposition[1]);
				drawpad(padplace, padplaceold,padlength, padplaceverti);
				ballposition[0]=padplace+padlength/2-1;
				ballposition[1]=padplaceverti-1;
				gotoxy(ballposition[0],ballposition[1]);
				printf("¡³");
			}
			delay(speed);
		}

	
		ballLife_1=ballLife;

		while(!GetAsyncKeyState(27)&&ballLife_1>0)
		{
    

		inputkey=0;
		gotoxy(ballposition[0],ballposition[1]);
		printf("¡³");

		padplaceold=padplace;
		movepad(&padplace, &padlength, padplaceverti, &inputkey, mode);
		drawpad(padplace, padplaceold,padlength, padplaceverti);


		delay(speed);                                    //delay time can later be changed
		erasescreen(ballposition[0],ballposition[1]);


		if(ballposition[1]+verti==padplaceverti && verti==1)
		{
			if(ballposition[0]>=padplace && ballposition[0]<=padplace+padlength)
			{
				verti=-1;

				////////////////////////////////////////////

				if(GetAsyncKeyState(65))
					ballposition[0]-=1;
				if(GetAsyncKeyState(68))
					ballposition[0]+=1;

			}
		}



		if(ballposition[0]+hori>49)
			hori=-1;
		else if(ballposition[0]+hori<3)
			hori=1;
		if(ballposition[1]+verti>34)
		{
			ballLife--;
			ballLife_1=0;
		}
		else if(ballposition[1]+verti<3)
			verti=1;


		if(hori==1)
			brick_xx=(ballposition[0]-2)/7;
		else if(hori==-1)
			brick_xx=(ballposition[0]-3)/7;
		brick_yy=(ballposition[1]+verti-3)/3;

		if((ballposition[1]+verti)==Bricks[brick_xx][brick_yy].y && Bricks[brick_xx][brick_yy].life>0)
		{
			
			if(ballposition[0]>=(Bricks[brick_xx][brick_yy].x-1) && ballposition[0]<=Bricks[brick_xx][brick_yy].x+bricklength)
			{
				verti=-verti;
				Bricks[brick_xx][brick_yy].life--;
				brickDraw(Bricks[brick_xx][brick_yy].x,Bricks[brick_xx][brick_yy].y, &Bricks[brick_xx][brick_yy].life, bricklength);
				printf("\a");
				hit+=10;

				//checkthings(Bricks[brick_xx][brick_yy].x,Bricks[brick_xx][brick_yy].y, Bricks[brick_xx][brick_yy].life, Bricks[brick_xx][brick_yy].thing);
			}
			else if(ballposition[0]==(Bricks[brick_xx][brick_yy].x-2) || ballposition[0]==(Bricks[brick_xx][brick_yy].x+bricklength+1))
			{
				verti=-verti;
				hori=-hori;
				Bricks[brick_xx][brick_yy].life--;
				brickDraw(Bricks[brick_xx][brick_yy].x,Bricks[brick_xx][brick_yy].y, &Bricks[brick_xx][brick_yy].life, bricklength);
				printf("\a");
				hit+=10;
				//checkthings(Bricks[brick_xx][brick_yy].x,Bricks[brick_xx][brick_yy].y, Bricks[brick_xx][brick_yy].life, Bricks[brick_xx][brick_yy].thing);
			}
		}

		



		ballposition[0]+=hori;
		ballposition[1]+=verti;





		gameinfo(&hit, ballLife);

		int checkfinish=0;

		for(int j=0; j<brick_y;j++)
			for(int i=0;i<brick_x;i++)
			{
				if(Bricks[i][j].life!=0)
					  checkfinish=1;	
			}

		if(checkfinish==0){
			hit=ballLife*100+hit;
			inputkey=27;
		}
		}
	}


}

void drawpad(int padplace, int padplaceold,int length, int padplaceverti)
{
	gotoxy(padplaceold, padplaceverti);                               //erasepad
	for(int i=0;i<length;i++)
		printf(" ");
	textbackground(WHITE);
	gotoxy(padplace, padplaceverti);
	for(int i=0;i<length;i++)
		printf(" ");

	textbackground(BLACK);
}

void movepad(int *x, int *length, int padplaceverti, char *inputkey, int mode)
{
	if(GetAsyncKeyState(65))
	{
		if(*x>3)
			*x=*x-mode;
	}
	else if(GetAsyncKeyState(68))
	{
		if(*x+*length<=50)
			*x=*x+mode;
	}


}


void erasescreen(int x, int y)  //erasetheball
{
	gotoxy(x,y);
	printf("  ");
}



void brickDraw(int x,int y,int *life, int length)
{
	int color;
	gotoxy(x,y);
    
    if(*life==3)
		color=4;
	else if(*life==2)
		color=14;
	else if(*life==1)
		color=1;
	else if(*life==0)
		color=0;

	textbackground(color);
	for(int i=0;i<length;i++)
		printf(" ");

	textbackground(BLACK);
}

void placebrick(int bricklength)
{
	for(int j=0; j<brick_y;j++)
		for(int i=0;i<brick_x;i++)
		{
			Bricks[i][j].x=3+7*i;
			Bricks[i][j].y=3+3*j;
			Bricks[i][j].life=rand()%3+1;
			Bricks[i][j].thing=rand()%20+1;
			brickDraw(Bricks[i][j].x,Bricks[i][j].y, &Bricks[i][j].life, bricklength);
		}
}

void checkthings(int x, int y, int life, int thing )
{
	/*life=life+1;
	if(life==1){

		if(thing==1)

		else if(thing>=2 && thing<=4)

		else if(thing>=5 && thing<=20)

	}*/
}