#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pokecore.h"
#include "pokedex.h"

void printmsg (char* msg, int msg_len) {
    if (write(1, msg, msg_len) < 0) exiterror("write error @main", 1);
}

int main (int argc, char** argv) {
    char msg[256];
    int len, damage;
    srand(time(NULL));

    pokemon_data shaymin = spawn_shaymin();
    len = sprintf(msg, "¡Un %s salvaje apareció!\n", shaymin->name);
    printmsg(msg, len);

    pokemon_data riolu = spawn_riolu();
    len = sprintf(msg, "¡Adelante, %s!\n", riolu->name);
    printmsg(msg, len);

    printf("\n"); //*TURNO 1**************************************************/

    len = sprintf(msg, "¡%s usó %s!\n", riolu->name, riolu->attacks->name1);
    printmsg(msg, len);
    damage = riolu->attacks->slot1(riolu, shaymin);
    shaymin->actHP -= damage;
    if (shaymin->actHP > 0) {
        len = sprintf(msg, "¡Causó %d puntos de daño!\nSalud de %s: %d / %d\n", damage, shaymin->name, shaymin->actHP, shaymin->HP);
    } else {
        len = sprintf(msg, "¡Causó %d puntos de daño!\n¡%s queda fuera de combate!\n", damage, shaymin->name);
    }
    printmsg(msg, len);

    printf("\n"); //*TURNO 2**************************************************/

    len = sprintf(msg, "¡%s usó %s!\n", shaymin->name, shaymin->attacks->name1);
    printmsg(msg, len);
    damage = riolu->attacks->slot1(shaymin, riolu);
    riolu->actHP -= damage;
    if (riolu->actHP > 0) {
        len = sprintf(msg, "¡Causó %d puntos de daño!\nSalud de %s: %d / %d\n", damage, riolu->name, riolu->actHP, riolu->HP);
    } else {
        len = sprintf(msg, "¡Causó %d puntos de daño!\n¡%s queda fuera de combate!\n", damage, riolu->name);
    }
    printmsg(msg, len);

    printf("\n"); //*TURNO 3**************************************************/

    pokemon_data mimikyu = spawn_mimikyu();
    len = sprintf(msg, "¡Un %s salvaje apareció!\n¡A por él, %s! *lo cura*\n", mimikyu->name, riolu->name);
    printmsg(msg, len);
    riolu->actHP = riolu->HP;

    printf("\n"); //*TURNO 4**************************************************/

    len = sprintf(msg, "¡%s usó %s!\n", riolu->name, riolu->attacks->name1);
    printmsg(msg, len);
    damage = riolu->attacks->slot1(riolu, mimikyu);
    mimikyu->actHP -= damage;
    if (shaymin->actHP > 0) {
        len = sprintf(msg, "¡Causó %d puntos de daño!\nSalud de %s: %d / %d\n", damage, mimikyu->name, mimikyu->actHP, mimikyu->HP);
    } else {
        len = sprintf(msg, "¡Causó %d puntos de daño!\n¡%s queda fuera de combate!\n", damage, mimikyu->name);
    }
    printmsg(msg, len);

    printf("\n"); //*TURNO 4**************************************************/

    pokemon_data chimchar = spawn_chimchar();
    len = sprintf(msg, "¡Un %s salvaje apareció, parece que quiere ayudar!\n", chimchar->name);
    printmsg(msg, len);

    len = sprintf(msg, "¡%s usó %s!\n", chimchar->name, chimchar->attacks->name2);
    printmsg(msg, len);
    damage = riolu->attacks->slot2(chimchar, shaymin);
    shaymin->actHP -= damage;
    if (shaymin->actHP > 0) {
        len = sprintf(msg, "¡Causó %d puntos de daño!\nSalud de %s: %d / %d\n", damage, shaymin->name, shaymin->actHP, shaymin->HP);
    } else {
        len = sprintf(msg, "¡Causó %d puntos de daño!\n¡%s queda fuera de combate!\n", damage, shaymin->name);
    }
    printmsg(msg, len);

    despawn(shaymin);
    despawn(riolu);
    despawn(mimikyu);
    despawn(chimchar);
    return 0;
}
