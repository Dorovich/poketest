#include "pokedex.h"
#include "pokecore.h"

pokemon_t* spawn_riolu (void) {
    pokemon_t* riolu = alloc_mem();
    riolu->name = "Riolu";
    riolu->nick = NULL;
    riolu->owner = NULL;
    riolu->level = 15;
    riolu->exp = 0;
    riolu->gender = Male;
    set_types(riolu, Fighting, NoType);
    set_stats(riolu, 40, 70, 40, 35, 40, 60);
    set_attack(riolu, 1, QuickAttack);
    set_attack(riolu, 2, Tackle);
    set_attack(riolu, 3, NoAttack);
    set_attack(riolu, 4, NoAttack);
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
    set_types(shaymin, Grass, NoType);
    set_stats(shaymin, 100, 100, 100, 100, 100, 100);
    set_attack(shaymin, 1, QuickAttack);
    set_attack(shaymin, 2, Tackle);
    set_attack(shaymin, 3, NoAttack);
    set_attack(shaymin, 4, NoAttack);
    return shaymin;
}

pokemon_t* spawn_mimikyu (void) {
    pokemon_t* mimikyu = alloc_mem();
    mimikyu->name = "Mimikyu";
    mimikyu->nick = NULL;
    mimikyu->owner = NULL;
    mimikyu->level = 20;
    mimikyu->exp = 0;
    mimikyu->gender = Female;
    set_types(mimikyu, Ghost, Fairy);
    set_stats(mimikyu, 55, 90, 80, 50, 105, 96);
    set_attack(mimikyu, 1, QuickAttack);
    set_attack(mimikyu, 2, Tackle);
    set_attack(mimikyu, 3, NoAttack);
    set_attack(mimikyu, 4, NoAttack);
    return mimikyu;
}

pokemon_t* spawn_chimchar (void) {
    pokemon_t* chimchar = alloc_mem();
    chimchar->name = "Chimchar";
    chimchar->nick = NULL;
    chimchar->owner = NULL;
    chimchar->level = 15;
    chimchar->exp = 0;
    chimchar->gender = Male;
    set_types(chimchar, Fire, NoType);
    set_stats(chimchar, 44, 58, 44, 58, 44, 61);
    set_attack(chimchar, 1, Tackle);
    set_attack(chimchar, 2, Ember);
    set_attack(chimchar, 3, NoAttack);
    set_attack(chimchar, 4, NoAttack);
    return chimchar;
}
