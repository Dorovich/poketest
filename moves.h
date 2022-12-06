#ifndef MOVES
#define MOVES

#include "pokecore.h"

/* calculate attack's damage from certain parameters */
int calc_attack (int caster_level, int attack_stat, int attack_power, int defence, double type_bonus, double effectiveness);
/* calculate attack's effectiveness from its type and the target's */
double calc_effectiveness (int attack_type, pokemon_t* target);

int quick_attack (pokemon_t* caster, pokemon_t* target);
int counter (pokemon_t* caster, pokemon_t* target);
int endure (pokemon_t* caster, pokemon_t* target);
int feint (pokemon_t* caster, pokemon_t* target);
/* NOTE: attacks return damage dealt */

#endif
