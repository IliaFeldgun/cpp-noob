CC = g++
CFLAGS = -W -Wall -Wextra -g 
LDFLAGS = -lncurses

all: main.out

main.out: main.o sprite.o
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS) 

main.o: main.cpp sprite.o *.cpp
	$(CC) $(CFLAGS) -c $<

sprite.o: sprite.cpp sprite.h
	$(CC) $(CFLAGS) -c $< $(LDFLAGS)

.PHONY: clean all
clean:
	rm -f *.o *.out

record:
	asciinema rec -c "make && ./main.out"
