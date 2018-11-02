

CFLAGS = -g

life: Board.o Game.o
	gcc $(CFLAGS) -Wall Board.c Game.c -o life 

Board.o: Life.h Board.c
	gcc $(CFLAGS) -Wall -c Board.c

Game.o: Life.h Game.c Board.c 
	gcc $(CFLAGS) -Wall -c Game.c


clean:
	rm -f Board.o Game.o life

all: life


