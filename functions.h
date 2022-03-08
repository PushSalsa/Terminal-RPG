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
} player;

int life(char t);
int att(char t);
int nrg(char t);
void wprompt(int l);
void dprompt(int l);
void bprompt(int l);
int enemyStats (player *vile, int d, int xp);

#endif
