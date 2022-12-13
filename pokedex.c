#include "pokedex.h"
#include "pokecore.h"

pokemon_t* spawn_riolu (void) {
    pokemon_t* riolu = alloc_mem();
    riolu->name = "Riolu";
    riolu->nick = NULL;
    riolu->owner = NULL;
    riolu->pokedexn = 447;
    riolu->gender = Male;
    riolu->level = 15;
    riolu->exp = 0;
    set_types(riolu, Fighting, NoType);
    generate_vstats(riolu);
    set_stats(riolu, 40, 70, 40, 35, 40, 60);
    set_attack(riolu, 1, QuickAttack);
    set_attack(riolu, 2, Tackle);
    set_attack(riolu, 3, NoAttack);
    set_attack(riolu, 4, NoAttack);
    clear_mods(riolu);
    return riolu;
}

pokemon_t* spawn_shaymin (void) {
    pokemon_t* shaymin = alloc_mem();
    shaymin->name = "Shaymin";
    shaymin->nick = NULL;
    shaymin->owner = NULL;
    shaymin->pokedexn = 492;
    shaymin->gender = Genderless;
    shaymin->level = 50;
    shaymin->exp = 0;
    set_types(shaymin, Grass, NoType);
    generate_vstats(shaymin);
    set_stats(shaymin, 100, 100, 100, 100, 100, 100);
    set_attack(shaymin, 1, QuickAttack);
    set_attack(shaymin, 2, Tackle);
    set_attack(shaymin, 3, NoAttack);
    set_attack(shaymin, 4, NoAttack);
    clear_mods(shaymin);
    return shaymin;
}

pokemon_t* spawn_mimikyu (void) {
    pokemon_t* mimikyu = alloc_mem();
    mimikyu->name = "Mimikyu";
    mimikyu->nick = NULL;
    mimikyu->owner = NULL;
    mimikyu->pokedexn = 778;
    mimikyu->gender = Female;
    mimikyu->level = 20;
    mimikyu->exp = 0;
    set_types(mimikyu, Ghost, Fairy);
    generate_vstats(mimikyu);
    set_stats(mimikyu, 55, 90, 80, 50, 105, 96);
    set_attack(mimikyu, 1, QuickAttack);
    set_attack(mimikyu, 2, Tackle);
    set_attack(mimikyu, 3, NoAttack);
    set_attack(mimikyu, 4, NoAttack);
    clear_mods(mimikyu);
    return mimikyu;
}

pokemon_t* spawn_chimchar (void) {
    pokemon_t* chimchar = alloc_mem();
    chimchar->name = "Chimchar";
    chimchar->nick = NULL;
    chimchar->owner = NULL;
    chimchar->pokedexn = 390;
    chimchar->gender = Male;
    chimchar->level = 15;
    chimchar->exp = 0;
    set_types(chimchar, Fire, NoType);
    generate_vstats(chimchar);
    set_stats(chimchar, 44, 58, 44, 58, 44, 61);
    set_attack(chimchar, 1, Tackle);
    set_attack(chimchar, 2, Ember);
    set_attack(chimchar, 3, NoAttack);
    set_attack(chimchar, 4, NoAttack);
    clear_mods(chimchar);
    return chimchar;
}

pokemon_t* spawn_archen (void) {
    pokemon_t* archen = alloc_mem();
    archen->name = "Archen";
    archen->nick = NULL;
    archen->owner = NULL;
    archen->pokedexn = 566;
    archen->gender = Male;
    archen->level = 20;
    archen->exp = 0;
    set_types(archen, Rock, Flying);
    generate_vstats(archen);
    set_stats(archen, 55, 112, 45, 74, 45, 70);
    set_attack(archen, 1, Tackle);
    set_attack(archen, 2, NoAttack);
    set_attack(archen, 3, NoAttack);
    set_attack(archen, 4, NoAttack);
    clear_mods(archen);
    return archen;
}
