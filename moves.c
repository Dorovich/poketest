#include "moves.h"
#include "pokecore.h"


int calc_damage (pokemon_t* caster, pokemon_t* target, int attack_stat_id, int defence_stat_id, int power, double stab, double effectiveness) {
    if (effectiveness == IMMUNE) return 0;
    double attack_stat_value = translate_stat(caster, attack_stat_id) * translate_mod(caster, attack_stat_id);
    double defence_stat_value = translate_stat(target, defence_stat_id) * translate_mod(target, defence_stat_id);
    int attack_rand = rand()%16 + 85;
    double damage = ((0.2 * caster->level + 1) * attack_stat_value * power)/(25 * defence_stat_value) + 2;
    damage *= 0.01 * stab * effectiveness * attack_rand;
    return (int)round(damage);
}

double calc_effectiveness (int attacker_type, int defender_type) {
    if (defender_type == NoType || attacker_type == NoType) return NORMAL;
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
    double stab = (caster->type1 == attack_type || caster->type2 == attack_type ? 1.5 : 1.0);
    double effec = calc_effectiveness(attack_type, target->type1) * calc_effectiveness(attack_type, target->type2);
    return calc_damage(caster, target, Atk, Def, 40, stab, effec);
}

int tackle (pokemon_t* caster, pokemon_t* target) {
    int attack_type = Normal;
    double stab = (caster->type1 == attack_type || caster->type2 == attack_type ? 1.5 : 1.0);
    double effec = calc_effectiveness(attack_type, target->type1) * calc_effectiveness(attack_type, target->type2);
    return calc_damage(caster, target, Atk, Def, 40, stab, effec);
}

int ember (pokemon_t* caster, pokemon_t* target) {
    int attack_type = Fire;
    double stab = (caster->type1 == attack_type || caster->type2 == attack_type ? 1.5 : 1.0);
    double effec = calc_effectiveness(attack_type, target->type1) * calc_effectiveness(attack_type, target->type2);
    return calc_damage(caster, target, SAtk, SDef, 40, stab, effec);
}
