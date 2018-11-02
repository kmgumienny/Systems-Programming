CFLAGS = -g -Wall

all: PA5

PA5: main.o Rational.o
	g++ $(CFLAGS) main.o Rational.o -o PA5
	
main.o: main.cpp Rational.h Rational.cpp
	g++ $(CFLAGS) -c main.cpp Rational.cpp
	
Rational.o: Rational.h Rational.cpp
	g++ $(CFLAGS) -c Rational.cpp

clean:
	rm -f *.o PA5

