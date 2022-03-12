
Conversation opened. 1 unread message.

Skip to content
Using Gmail with screen readers
Meet
Hangouts
8 of 11,116
update6 (UNCLASSIFIED)
Inbox
Salazar Mejia, Kevin A SPC USARMY 780 MI BDE (USA) <kevin.a.salazarmejia.mil@army.mil>
	
AttachmentsThu, Mar 10, 1:59 PM (2 days ago)
	
to me

CLASSIFICATION: UNCLASSIFIED

 

 

 

 

CLASSIFICATION: UNCLASSIFIED
3 Attachments
	
	
	

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"


void playerStats(player *play)
{
    static const int wizNRG[]= {5,10,20,30,45,60};
    static const int defNRG[]= {5,10,15,20,30,40};
    static const int barNRG[]= {5,10,15,20,25,30};
    static const char wizName[6][20]= {"Wand Blast","Fireball","Gusty Forces","Shadow Bomb","Data Drainer","Cyber Electrocution"};
    static const char defName[6][20]= {"Wand Blast","Fireball","Gusty Forces","Shadow Bomb","Data Drainer","Cyber Electrocution"};
    static const char barName[6][20]= {"Wand Blast","Fireball","Gusty Forces","Shadow Bomb","Data Drainer","Cyber Electrocution"};
    switch (play->type)
	{
	case 'w':
		play->hp = 50;
		play->dmg = 10;
		play->nrg = 150;
		memcpy(play->nrgActions, wizNRG, sizeof(play->nrgActions));
		memcpy(play->nameActions, wizName, sizeof(play->nameActions));
		printf("\nYou have chosen the Code Wizard!\n");
		break;
	case 'd':
		play->hp = 150;
		play->dmg = 5;
		play->nrg = 100;
        memcpy(play->nrgActions, defNRG, sizeof(play->nrgActions));
		memcpy(play->nameActions, defName, sizeof(play->nameActions));
		printf("\nYou have chosen the Windows Defender!\n");
		break;
	case 'b':
		play->hp = 100;
		play->dmg = 15;
		play->nrg = 50;
		memcpy(play->nrgActions, barNRG, sizeof(play->nrgActions));
		memcpy(play->nameActions, barName, sizeof(play->nameActions));
		printf("\nYou have chosen the Brute Force\n");
		break;
	}
}

int movement(char move)
{
    int r;
    switch (move)
	{
	case 'a':
		r = rand() % 5;
		break;
	case 's':
		r = rand() % 3;
		break;
	case 'w':
		r = 2;
		break;
	case 'd':
		r = rand() % 4;
		break;
	default:
		printf("Invalid entry!");
		break;
	}
	return r;
}

void prompt(int l,player *play)
{
    printf("\n(2) Basic Attack = q\n(10) Run = w\n(0) Energize = e\n(0) Heal = r"); 
    printf("\n(5) Wand Blast = a");
    if (l>=5)
        printf("\n(%d) %s = s",play->nrgActions[1],play->nameActions[1]);
    if (l>=10)
        printf("\n(%d) %s = d",play->nrgActions[2],play->nameActions[2]);
    if (l>=15)
       	printf("\n(%d) %s = f",play->nrgActions[3],play->nameActions[3]);
    if (l>=20)
        printf("\n(%d) %s = c",play->nrgActions[4],play->nameActions[4]);
    if (l>=25)
        printf("\n(%d) %s = v",play->nrgActions[5],play->nameActions[5]);
}

int enemyStats (player *vile, int d, int xp)
{
    printf("\nYou've encountered an enemy. "); //list: malwarewolf, phisherman, minorbug, deedos
    switch (d)
    {
    case 0: case 1: case 2: case 3:
        vile->hp = 20;
        vile->dmg = 5;
        vile->nrg = 25;
        vile->type = 'b';
        xp = 5;
        printf("It's the minorbug!");
        break;
    case 4: case 5:
        vile->hp = 30;
        vile->dmg = 10;
        vile->nrg = 40;
        vile->type = 'p';
        xp = 15;
        printf("It's the phisherman!");
        break;
    case 6:
        vile->hp = 75;
        vile->dmg = 10;
        vile->nrg = 50;
        vile->type = 'm';
        xp = 25;
        printf("It's the malwarewolf!");
        break;
    case 7: case 8:
        vile->hp = 60;
        vile->dmg = 5;
        vile->nrg = 75;
        vile->type = 'd';
        xp = 20;
        printf("It's the deedos!");
        break;
    }
    return xp;
}

