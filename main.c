#include <stdio.h>
#include "pokedex.h"

int main (int argc, char** argv) {
    pokemon_data riolu = spawn_riolu();
    char msg[256];
    int len = sprintf(msg, "A wild %s appeared!\n", riolu->name);
    despawn(riolu);
    if (write(1, msg, len) < 0) exit(1);
    return 0;
}
