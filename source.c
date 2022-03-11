

Skip to content
Using Gmail with screen readers
Meet
Hangouts
Conversations
14.17 GB of 15 GB (94%) used
Terms · Privacy · Program Policies
Last account activity: 2 hours ago
Details

/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "functions.h"

int main()
{
	int r=0,randomNum=0,xp=0,pxp=0,lvl=1,maxHP=0,maxNRG=0;
	char move,act;
	player play;
	srand (time(NULL));	//use with int r = rand() % 20 to get rand num between 0 - 19
	printf("Welcome! \ncode_wizard = w - High energy means many ways to kill your enemy.\nStats -- HP:50\tAttack:10\tEnergy:150\n\n");
	printf("windows_defender = d - Endure powerful blows with the magical Windows shield.\nStats -- HP:150\tAttack:5\tEnergy:100\n\n");
	printf("brute_force = b - Deal powerful blows using brute force.\nStats -- HP:100\tAttack:15\tEnergy:50\n\nChoose which type of cyber hero to become (type w,d, or b):\n");
	scanf(" %c", &play.type);
	while (play.type != 'w' && play.type != 'd' && play.type != 'b') 
	{
	    printf("Invalid entry! type w, d, or b:\n");
	    scanf(" %c", &play.type);
	}
	playerStats(&play);
    maxHP = play.hp;
    maxNRG = play.nrg;
	while (play.hp>0)
	{
		printf("\n\na = Left, hard route \nw = Forward, the most dangerous route \ns = Back, easy route \nd = Right, medium route\nType your direction:");
		scanf(" %c", &move);
		r = movement(move);
		if (r >= 2)
		{
			randomNum = rand() % 9;
			player vile;
			xp = enemyStats(&vile,randomNum,xp);
			printf("\nHP:%d \tAttack:%d\tEnergy:%d\n\nYour current stats are:", vile.hp, vile.dmg, vile.nrg);
        	printf("\nHP:%d \tAttack:%d\tEnergy:%d\n\nWhat will you do?", play.hp, play.dmg, play.nrg);  
			while(play.hp>0 && vile.hp>0)
			{
    			prompt(lvl,play.type);
    			while(act != 'q' && act != 'w' && act != 'e' && act != 'r' && act != 'a' && act != 's' && act != 'd' && act != 'f' && act != 'c' && act != 'v')
    			{
        			printf("\nEnter one of choices from the list above!:\n");
        			scanf(" %c", &act);                                     //get user's action selection
        			if ((act=='s' && lvl<5) || (act=='d' && lvl<10) ||(act=='f' && lvl<15) || (act=='c' && lvl<20) || (act=='v' && lvl<25))  //validate selection
                    {    
                        act='z';
                        printf("\nYou are not a high enough level to use this yet.");
                    }
    		    }
    		    randomNum = (rand()%16) + 5;
    		    battle(&vile,&play,randomNum,act);
    		    if (act == 'w')
    		        break;
        	    act='z';
			}
			if (vile.hp<=0)
        	{
        	    printf("\nThe enemy is deleted!\n");
        	    pxp+=xp;
        	    printf("You gained %d xp.",xp);
                if (pxp>=100)
    			{
    			    ++lvl;
    			    pxp-=100;
    			    printf("You leveled up!");
    			}
        	}
			if (play.hp > maxHP)
	            play.hp = maxHP;
		    if (play.nrg > maxNRG)
		        play.nrg = maxNRG;
			act='z';
		}
		if (r == 0)
		    if (play.hp < maxHP)
		    {
    		    play.hp+=(maxHP*.15);
    		    printf("\nYou found some spare data, healing you for 15%% health.\n");
    		    if (play.hp > maxHP)
    		        play.hp = maxHP;
		    }
		    else
		        printf("\nYou found some spare data, but you're at max health already.\n");
    		 
		if (r == 1)
		    if (play.nrg < maxNRG)
		    {
    		    play.nrg+=(maxNRG*.15);
    		    printf("\nYou found some spare data, energizing you for 15%% energy.\n");
    		    if (play.nrg > maxNRG)
    		        play.nrg = maxNRG;
		    }
		    else
		        printf("\nYou found some spare data, but you're at max energy already.\n");
	}
	printf("\n\nGame Over, you're dead!\nDead at level %d",lvl);
}

source.c.txt
Displaying functions.c.txt.
