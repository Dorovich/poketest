#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct pokemon_t pokemon_t;
typedef struct attacks_t attacks_t;
typedef struct pokemon_t* pokemon_data;

enum type_e { None, Bug, Dragon, Fairy, Fire, Ghost, Ground, Normal, Psychic, Steel, Dark, Electric, Fighting, Flying, Grass, Ice, Poison, Rock, Water };

enum attack_e { QuickAttack, Counter, Endure, Feint };

void quick_attack (pokemon_t* caster, pokemon_t* target);
void counter (pokemon_t* caster, pokemon_t* target);
void endure (pokemon_t* caster, pokemon_t* target);
void feint (pokemon_t* caster, pokemon_t* target);

struct pokemon_t {
    char* name; /* pokemon name */
    char* nick; /* nickname set by owner. must be NULL if owner is NULL */
    char* owner; /* pokemon owner. NULL if wild */
    int type1, type2; /* pokemon's types. type1 is mandatory, type2 can be NULL */
    int HP, ATK, DEF, SATK, SDEF, SPD; /* stats */
    int actHP; /* current pokemon's HP */
    attacks_t* attacks; /* attack moves */
};

struct attacks_t {
    int id1, id2, id3, id4;
    void (*slot1)(pokemon_t*, pokemon_t*);
    void (*slot2)(pokemon_t*, pokemon_t*);
    void (*slot3)(pokemon_t*, pokemon_t*);
    void (*slot4)(pokemon_t*, pokemon_t*);
};

pokemon_t* alloc_mem (void);
void despawn (pokemon_t* pkmn);
void set_types (pokemon_t* pkmn, int type1, int type2);
void set_stats (pokemon_t* pkmn, int hp, int atk, int def, int satk, int sdef, int spd);
void set_attack (pokemon_t* pkmn, int slot, int atkid);
