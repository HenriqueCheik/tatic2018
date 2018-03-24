CC=gcc
CFLAGS=

all: armazenador buscador


armazenador: armazenador.c
	gcc -o armazenador armazenador.c

buscador: buscador.c
	gcc -o buscador buscador.c

clean:
	-rm armazenador buscador
