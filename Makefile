# Compilation du Suika game
#   make       -> compile le jeu
#   make run   -> compile puis lance
#   make clean -> supprime l'executable

CC      = cc
CFLAGS  = -Wall -Wextra -std=c99 -g -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lraylib -lm

suika: main.c
	$(CC) $(CFLAGS) main.c -o suika $(LDFLAGS)

run: suika
	./suika

clean:
	rm -f suika

.PHONY: run clean
