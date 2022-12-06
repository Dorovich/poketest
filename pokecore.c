#include "pokecore.h"
#include "moves.h"

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
    switch (slot) {
        case 1:
            attack_func = &pkmn->attacks->slot1;
            break;
        case 2:
            attack_func = &pkmn->attacks->slot2;
            break;
        case 3:
            attack_func = &pkmn->attacks->slot3;
            break;
        case 4:
            attack_func = &pkmn->attacks->slot4;
            break;
        default:
            perror("INVALID SLOT");
            exit(1);
    }

    switch (atkid) {
        case QuickAttack:
            *attack_func = quick_attack;
            break;
        case Counter:
            *attack_func = counter;
            break;
        case Endure:
            *attack_func = endure;
            break;
        case Feint:
            *attack_func = feint;
            break;
        default:
            perror("INVALID ATTACK ID");
            exit(1);
    }
}