void battle (player *vile, player *play, int randomNum,char act)
{
    int dmg=0,ene=0;
    printf("\nYou used ");
    switch(act)
	{
	case 'q':
	    play->nrg-=2;
         dmg = play->dmg;
		printf("Basic Attack, dealing %d damage.", dmg);
		break;
	case 'w':
	    play->nrg-=15;
		printf("this opportunity to run away!");
		break;
	case 'e':
	    play->nrg+=randomNum;
		printf("Energy Recovery, recovering %d energy.",randomNum);
		break;
	case 'r':
	    play->hp+=randomNum;
		printf("Health Recovery, recovering %d health.",randomNum);
		break;
	}
	if (act == 'w')
	    return;
	if (play->type == 'w')
	{
		switch(act)
		{
		case 'a':
		    dmg = play->dmg*2;
		    play->nrg-=5;
		    printf("Wand Blast, dealing %d damage.", dmg);
		    break;
		case 's':
		    play->nrg-=10;
		    dmg = play->dmg*3.5;
		    printf("Fireball, dealing %d damage.", dmg);
		    break;
		case 'd':
		    play->nrg-=20;
		    ene = 10;
		    dmg = play->dmg*4.25;
		    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
		    break;
		case 'f':
		    play->nrg-=30;
		    ene = 25;
		    dmg = play->dmg*6;
		    printf("Shadow Bomb, dealing %d damage and reducing op's energy by %d", dmg,ene);
		    break;
		case 'c':
		    play->nrg-=45;
		    ene = 25;
		    dmg = play->dmg*6;
		    printf("Data Drainer, dealing %d damage and reducing op's energy by %d", dmg,ene);
		    break;
		case 'v':
		    play->nrg-=60;
		    ene = 25;
		    dmg = play->dmg*6;
		    printf("Cyber Electrocution, dealing %d damage and reducing op's energy by %d", dmg,ene);
		    break;
		}
		
	}
	if (play->type == 'd')
	{
		switch(act)
		{
		case 'a':
		    dmg = play->dmg*2;
		    play->nrg-=5;
		    printf("Wand Blast, dealing %d damage.", dmg);
		    break;
		case 's':
		    play->nrg-=10;
		    dmg = play->dmg*3.5;
		    printf("Fireball, dealing %d damage.", dmg);
		    break;
		case 'd':
		    play->nrg-=20;
		    ene = 10;
		    dmg = play->dmg*4.25;
		    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
		    break;
		case 'f':
		    play->nrg-=30;
		    ene = 25;
		    dmg = play->dmg*6;
		    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
		    break;
		case 'c':
		    play->nrg-=45;
		    ene = 25;
		    dmg = play->dmg*6;
		    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
		    break;
		case 'v':
		    play->nrg-=60;
		    ene = 25;
		    dmg = play->dmg*6;
		    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
		    break;
		}
		
	}
	if (play->type == 'b')
	{
		switch(act)
		{
		case 'a':
		    dmg = play->dmg*2;
		    play->nrg-=5;
		    printf("Wand Blast, dealing %d damage.", dmg);
		    break;
		case 's':
		    play->nrg-=10;
		    dmg = play->dmg*3.5;
		    printf("Fireball, dealing %d damage.", dmg);
		    break;
		case 'd':
		    play->nrg-=20;
		    ene = 10;
		    dmg = play->dmg*4.25;
		    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
		    break;
		case 'f':
		    play->nrg-=30;
		    ene = 25;
		    dmg = play->dmg*6;
		    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
		    break;
		case 'c':
		    play->nrg-=45;
		    ene = 25;
		    dmg = play->dmg*6;
		    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
		    break;
		case 'v':
		    play->nrg-=60;
		    ene = 25;
		    dmg = play->dmg*6;
		    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
		    break;
		}
		
	}
	vile->hp-=dmg;
	vile->nrg-=ene;
	if (vile->hp<=0)
	    return;
	printf("\n\nYour opponent uses ");
	randomNum = rand()%3;
    switch(randomNum)
	{
	case 0:
	    vile->nrg-=2;
	    dmg = vile->dmg;
		printf("Basic Attack, dealing %d damage.", dmg);
		break;
	case 1:
	    vile->nrg-=5;
	    dmg = vile->dmg*1.5;
		printf("Charged Attack, dealing %d damage.", dmg);
		break;
	case 2:
	    vile->nrg-=10;
	    dmg = vile->dmg*2;
		printf("Data Chomp, dealing %d damage.", dmg);
		break;
	}
	play->hp-=dmg;
	if (play->hp<=0)
	    return;
    printf("\n\nYour HP: %d\tYour Energy: %d\nEnemy HP: %d\tEnemy Energy: %d", play->hp,play->nrg,vile->hp,vile->nrg);
}

//void foundData

functions.c.txt
Displaying source.c.txt.
