CFLAGS = -Wall
LDFLAGS = -lm

all: hash

hash: main.o arvoreavl.o
	gcc -o myht main.o hash.o $(CFLAGS) $(LDFLAGS)

main.o: main.c arvoreavl.h
	gcc -c main.c $(CFLAGS)

aroreavl.o: arvoreavl.c arvoreavl.h
	gcc -c hash.c $(CFLAGS)	

clean:
	-rm -f *~ *.o
	
purge: clean
	-rm -f myht
