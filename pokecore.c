#include "pokecore.h"
#include "moves.h"

void exiterror(const char* msg, int errnum) {
    perror(msg);
    exit(1);
}

pokemon_t* alloc_mem (void) {
    pokemon_t* new_pkmn = (pokemon_t*)malloc(sizeof(pokemon_t));
    new_pkmn->attacks = (attacks_t*)malloc(sizeof(attacks_t));
    return new_pkmn;
}

void despawn (pokemon_t* pkmn) {
    free(pkmn->attacks);
    free(pkmn);
}

void set_types (pokemon_t* pkmn, int type1, int type2) {
    pkmn->type1 = type1;
    pkmn->type2 = type2;
}

void set_stats (pokemon_t* pkmn, int hp, int atk, int def, int satk, int sdef, int spd) {
    pkmn->HP = hp;
    pkmn->actHP = hp;
    pkmn->ATK = atk;
    pkmn->DEF = def;
    pkmn->SATK = satk;
    pkmn->SDEF = sdef;
    pkmn->SPD = spd;
}

void set_attack (pokemon_t* pkmn, int slot, int atkid) {
    int (**attack_func)(pokemon_t*, pokemon_t*);
    char** attack_name;
    int* attack_id;

    switch (slot) {
        case 1:
            attack_func = &pkmn->attacks->slot1;
            attack_name = &pkmn->attacks->name1;
            attack_id = &pkmn->attacks->id1;
            break;
        case 2:
            attack_func = &pkmn->attacks->slot2;
            attack_name = &pkmn->attacks->name2;
            attack_id = &pkmn->attacks->id2;
            break;
        case 3:
            attack_func = &pkmn->attacks->slot3;
            attack_name = &pkmn->attacks->name3;
            attack_id = &pkmn->attacks->id3;
            break;
        case 4:
            attack_func = &pkmn->attacks->slot4;
            attack_name = &pkmn->attacks->name4;
            attack_id = &pkmn->attacks->id4;
            break;
        default:
            exiterror("INVALID SLOT", 1);
    }

    switch (atkid) {
        case NoAttack:
            *attack_func = NULL;
            *attack_name = "---";
            *attack_id = NoAttack;
            break;
        case QuickAttack:
            *attack_func = quick_attack;
            *attack_name = "Quick attack";
            *attack_id = QuickAttack;
            break;
        case Tackle:
            *attack_func = tackle;
            *attack_name = "Tackle";
            *attack_id = Tackle;
            break;
        case Ember:
            *attack_func = ember;
            *attack_name = "Ember";
            *attack_id = Ember;
            break;
        default:
            exiterror("INVALID ATTACK ID", 1);
    }
}

