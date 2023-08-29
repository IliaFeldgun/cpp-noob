CC = g++
CFLAGS = -Wall -g
all: main.out

main.out: main.o matrix.o
	$(CC) $(CFLAGS) -o $@ $?

main.o: main.cpp matrix.o
	$(CC) $(CFLAGS) -c $< 

matrix.o: matrix.h

