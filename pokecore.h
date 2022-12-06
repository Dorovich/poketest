#ifndef POKECORE
#define POKECORE

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

typedef struct pokemon_t pokemon_t;
typedef struct attacks_t attacks_t;
typedef struct pokemon_t* pokemon_data;

/* possible pokemon types */
enum type_e { None, Bug, Dragon, Fairy, Fire, Ghost, Ground, Normal, Psychic, Steel, Dark, Electric, Fighting, Flying, Grass, Ice, Poison, Rock, Water };

/* possible attacks to be used */
enum attack_e { QuickAttack, Counter, Endure, Feint };

/* pokemon genders */
enum gender_e { Male, Female, Genderless };

/* effectiveness values */
#define Ef_Immune 0.0
#define Ef_VeryWeak 0.25
#define Ef_Weak 0.5
#define Ef_Normal 1.0
#define Ef_Effective 2.0
#define Ef_VeryEffective 4.0

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
    int (*slot1)(pokemon_t*, pokemon_t*);
    int (*slot2)(pokemon_t*, pokemon_t*);
    int (*slot3)(pokemon_t*, pokemon_t*);
    int (*slot4)(pokemon_t*, pokemon_t*);
};

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