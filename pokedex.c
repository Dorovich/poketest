#include "pokedex.h"

pokemon_t* spawn_riolu (void) {
    pokemon_t* riolu = alloc_mem();
    riolu->name = "Riolu";
    riolu->nick = NULL;
    riolu->owner = NULL;
    riolu->level = 15;
    riolu->exp = 0;
    riolu->gender = Male;
    set_types(riolu, Fighting, None);
    set_stats(riolu, 40, 70, 40, 35, 40, 60);
    set_attack(riolu, 1, QuickAttack);
    set_attack(riolu, 2, Counter);
    set_attack(riolu, 3, Endure);
    set_attack(riolu, 4, Feint);
    return riolu;
}

pokemon_t* spawn_shaymin (void) {
    pokemon_t* shaymin = alloc_mem();
    shaymin->name = "Shaymin";
    shaymin->nick = NULL;
    shaymin->owner = NULL;
    shaymin->level = 70;
    shaymin->exp = 0;
    shaymin->gender = Genderless;
    set_types(shaymin, Grass, None);
    set_stats(shaymin, 100, 100, 100, 100, 100, 100);
    set_attack(shaymin, 1, QuickAttack);
    set_attack(shaymin, 2, Counter);
    set_attack(shaymin, 3, Endure);
    set_attack(shaymin, 4, Feint);
    return shaymin;
}
