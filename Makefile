all: poketest

poketest: poketest.o main.o
	gcc -O3 -Wall -o poketest poketest.o main.o

poketest.o: poketest.c poketest.h
	gcc -O3 -Wall -o poketest.o poketest.c -c

main.o: main.c pokedex.h poketest.h
	gcc -O3 -Wall -o main.o main.c -c

clean:
	rm *.o poketest
