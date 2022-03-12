#ifndef HEADER_END
#define HEADER_END

//for structure type declarations, function prototypes, and global variable extern delcarations

typedef struct
{
	char type;
	int hp;
	int max;
	int dmg;
	int nrg;
	int nrgActions[6];
	char nameActions[6][20];
} player;

void playerStats(player *play);
int movement(char move);
void prompt(int l, player *play);
int enemyStats (player *vile, int d, int xp);
void battle (player *vile, player *play, int randomNum,char act);

#endif
