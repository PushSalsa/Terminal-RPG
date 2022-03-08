#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

int life(char t)
{
	int x;
	switch (t)
	{
	case 'w':
		x = 50;
		break;
	case 'd':
		x = 150;
		break;
	case 'b':
		x = 100;
		break;
	default:
	    printf("Invalid entry! type w, d, or b:\n");
	    return -1;
	}
	return x;
}

int att(char t)
{
	int x;
	switch (t)
	{
	case 'w':
		x = 10;
		break;
	case 'd':
		x = 5;
		break;
	case 'b':
		x = 15;
		break;
	}
	return x;
}

int nrg(char t)
{
	int x;
	switch (t)
	{
	case 'w':
		x = 150;
		printf("\nYou have chosen the Code Wizard!\n");
		break;
	case 'd':
		x = 100;
		printf("\nYou have chosen the Windows Defender!\n");
		break;
	case 'b':
		x = 50;
		printf("\nYou have chosen the Brute Force\n");
		break;
	}
	return x;
}

void wprompt(int l)
{
    printf("\n(5) Wand Blast = a");
    switch(l)
    {
    case 5:
        printf("\n(10) Fireball = s");
        break;
    case 10:
        printf("\n(20) Gusty Forces = d");
    	break;
    case 15:
       	printf("\n(30) Shadow Bomb = f");
      	break;
    case 20:
        printf("\n(45) Data Drainer = c");
        break;
    case 25:
        printf("\n(60) Cyber Electrocution = v");
        break;
    }
}

void dprompt(int l)
{
    printf("\n(5) Shield Bash = a");
    switch(l)
    {
    case 5:
        printf("\n(10) Rejuvenate = s");
        break;
    case 10:
        printf("\n(15) Thorns = d");
        break;
    case 15:
        printf("\n(20) Window's Grasp = f");
        break;
    case 20:
        printf("\n(30) Overload = c");
        break;
    case 25:
        printf("\n(40) Data Destruction = v");
        break;
    }
}

void bprompt(int l)
{
    printf("\n(5) Brute Swipe = a");
    switch(l)
    {
    case 5:
        printf("\n(10) Brutal Combo = s");
        break;
    case 10:
        printf("\n(15) Double Dual Blades  = d");
        break;
    case 15:
        printf("\n(20) Sharknado = f");
        break;
    case 20:
        printf("\n(25) Vampiric Flurry = c");
        break;
    case 25:
        printf("\n(30) Chaos DDOS = v");
        break;
    }
}

int enemyStats (player *vile, int d, int xp)
{
    switch (d)
    {
    case 0:
        vile->hp = 20;
        vile->dmg = 5;
        vile->nrg = 25;
        vile->type = 'b';
        xp = 5;
        printf("It's the minorbug!");
        break;
    case 1:
        vile->hp = 30;
        vile->dmg = 10;
        vile->nrg = 40;
        vile->type = 'p';
        xp = 15;
        printf("It's the phisherman!");
        break;
    case 2:
        vile->hp = 75;
        vile->dmg = 10;
        vile->nrg = 50;
        vile->type = 'm';
        xp = 25;
        printf("It's the malwarewolf!");
        break;
    case 3:
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
