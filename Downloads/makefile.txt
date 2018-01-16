CC=gcc
CFLAGS=-Wall -ansi

all: mainlineTestPart1 mainlineTestPart2 mainlineTestPart3

mainlineTestPart1 : mainlineTestPart1.o create2DArray.o set2DElement.o get2DElement.o free2DArray.o
	$(CC) -o mainlineTestPart1 mainlineTestPart1.o create2DArray.o set2DElement.o get2DElement.o free2DArray.o

mainlineTestPart1.o : mainlineTestPart1.c arrayDefns.h arrayVars.h
	$(CC) $(CFLAGS) -c mainlineTestPart1.c

create2DArray.o : create2DArray.c arrayVars.h
	$(CC) $(CFLAGS) -c create2DArray.c

set2DElement.o : set2DElement.c arrayVars.h
	$(CC) $(CFLAGS) -c set2DElement.c

get2DElement.o : get2DElement.c arrayVars.h
	$(CC) $(CFLAGS) -c get2DElement.c

free2DArray.o : free2DArray.c
	$(CC) $(CFLAGS) -c free2DArray.c

mainlineTestPart2 : mainlineTestPart2.o createStringArray.o setStringArray.o getStringArray.o freeStringArray.o
	$(CC) -o mainlineTestPart2 mainlineTestPart2.o createStringArray.o setStringArray.o getStringArray.o freeStringArray.o

mainlineTestPart2.o : mainlineTestPart2.c arrayDefns.h
	$(CC) $(CFLAGS) -c mainlineTestPart2.c

createStringArray.o : createStringArray.c 
	$(CC) $(CFLAGS) -c createStringArray.c

setStringArray.o : setStringArray.c 
	$(CC) $(CFLAGS) -c setStringArray.c

getStringArray.o : getStringArray.c
	$(CC) $(CFLAGS) -c getStringArray.c

freeStringArray.o : freeStringArray.c
	$(CC) $(CFLAGS) -c freeStringArray.c

mainlineTestPart3 : mainlineTestPart3.o createArray.o freeArray.o
	$(CC) -o mainlineTestPart3 mainlineTestPart3.o createArray.o freeArray.o

mainlineTestPart3.o : mainlineTestPart3.c arrayDefns.h
	$(CC) $(CFLAGS) -c mainlineTestPart3.c

createArray.o : createArray.c
	$(CC) $(CFLAGS) -c createArray.c

freeArray.o : freeArray.c
	$(CC) $(CFLAGS) -c freeArray.c

clean :
	rm mainlineTestPart1 mainlineTestPart1.o create2DArray.o set2DElement.o get2DElement.o free2DArray.o \
mainlineTestPart2 mainlineTestPart2.o createStringArray.o setStringArray.o getStringArray.o freeStringArray.o \
mainlineTestPart3 mainlineTestPart3.o createArray.o freeArray.o

