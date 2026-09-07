CC = gcc
CFLAGS = -Wall

all: main test_list test_set

main: main.o hashmap.o set.o list.o utils.o
	$(CC) $(CFLAGS) -o main main.o hashmap.o set.o list.o utils.o

test_list: test_list.o list.o utils.o
	$(CC) $(CFLAGS) -o test_list test_list.o list.o utils.o

test_set: test_set.o set.o list.o utils.o
	$(CC) $(CFLAGS) -o test_set test_set.o set.o list.o utils.o

main.o: main.c hashmap.h set.h list.h utils.h
	$(CC) $(CFLAGS) -c main.c

test_list.o: test_list.c list.h
	$(CC) $(CFLAGS) -c test_list.c

test_set.o: test_set.c set.h list.h utils.h
	$(CC) $(CFLAGS) -c test_set.c

list.o: list.c list.h
	$(CC) $(CFLAGS) -c list.c

set.o: set.c set.h list.h utils.h
	$(CC) $(CFLAGS) -c set.c

hashmap.o: hashmap.c hashmap.h list.h utils.h
	$(CC) $(CFLAGS) -c hashmap.c

utils.o: utils.c utils.h
	$(CC) $(CFLAGS) -c utils.c

clean:
	rm -f *.o test_list test_set main

.PHONY: test_list test_set clean