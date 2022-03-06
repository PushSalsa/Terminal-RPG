/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "header.h"



int main()
{
	int r=0,d=0,xp=0,pxp=0,lvl=1,dmg=0,ene=0,maxHP=0,maxNRG=0;
	char move,act;
	player play;
	srand (time(NULL));	//use with int r = rand() % 20 to get rand num between 0 - 19
	printf("Welcome! \ncode_wizard = w - High energy means many ways to kill your enemy.\nStats -- HP:50\tAttack:10\tEnergy:150\n\n");
	printf("windows_defender = d - Endure powerful blows with the magical Windows shield.\nStats -- HP:150\tAttack:5\tEnergy:100\n\n");
	printf("brute_force = b - Deal powerful blows using brute force.\nStats -- HP:100\tAttack:15\tEnergy:50\n\nChoose which type of cyber hero to become (type w,d, or b):\n");
	while (play.type != 'w' && play.type != 'd' && play.type != 'b') 
	{
	    scanf(" %c", &play.type);
		if (play.type != 'w' && play.type != 'd' && play.type != 'b')
			printf("Invalid entry! type w, d, or b:\n");
	}
	play.hp = life(play.type);
	play.dmg = att(play.type);
	play.nrg = nrg(play.type);
    maxHP = play.hp;
    maxNRG = play.nrg;
	while (play.hp>=0)
	{
		printf("\n\na = Left, hard route \nw = Forward, the most dangerous route \ns = Back, easy route \nd = Right, medium route\nType your direction:");
		scanf(" %c", &move);
		switch (move)
		{
			case 'a':
				r = rand() % 4;
				break;
			case 's':
				r = rand() % 5;
				break;
			case 'w':
				r = 2;
				break;
			case 'd':
				r = rand() % 3;
				break;
			default:
				printf("Invalid entry!");
				break;
		}
		if (r >= 2)
		{
			printf("\nYou've encountered an enemy. "); //list: malwarewolf, phisherman, minorbug, deedos
			d = rand() % 4;
			enemy vile;
			switch (d)
			{
			case 0:
				vile.hp = 20;
				vile.dmg = 5;
				vile.nrg = 25;
				vile.type = 'b';
				xp = 5;
				printf("It's the minorbug!");
				break;
			case 1:
				vile.hp = 30;
				vile.dmg = 10;
				vile.nrg = 40;
				vile.type = 'p';
				xp = 15;
				printf("It's the phisherman!");
				break;
			case 2:
				vile.hp = 75;
				vile.dmg = 10;
				vile.nrg = 50;
				vile.type = 'm';
				xp = 25;
				printf("It's the malwarewolf!");
				break;
			case 3:
				vile.hp = 60;
				vile.dmg = 5;
				vile.nrg = 75;
				vile.type = 'd';
				xp = 20;
				printf("It's the deedos!");
				break;
			}
			printf("\nHP:%d \tAttack:%d\tEnergy:%d\n\nYour current stats are:", vile.hp, vile.dmg, vile.nrg);
			printf("\nHP:%d \tAttack:%d\tEnergy:%d\n\nWhat will you do?", play.hp, play.dmg, play.nrg);
			while(play.hp>0 && vile.hp>0)
			{
    			while(act != 'q' && act != 'w' && act != 'e' && act != 'r' && act != 'a' && act != 's' && act != 'd' && act != 'f' && act != 'c' && act != 'v')
    			{
        			printf("\n(2) Basic Attack = q\n(10) Run = w\n(0) Energize = e\n(0) Heal = r");  //q,w,e,r actions
        			if (play.type == 'w')
        			    wprompt(lvl);
        			if (play.type == 'd')
        		        dprompt(lvl);
        			if (play.type == 'b')
        			    bprompt(lvl);
        			printf("\nEnter one of choices above!:\n");
        			scanf(" %c", &act);                                     //get user's action selection
        			if ((act=='s' && lvl<5) || (act=='d' && lvl<10) ||(act=='f' && lvl<15) || (act=='c' && lvl<20) || (act=='v' && lvl<25))  //validate selection
                    {    
                        act='z';
                        printf("\nYou are not a high enough level to use this yet.\n");
                    }
    		    }
    		    printf("\nYou used ");
    		    d = (rand()%16) + 5;
    		    switch(act)
        		{
        		case 'q':
        		    play.nrg-=2;
     		        dmg = play.dmg;
        			printf("Basic Attack, dealing %d damage.", dmg);
        			break;
        		case 'w':
        		    play.nrg-=15;
        			printf("this opportunity to run away!");
        			goto runaway;
        			break;
        		case 'e':
        		    play.nrg+=d;
        			printf("Energy Recovery, recovering %d energy.",d);
        			break;
        		case 'r':
        		    play.hp+=d;
        			printf("Health Recovery, recovering %d health.",d);
        			break;
        		}
    			if (play.type == 'w')
    			{
        			switch(act)
        			{
        			case 'a':
        			    dmg = play.dmg*2;
        			    play.nrg-=5;
        			    printf("Wand Blast, dealing %d damage.", dmg);
        			    break;
        			case 's':
        			    play.nrg-=10;
        			    dmg = play.dmg*3.5;
        			    printf("Fireball, dealing %d damage.", dmg);
        			    break;
        			case 'd':
        			    play.nrg-=20;
        			    ene = 10;
        			    dmg = play.dmg*4.25;
        			    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
        			    break;
        			case 'f':
        			    play.nrg-=30;
        			    ene = 25;
        			    dmg = play.dmg*6;
        			    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
        			    break;
        			case 'c':
        			    play.nrg-=45;
        			    ene = 25;
        			    dmg = play.dmg*6;
        			    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
        			    break;
        			case 'v':
        			    play.nrg-=60;
        			    ene = 25;
        			    dmg = play.dmg*6;
        			    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
        			    break;
        			}
        			
    			}
    			if (play.type == 'd')
    			{
        			switch(act)
        			{
        			case 'a':
        			    dmg = play.dmg*2;
        			    play.nrg-=5;
        			    printf("Wand Blast, dealing %d damage.", dmg);
        			    break;
        			case 's':
        			    play.nrg-=10;
        			    dmg = play.dmg*3.5;
        			    printf("Fireball, dealing %d damage.", dmg);
        			    break;
        			case 'd':
        			    play.nrg-=20;
        			    ene = 10;
        			    dmg = play.dmg*4.25;
        			    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
        			    break;
        			case 'f':
        			    play.nrg-=30;
        			    ene = 25;
        			    dmg = play.dmg*6;
        			    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
        			    break;
        			case 'c':
        			    play.nrg-=45;
        			    ene = 25;
        			    dmg = play.dmg*6;
        			    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
        			    break;
        			case 'v':
        			    play.nrg-=60;
        			    ene = 25;
        			    dmg = play.dmg*6;
        			    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
        			    break;
        			}
        			
    			}
    			if (play.type == 'b')
    			{
        			switch(act)
        			{
        			case 'a':
        			    dmg = play.dmg*2;
        			    play.nrg-=5;
        			    printf("Wand Blast, dealing %d damage.", dmg);
        			    break;
        			case 's':
        			    play.nrg-=10;
        			    dmg = play.dmg*3.5;
        			    printf("Fireball, dealing %d damage.", dmg);
        			    break;
        			case 'd':
        			    play.nrg-=20;
        			    ene = 10;
        			    dmg = play.dmg*4.25;
        			    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
        			    break;
        			case 'f':
        			    play.nrg-=30;
        			    ene = 25;
        			    dmg = play.dmg*6;
        			    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
        			    break;
        			case 'c':
        			    play.nrg-=45;
        			    ene = 25;
        			    dmg = play.dmg*6;
        			    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
        			    break;
        			case 'v':
        			    play.nrg-=60;
        			    ene = 25;
        			    dmg = play.dmg*6;
        			    printf("Gusty Forces, dealing %d damage and reducing op's energy by %d", dmg,ene);
        			    break;
        			}
        			
    			}
    			vile.hp-=dmg;
    			vile.nrg-=ene;
    			if (vile.hp<=0)
    			    goto win;
    			printf("\n\nYour opponent uses ");
    			d = rand()%3;
    		    switch(d)
        		{
        		case 0:
        		    vile.nrg-=2;
        		    dmg = vile.dmg;
        			printf("Basic Attack, dealing %d damage.", dmg);
        			break;
        		case 1:
        		    vile.nrg-=5;
        		    dmg = vile.dmg*1.5;
        			printf("Charged Attack, dealing %d damage.", dmg);
        			break;
        		case 2:
        		    vile.nrg-=10;
        		    dmg = vile.dmg*2;
        			printf("Data Chomp, dealing %d damage.", dmg);
        			break;
        		}
        		play.hp-=dmg;
        		if (play.hp<=0)
        		    goto dead;
        	    printf("\n\nYour HP: %d\tYour Energy: %d\nEnemy HP: %d\tEnemy Energy: %d", play.hp,play.nrg,vile.hp,vile.nrg);
        	    act='z';
        	    ene,dmg=0;
			}
			win: printf("\nThe enemy is deleted!\n");
			pxp+=xp;
			printf("You gained %d xp.",xp);
			runaway:act='z';
			if (pxp>=100)
			{
			    ++lvl;
			    pxp-=100;
			    printf("You leveled up!");
			}
			if (play.hp > maxHP)
		        play.hp = maxHP;
		    if (play.nrg > maxNRG)
		        play.nrg = maxNRG;
		}
		if (r == 0 && play.hp < maxHP)
		{
		    play.hp+=(maxHP*.15);
		    if (play.hp > maxHP)
		        play.hp = maxHP;
		    printf("\nYou found some spare data, healing you for 15%% health.\n");
		}
		if (r == 1 && play.nrg < maxNRG)
		{
		    play.nrg+=(maxNRG*.15);
		    printf("\nYou found some spare data, energizing you for 15%% energy.\n");
		    if (play.nrg > maxNRG)
		        play.nrg = maxNRG;
		}
	}
	dead:;
	printf("\n\nGame Over, you're dead!\nDead at level %d",lvl);
}



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

