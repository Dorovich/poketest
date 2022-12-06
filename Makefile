all: poketest

poketest: main.c pokecore.o pokedex.o moves.o
	gcc -O3 -Wall -o poketest main.c pokecore.o pokedex.o moves.o -lm

pokecore.o: pokecore.c pokecore.h
	gcc -O3 -Wall -o pokecore.o pokecore.c -c

pokedex.o: pokedex.c pokedex.h
	gcc -O3 -Wall -o pokedex.o pokedex.c -c

moves.o: moves.c moves.h
	gcc -O3 -Wall -o moves.o moves.c -c -lm

clean:
	rm *.o poketest
