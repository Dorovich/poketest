#include "poketest.h"

pokemon_t* spawn_riolu (void) {
    pokemon_t* riolu = alloc_mem();
    riolu->name = "Riolu";
    riolu->nick = NULL;
    riolu->owner = NULL;
    set_types(riolu, Fighting, None);
    /* stats =>      HP, ATK, DEF, SATK, SDEF, SPD */
    set_stats(riolu, 40, 70,  40,  35,   40,   60);
    /* attacks        Slot, AttackId */
    set_attack(riolu, 1,    QuickAttack);
    set_attack(riolu, 2,    Counter);
    set_attack(riolu, 3,    Endure);
    set_attack(riolu, 4,    Feint);
    return riolu;
}
