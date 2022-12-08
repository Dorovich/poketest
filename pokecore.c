#include "pokecore.h"
#include "moves.h"
#include <math.h>

void exiterror(const char* msg, int errnum) {
    perror(msg);
    exit(1);
}

pokemon_t* alloc_mem (void) {
    pokemon_t* new_pkmn = (pokemon_t*)malloc(sizeof(pokemon_t));
    new_pkmn->attacks = (attacks_t*)malloc(sizeof(attacks_t));
    new_pkmn->vstats = (vstats_t*)malloc(sizeof(vstats_t));
    return new_pkmn;
}

void despawn (pokemon_t* pkmn) {
    free(pkmn->attacks);
    free(pkmn->vstats);
    free(pkmn);
}

void set_types (pokemon_t* pkmn, int type1, int type2) {
    pkmn->type1 = type1;
    pkmn->type2 = type2;
}

void set_stats (pokemon_t* pkmn, int hp, int atk, int def, int satk, int sdef, int spd) {
    pkmn->vstats->baseHP = hp;
    pkmn->vstats->baseATK = atk;
    pkmn->vstats->baseDEF = def;
    pkmn->vstats->baseSATK = satk;
    pkmn->vstats->baseSDEF = sdef;
    pkmn->vstats->baseSPD = spd;
    update_stats(pkmn);
}

void update_stats (pokemon_t* pkmn) {
    pkmn->HP = floor(0.01 * (2 * pkmn->vstats->baseHP + pkmn->vstats->ivHP + floor(0.25 * pkmn->vstats->evHP)) * pkmn->level) + pkmn->level + 10;
    pkmn->ATK = floor(0.01 * (2 * pkmn->vstats->baseATK + pkmn->vstats->ivATK + floor(0.25 * pkmn->vstats->evATK)) * pkmn->level);
    pkmn->DEF = floor(0.01 * (2 * pkmn->vstats->baseDEF + pkmn->vstats->ivDEF + floor(0.25 * pkmn->vstats->evDEF)) * pkmn->level);
    pkmn->SATK = floor(0.01 * (2 * pkmn->vstats->baseSATK + pkmn->vstats->ivSATK + floor(0.25 * pkmn->vstats->evSATK)) * pkmn->level);
    pkmn->SDEF = floor(0.01 * (2 * pkmn->vstats->baseSDEF + pkmn->vstats->ivSDEF + floor(0.25 * pkmn->vstats->evSDEF)) * pkmn->level);
    pkmn->SPD = floor(0.01 * (2 * pkmn->vstats->baseSPD + pkmn->vstats->ivSPD + floor(0.25 * pkmn->vstats->evSPD)) * pkmn->level);
    pkmn->actHP = pkmn->HP;
}

int translate_stat (pokemon_t* pkmn, int stat_id) {
    switch (stat_id) {
        case Hp:
            return pkmn->HP;
        case Atk:
            return pkmn->ATK;
        case Def:
            return pkmn->DEF;
        case SAtk:
            return pkmn->SATK;
        case SDef:
            return pkmn->SDEF;
        case Spd:
            return pkmn->SPD;
        default:
            exiterror("INVALID STAT @translate_stat", 1);
    }
    return 0;
}

void set_attack (pokemon_t* pkmn, int slot, int atkid) {
    int (**attack_func)(pokemon_t*, pokemon_t*);
    char** attack_name;
    int* attack_id;

    switch (slot) {
        case 1:
            attack_func = &pkmn->attacks->slot1;
            attack_name = &pkmn->attacks->name1;
            attack_id = &pkmn->attacks->id1;
            break;
        case 2:
            attack_func = &pkmn->attacks->slot2;
            attack_name = &pkmn->attacks->name2;
            attack_id = &pkmn->attacks->id2;
            break;
        case 3:
            attack_func = &pkmn->attacks->slot3;
            attack_name = &pkmn->attacks->name3;
            attack_id = &pkmn->attacks->id3;
            break;
        case 4:
            attack_func = &pkmn->attacks->slot4;
            attack_name = &pkmn->attacks->name4;
            attack_id = &pkmn->attacks->id4;
            break;
        default:
            exiterror("INVALID ATTACK SLOT @set_attack", 1);
    }

    switch (atkid) {
        case NoAttack:
            *attack_func = NULL;
            *attack_name = "---";
            *attack_id = NoAttack;
            break;
        case QuickAttack:
            *attack_func = quick_attack;
            *attack_name = "Quick attack";
            *attack_id = QuickAttack;
            break;
        case Tackle:
            *attack_func = tackle;
            *attack_name = "Tackle";
            *attack_id = Tackle;
            break;
        case Ember:
            *attack_func = ember;
            *attack_name = "Ember";
            *attack_id = Ember;
            break;
        default:
            exiterror("INVALID ATTACK ID @set_attack", 1);
    }
}

