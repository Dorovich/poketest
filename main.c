#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pokedex.h"

int main (int argc, char** argv) {
    char msg[256];
    int len, damage;
    srand(time(NULL));

    pokemon_data shaymin = spawn_shaymin();
    len = sprintf(msg, "¡Un %s salvaje apareció!\n", shaymin->name);
    if (write(1, msg, len) < 0) exit(1);

    pokemon_data riolu = spawn_riolu();
    len = sprintf(msg, "¡Adelante, %s!\n", riolu->name);
    if (write(1, msg, len) < 0) exit(1);

    printf("\n");

    len = sprintf(msg, "¡%s usó %s!\n", riolu->name, riolu->attacks->name1);
    if (write(1, msg, len) < 0) exit(1);
    damage = riolu->attacks->slot1(riolu, shaymin);
    shaymin->actHP -= damage;
    if (shaymin->actHP > 0) {
        len = sprintf(msg, "¡Causó %d puntos de daño!\nSalud de %s: %d / %d\n", damage, shaymin->name, shaymin->actHP, shaymin->HP);
    } else {
        len = sprintf(msg, "¡Causó %d puntos de daño!\n¡%s queda fuera de combate!\n", damage, shaymin->name);
    }
    if (write(1, msg, len) < 0) exit(1);

    printf("\n");

    len = sprintf(msg, "¡%s usó %s!\n", shaymin->name, shaymin->attacks->name1);
    if (write(1, msg, len) < 0) exit(1);
    damage = riolu->attacks->slot1(shaymin, riolu);
    riolu->actHP -= damage;
    if (riolu->actHP > 0) {
        len = sprintf(msg, "¡Causó %d puntos de daño!\nSalud de %s: %d / %d\n", damage, riolu->name, riolu->actHP, riolu->HP);
    } else {
        len = sprintf(msg, "¡Causó %d puntos de daño!\n¡%s queda fuera de combate!\n", damage, riolu->name);
    }
    if (write(1, msg, len) < 0) exit(1);

    despawn(shaymin);
    despawn(riolu);
    return 0;
}
