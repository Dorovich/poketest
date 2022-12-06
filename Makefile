all: poketest

poketest: pokecore.o pokedex.o main.o moves.o
	gcc -O3 -Wall -o poketest pokecore.o main.o pokedex.o moves.o

pokecore.o: pokecore.c pokecore.h
	gcc -O3 -Wall -o pokecore.o pokecore.c -c

pokedex.o: pokedex.c pokedex.h pokecore.h
	gcc -O3 -Wall -o pokedex.o pokedex.c -c

moves.o: moves.c moves.h pokecore.h
	gcc -O3 -Wall -o moves.o moves.c -c

main.o: main.c pokecore.h
	gcc -O3 -Wall -o main.o main.c -c

clean:
	rm *.o poketest
