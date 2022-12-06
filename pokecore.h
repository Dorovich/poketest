#ifndef POKECORE
#define POKECORE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct pokemon_t pokemon_t;
typedef struct attacks_t attacks_t;
typedef struct pokemon_t* pokemon_data;

struct pokemon_t {
    char* name; /* pokemon name */
    char* nick; /* nickname set by owner. must be NULL if owner is NULL */
    char* owner; /* pokemon owner. NULL if wild */
    int gender; /* pokemon's gender */
    int level, exp; /* pokemon's level and experience points */
    int type1, type2; /* pokemon's types. type1 is mandatory, type2 can be NULL */
    int HP, ATK, DEF, SATK, SDEF, SPD; /* stats */
    int actHP; /* current pokemon's HP */
    attacks_t* attacks; /* attack moves */
};

struct attacks_t {
    int id1, id2, id3, id4;
    char* name1; char* name2; char* name3; char* name4;
    int (*slot1)(pokemon_t*, pokemon_t*);
    int (*slot2)(pokemon_t*, pokemon_t*);
    int (*slot3)(pokemon_t*, pokemon_t*);
    int (*slot4)(pokemon_t*, pokemon_t*);
};

/* possible pokemon types */
enum type_e { Normal, Fire, Water, Grass, Electric, Ice, Fighting, Poison, Ground, Flying, Psychic, Bug, Rock, Ghost, Dragon, Dark, Steel, Fairy, NoType };

/* possible attacks to be used */
enum attack_e { QuickAttack, Tackle, Ember, NoAttack };

/* pokemon genders */
enum gender_e { Male, Female, Genderless };

/* type effectiveness matrix (column is defender, row is attacker).
 * 1: normal effectiveness, 0: weak, -1: immune, 2: effective */
static char type_chart[18][18] = {
/*             Normal, Fire, Water, Grass, Electric, Ice, Fighting, Poison, Ground, Flying, Psychic, Bug, Rock, Ghost, Dragon, Dark, Steel, Fairy */
/*Normal  */ { 1,      1,    1,     1,     1,        1,   1,        1,      1,      1,      1,       1,   0,    -1,    1,      1,    0,     1 },
/*Fire    */ { 1,      0,    0,     2,     1,        2,   1,        1,      1,      1,      1,       2,   0,    1,     0,      1,    2,     1 },
/*Water   */ { 1,      2,    0,     0,     1,        1,   1,        1,      2,      1,      1,       1,   2,    1,     0,      1,    1,     1 },
/*Grass   */ { 1,      0,    2,     0,     1,        1,   1,        0,      2,      0,      1,       0,   2,    1,     0,      1,    0,     1 },
/*Electric*/ { 1,      1,    2,     0,     0,        1,   1,        1,      -1,     2,      1,       1,   1,    1,     0,      1,    1,     1 },
/*Ice     */ { 1,      0,    0,     2,     1,        0,   1,        1,      2,      2,      1,       1,   1,    1,     2,      1,    0,     1 },
/*Fighting*/ { 2,      1,    1,     1,     1,        2,   1,        0,      1,      0,      0,       0,   2,    -1,    1,      2,    2,     0 },
/*Poison  */ { 1,      1,    1,     2,     1,        1,   1,        0,      0,      1,      1,       1,   0,    0,     1,      1,    -1,    2 },
/*Ground  */ { 1,      2,    1,     0,     2,        1,   1,        2,      1,      -1,     1,       0,   2,    1,     1,      1,    2,     1 },
/*Flying  */ { 1,      1,    1,     2,     0,        1,   2,        1,      1,      1,      1,       2,   0,    1,     1,      1,    0,     1 },
/*Psychic */ { 1,      1,    1,     1,     1,        1,   2,        2,      1,      1,      0,       1,   1,    1,     1,      -1,   0,     1 },
/*Bug     */ { 1,      0,    1,     2,     1,        1,   0,        0,      1,      0,      2,       1,   1,    0,     1,      2,    0,     0 },
/*Rock    */ { 1,      2,    1,     1,     1,        2,   0,        1,      0,      2,      1,       2,   1,    1,     1,      1,    0,     1 },
/*Ghost   */ { -1,     1,    1,     1,     1,        1,   1,        1,      1,      1,      2,       1,   1,    2,     1,      0,    1,     1 },
/*Dragon  */ { 1,      1,    1,     1,     1,        1,   1,        1,      1,      1,      1,       1,   1,    1,     2,      1,    0,     -1},
/*Dark    */ { 1,      1,    1,     1,     1,        1,   0,        1,      1,      1,      2,       1,   1,    2,     1,      0,    1,     0 },
/*Steel   */ { 1,      0,    0,     1,     0,        2,   1,        1,      1,      1,      1,       1,   2,    1,     1,      1,    0,     2 },
/*Fairy   */ { 1,      0,    1,     1,     1,        1,   2,        0,      1,      1,      1,       1,   1,    1,     2,      2,    0,     1 }
};

/* effectiveness values */
#define IMMUNE 0.0
#define WEAK 0.5
#define NORMAL 1.0
#define EFFECTIVE 2.0

/* create an error message and halt the program */
void exiterror (const char* msg, int errnum);
/* allocate memory for a new pokemon */
pokemon_t* alloc_mem (void);
/* free memory of a pokemon */
void despawn (pokemon_t* pkmn);
/* set types of a pokemon */
void set_types (pokemon_t* pkmn, int type1, int type2);
/* set stats of a pokemon */
void set_stats (pokemon_t* pkmn, int hp, int atk, int def, int satk, int sdef, int spd);
/* set attack of a pokemon on a certain slot */
void set_attack (pokemon_t* pkmn, int slot, int atkid);

#endif
