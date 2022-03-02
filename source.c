#include <std.io>
#include <time.h>
#include <stdlib.h>
#include "header.h"

srand(time(NULL));	//use with int r = rand() % 20 to get rand num between 0 - 19



int main()
{
	int r,d;
	char move;
	player play;
	printf("Welcome! Choose your type of cyber hero:\n c = code_wizard - High energy means many ways to kill your enemy.\nStats -- HP:50\tAttack:10\tEnergy:150\n");
	printf("w=win_defender - Endure powerful blows with the magical Windows shield.\nStats -- HP:150\tAttack:5\tEnergy:100\n");
	printf("b=brute_force - Deal powerful blows using brute force.\nStats -- HP:100\tAttack:15\tEnergy:50\n");
	while (play.type != ('w' || 'd' || 'b'))
	{
		scanf(% c, play.type);
		if (play.type != ('w' || 'd' || 'b')
			printf("Invalid entry! w, d, or b\n")
	}
	play.hp = hp(play.type);
	play.dmg = dmg(play.type);
	play.nrg = nrg(play.type);

	while (play.hp!=0)
	{
		printf("Type your direction: a=left w=forward s=back d=right");
			scanf(% c, move);
			switch (move)
				{
			case 'a':
			case 's':
			case 'w':
			case 'd':
				r = rand() % 5;
				break;
			default:
				printf("invalid entry!");
				break;
			}
		if (r == 0)
		{
			printf("You've encountered an enemy. "); //list: malwarewolf, phisherman, minorbug, deedos
			d = rand() % 4;
			enemy vile;
			switch (d)
			{
			case 0:
				vile.hp = 20;
				vile.dmg = 5;
				vile.nrg = 25;
				printf("It's the minorbug!");
			case 1:
				vile.hp = 30;
				vile.dmg = 10;
				vile.nrg = 40;
				printf("It's the phisherman!");
			case 2:
				vile.hp = 75;
				vile.dmg = 10;
				vile.nrg = 50;
				printf("It's the malwarewolf!");
			case 3:
				vile.hp = 60;
				vile.dmg = 5;
				vile.nrg = 75;
				printf("It's the deedos!");
				
			}
			printf("Stats - HP:%d \tAttack:%d\tEnergy:%d\n", vile.hp, vile.dmg, vile.nrg);
		}
		if (r == 1)
		{
			printf("You found a some health");
			d = rand() % 6;
			d = d + 5;	//range of 5 - 10
			
		}
	}
}

int hp(char t)
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
	}
	return x;
}

int dmg(char t)
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
		printf ("You have chosen the Code Wizard!")
		break;
	case 'd':
		x = 100;
		break;
	case 'b':
		x = 50;
		break;
	}
	return x;
}

void monster()
{

}
