#ifndef MOVES
#define MOVES

#include "pokecore.h"

/* calculate attack's damage from certain parameters */
int calc_damage (int caster_level, int attack_stat, int attack_power, int defence_stat, double type_bonus, double effectiveness);
/* calculate attack's effectiveness from its type and the target's */
double calc_effectiveness (int attack_type, int target_type);

int quick_attack (pokemon_t* caster, pokemon_t* target);
int tackle (pokemon_t* caster, pokemon_t* target);
int ember (pokemon_t* caster, pokemon_t* target);
/* NOTE: attacks return damage dealt */

#endif
