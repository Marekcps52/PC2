CC=gcc
CFLAGS=-Wall -Wextra -pedantic -std=c99
LDFLAGS=-lncurses

SRC=main.c kurzor.c info.c
OBJ=$(SRC:.c=.o)

all: main

main: $(OBJ)
	$(CC) $^ -o $@ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) main

run: all
	./main

.PHONY: all clean
