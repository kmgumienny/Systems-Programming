

CFLAGS = -g0

PA3: main.o Reader_Writer.o BST.o
	gcc $(CFLAGS) -Wall main.c Reader_Writer.c BST.c -o PA3 

main.o: BSTH.h ReadWrite.h Reader_Writer.c BST.c main.c
	gcc $(CFLAGS) -Wall -c main.c

Reader_Writer.o: BSTH.h ReadWrite.h Reader_Writer.c BST.c main.c
	gcc $(CFLAGS) -Wall -c Reader_Writer.c

BST.o: BSTH.h main.c BST.c  Reader_Writer.c
	gcc $(CFLAGS) -Wall -c BST.c


clean:
	rm -f BST.o Reader_Writer.o main.o PA3

all: PA3


