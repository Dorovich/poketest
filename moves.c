#include "moves.h"
#include "pokecore.h"

int calc_damage (int caster_level, int attack_stat, int attack_power, int defence, double type_bonus, double effectiveness) {
    int attack_rand = rand()%16 + 85;
    double damage = ((0.2 * caster_level + 1) * attack_stat * attack_power)/(25 * defence) + 2;
    damage *= 0.01 * type_bonus * effectiveness * attack_rand;
    return (int)round(damage);
}

double calc_effectiveness (int attacker_type, int defender_type) {
    if (defender_type == None || attacker_type == None) return NORMAL;
    switch (type_chart[attacker_type][defender_type]) {
        case -1:
            return IMMUNE;
        case 0:
            return WEAK;
        case 2:
            return EFFECTIVE;
        default:
            return NORMAL;
    }
}

int quick_attack (pokemon_t* caster, pokemon_t* target) {
    int attack_type = Normal;
    double bonus = (caster->type1 == attack_type || caster->type2 == attack_type ? 1.5 : 1.0);
    double effec = calc_effectiveness(attack_type, target->type1) * calc_effectiveness(attack_type, target->type2);
    return calc_damage(caster->level, caster->ATK, 40, target->DEF, bonus, effec);
}

int counter (pokemon_t* caster, pokemon_t* target) { return 0; }
int endure (pokemon_t* caster, pokemon_t* target) { return 0; }
int feint (pokemon_t* caster, pokemon_t* target) { return 0; }
