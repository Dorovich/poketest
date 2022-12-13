#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pokecore.h"
#include "pokedex.h"

void printmsg (char* msg, int msg_len) {
    if (write(1, msg, msg_len) < 0) exiterror("write error @main", 1);
}

void make_attack (pokemon_data caster, pokemon_data target, int slot, char* buffer) {
    int len, damage;
    char* attack_name;
    damage = do_attack(caster, target, slot, &attack_name);
    len = sprintf(buffer, "¡%s usó %s!\n", caster->name, attack_name);
    printmsg(buffer, len);
    if (target->actHP > 0) {
        len = sprintf(buffer, "¡Causó %d puntos de daño!\nSalud de %s: %d / %d\n\n", damage, target->name, target->actHP, target->HP);
    } else {
        len = sprintf(buffer, "¡Causó %d puntos de daño!\n¡%s queda fuera de combate!\n\n", damage, target->name);
    }
    printmsg(buffer, len);
}

int main (int argc, char** argv) {
    char msg[256];
    int len;
    srand(time(NULL));

    pokemon_data shaymin = spawn_shaymin();
    len = sprintf(msg, "¡Un %s salvaje apareció!\n", shaymin->name);
    printmsg(msg, len);

    pokemon_data riolu = spawn_riolu();
    len = sprintf(msg, "¡Adelante, %s!\n\n", riolu->name);
    printmsg(msg, len);

    make_attack(riolu, shaymin, 1, msg);
    make_attack(shaymin, riolu, 1, msg);

    pokemon_data mimikyu = spawn_mimikyu();
    len = sprintf(msg, "¡Un %s salvaje apareció!\n¡A por él, %s! *lo cura*\n\n", mimikyu->name, riolu->name);
    printmsg(msg, len);
    riolu->actHP = riolu->HP;

    make_attack(riolu, mimikyu, 1, msg);

    pokemon_data chimchar = spawn_chimchar();
    len = sprintf(msg, "¡Un %s salvaje apareció, parece que quiere ayudar!\n", chimchar->name);
    printmsg(msg, len);

    make_attack(chimchar, shaymin, 2, msg);

    //************************************************************************/

    pokemon_data archen = spawn_archen();
    len = sprintf(msg, "¡Un %s salvaje apareció, y parece furioso!\n", archen->name);
    printmsg(msg, len);

    make_attack(archen, riolu, 1, msg);
    make_attack(archen, shaymin, 1, msg);
    make_attack(archen, mimikyu, 1, msg);
    make_attack(archen, chimchar, 1, msg);

    despawn(shaymin);
    despawn(riolu);
    despawn(mimikyu);
    despawn(chimchar);
    return 0;
}
