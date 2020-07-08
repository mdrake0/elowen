CC = gcc
CFLAGS = -Wall -g
CFLAGS_RELEASE = -Wall

all: elowen clean

release: elowen-release clean

elowen-release: obj/elowen.o obj/render.o
	$(CC) $(CFLAGS_RELEASE) -o build/elowen obj/elowen.o obj/render.o -lncurses

elowen: obj/elowen.o obj/render.o
	$(CC) $(CFLAGS) -o build/elowen obj/elowen.o obj/render.o -lncurses

obj/render.o: elowen/render.c
	$(CC) $(CFLAGS) -c -MMD $< -o $@

obj/%.o: elowen/%.c
	$(CC) $(CFLAGS) -c -MMD $< -o $@

-include obj/*.d

.PHONY: clean
clean:
	rm -f obj/*
