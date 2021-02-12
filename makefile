CFLAGS = -Wall
LDFLAGS = -lm

all: hash

hash: main.o hash.o
	gcc -o myht main.o hash.o $(CFLAGS) $(LDFLAGS)

main.o: main.c hash.h
	gcc -c main.c $(CFLAGS)

hash.o: hash.c hash.h
	gcc -c hash.c $(CFLAGS)	

clean:
	-rm -f *~ *.o
	
purge: clean
	-rm -f myht