void generate_vstats (pokemon_t* pkmn) {
    pkmn->vstats->ivHP = rand()%32;
    pkmn->vstats->ivATK = rand()%32;
    pkmn->vstats->ivDEF = rand()%32;
    pkmn->vstats->ivSATK = rand()%32;
    pkmn->vstats->ivSDEF = rand()%32;
    pkmn->vstats->ivSPD = rand()%32;
    pkmn->vstats->evHP = 0;
    pkmn->vstats->evATK = 0;
    pkmn->vstats->evDEF = 0;
    pkmn->vstats->evSATK = 0;
    pkmn->vstats->evSDEF = 0;
    pkmn->vstats->evSPD = 0;
}

int do_attack (pokemon_t* caster, pokemon_t* target, int slot, char** attack_name) {
    int (*attack_func)(pokemon_t*, pokemon_t*);
    switch (slot) {
        case 1:
            attack_func = caster->attacks->slot1;
            *attack_name = caster->attacks->name1;
            break;
        case 2:
            attack_func = caster->attacks->slot2;
            *attack_name = caster->attacks->name2;
            break;
        case 3:
            attack_func = caster->attacks->slot3;
            *attack_name = caster->attacks->name3;
            break;
        case 4:
            attack_func = caster->attacks->slot4;
            *attack_name = caster->attacks->name4;
            break;
        default:
            exiterror("INVALID SLOT @do_attack", 1);
    }
    int damage = attack_func(caster, target);
    if (damage != 0) target->actHP -= damage;
    return damage;
}

void clear_mods (pokemon_t* pkmn) {
    pkmn->modATK = NoMod;
    pkmn->modDEF = NoMod;
    pkmn->modSATK = NoMod;
    pkmn->modSDEF = NoMod;
    pkmn->modSPD = NoMod;
}

void add_mod (pokemon_t* pkmn, int stat, int stages) {
    int* stat_modifier;
    switch (stat) {
        case Atk:
            stat_modifier = &pkmn->modATK;
            break;
        case Def:
            stat_modifier = &pkmn->modDEF;
            break;
        case SAtk:
            stat_modifier = &pkmn->modSATK;
            break;
        case SDef:
            stat_modifier = &pkmn->modSDEF;
            break;
        case Spd:
            stat_modifier = &pkmn->modSPD;
            break;
        default:
            exiterror("INVALID STAT @add_mod", 1);
    }
    *stat_modifier += stages;
    if (*stat_modifier > 6) *stat_modifier = 6;
    else if (*stat_modifier < -6) *stat_modifier = -6;
}

double translate_mod (pokemon_t* pkmn, int stat_id) {
    int val;
    switch (stat_id) {
        case Atk:
            val = pkmn->modATK;
            break;
        case Def:
            val = pkmn->modDEF;
            break;
        case SAtk:
            val = pkmn->modSATK;
            break;
        case SDef:
            val = pkmn->modSDEF;
            break;
        case Spd:
            val = pkmn->modSPD;
            break;
        default:
            exiterror("INVALID STAT @translate_mod", 1);
    }
    switch (val) {
        case Debuff6:
            return 0.25;
        case Debuff5:
            return 0.28;
        case Debuff4:
            return 0.33;
        case Debuff3:
            return 0.40;
        case Debuff2:
            return 0.50;
        case Debuff1:
            return 0.66;
        case NoMod:
            return 1;
        case Buff1:
            return 1.5;
        case Buff2:
            return 2;
        case Buff3:
            return 2.5;
        case Buff4:
            return 3;
        case Buff5:
            return 3.5;
        case Buff6:
            return 4;
        default:
            exiterror("INVALID MODIFICATION VALUE @translate_mod", 1);
    }
    return 0;
}
