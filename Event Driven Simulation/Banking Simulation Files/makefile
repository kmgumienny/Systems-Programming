CFLAGS = -g
	
	
all: qSim
	
	
qSim: teller.o customer.o event.o main.o
	g++ $(CFLAGS) teller.o customer.o event.o main.o -o qSim
	
	
teller.o: teller.cpp teller.h event.h
	g++ $(CFLAGS) -c teller.cpp
	
	
customer.o: customer.cpp customer.h teller.h
	g++ $(CFLAGS) -c customer.cpp
	
	
main.o: main.cpp teller.h event.h customer.h
	g++ $(CFLAGS) -c main.cpp
	
	
event.o: event.cpp event.h
	g++ $(CFLAGS) -c event.cpp
	
	
clean:
	rm -f *.o *.exe qSim
