#pragma once
#include "stdafx.h"

extern char PlayerName[10];
extern int hit;
extern int mode;

struct scores{
	char name[10];
	int score;
}Scores[11];



void highscore(){

	if(mode==1){
		ifstream openfile("HIGHSCORE.DAT");

		if(openfile.fail()){
			ofstream savefile("HIGHSCORE.DAT");

			savefile<<PlayerName<<" "<<hit<<"\n";
			for(int i=0;i<9;i++)
				savefile<<"XXX"<<" "<<0<<"\n";
			savefile.close();

			ifstream openfile("HIGHSCORE.DAT");

			for(int i=0;i<10;i++)
			{
				openfile>>Scores[i].name>>Scores[i].score;
			}
		}
		else{
			for(int i=0;i<10;i++)
			{
				openfile>>Scores[i].name>>Scores[i].score;
			}

			openfile.close();

			sscanf(PlayerName,"%s",&Scores[10].name);
			Scores[10].score=hit;

		

			for(int i=0;i<11;i++)
				for(int j=0; j<10;j++)
					if(Scores[j].score<Scores[j+1].score)
						swap(Scores[j],Scores[j+1]);

			ofstream savefile("HIGHSCORE.DAT");

			for(int i=0;i<10;i++){
				savefile<<Scores[i].name<<" "<<Scores[i].score<<"\n";
			}
			savefile.close();

		}

	}

	else if(mode==2){
		ifstream openfile("HIGHSCORENORMAL.DAT");

		if(openfile.fail()){
			ofstream savefile("HIGHSCORENORMAL.DAT");

			savefile<<PlayerName<<" "<<hit<<"\n";
			for(int i=0;i<9;i++)
				savefile<<"XXX"<<" "<<0<<"\n";
			savefile.close();

			ifstream openfile("HIGHSCORENORMAL.DAT");

			for(int i=0;i<10;i++)
			{
				openfile>>Scores[i].name>>Scores[i].score;
			}
		}
		else{
			for(int i=0;i<10;i++)
			{
				openfile>>Scores[i].name>>Scores[i].score;
			}

			openfile.close();

			sscanf(PlayerName,"%s",&Scores[10].name);
			Scores[10].score=hit;

		

			for(int i=0;i<11;i++)
				for(int j=0; j<10;j++)
					if(Scores[j].score<Scores[j+1].score)
						swap(Scores[j],Scores[j+1]);

			ofstream savefile("HIGHSCORENORMAL.DAT");

			for(int i=0;i<10;i++){
				savefile<<Scores[i].name<<" "<<Scores[i].score<<"\n";
			}
			savefile.close();

		}
	}



	for(int i=3;i<35;i++){
		gotoxy(3,i);
	for(int j=3;j<51;j++)
		printf(" ");
	}

	string type;

	if(mode==1)
		type="HARD";
	if(mode==2)
		type="NORMAL";

	gotoxy(10,5);
	cout<<"HIGHSCORE "<<type<<" MODE";
       
	for(int i=0;i<=9;i++){
		gotoxy(11,6+i);
		printf("%2i.%10s     %4i",i+1,Scores[i].name,Scores[i].score);
	}
	
}