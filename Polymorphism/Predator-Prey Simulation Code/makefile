CFLAGS = -g -Wall

all: PA6

PA6: Organism.o Ant.o Doodlebug.o Main.o Board.o
	g++ $(CFLAGS) Organism.o Ant.o Doodlebug.o Main.o Board.o -o PA6

Organism.o: Organism.cpp Organism.h
	g++ $(CFLAGS) -c Organism.cpp
	
Ant.o: Ant.cpp Ant.h
	g++ $(CFLAGS) -c Ant.cpp

Doodlebug.o: Doodlebug.cpp Doodlebug.h
	g++ $(CFLAGS) -c Doodlebug.cpp
	
Board.o: Board.cpp Board.h
	g++ $(CFLAGS) -c Board.cpp
	
Main.o: Simulation.cpp
	g++ $(CFLAGS) -c Main.cpp

clean:
rm -f *.o *.exe PA6
