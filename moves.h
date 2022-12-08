#ifndef MOVES
#define MOVES

#include "pokecore.h"

/* calculate attack's damage from certain parameters */
int calc_damage (pokemon_t* caster, pokemon_t* target, int attack_stat_id, int defence_stat_id, int power, double stab, double effectiveness);
/* calculate attack's effectiveness from its type and the target's */
double calc_effectiveness (int attack_type, int target_type);

int quick_attack (pokemon_t* caster, pokemon_t* target);
int tackle (pokemon_t* caster, pokemon_t* target);
int ember (pokemon_t* caster, pokemon_t* target);
/* NOTE: attacks return damage dealt */

#endif
