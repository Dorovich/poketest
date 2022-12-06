#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pokedex.h"

int main (int argc, char** argv) {
    char msg[256];
    int len;
    srand(time(NULL));

    pokemon_data shaymin = spawn_shaymin();
    len = sprintf(msg, "¡Un %s salvaje apareció!\n", shaymin->name);
    if (write(1, msg, len) < 0) exit(1);

    pokemon_data riolu = spawn_riolu();
    len = sprintf(msg, "¡Adelante, %s!\n", riolu->name);
    if (write(1, msg, len) < 0) exit(1);

    despawn(shaymin);
    despawn(riolu);
    return 0;
}
