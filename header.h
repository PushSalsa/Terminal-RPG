#ifndef HEADER
#define HEADER

//for structure type declarations, function prototypes, and global variable extern delcarations
typedef struct
{
	char type;
	int hp;
	int dmg;
	int nrg;
} enemy;

typedef struct
{
	char type;
	int hp;
	int max;
	int dmg;
	int nrg;
} player;

int hp(char t);
int dmg(char t);
int nrg(char t);
void explore();


#endif
