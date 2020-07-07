CC = gcc
CFLAGS = -Wall -g

all: elowen clean

elowen: obj/elowen.o obj/render.o
	$(CC) $(CFLAGS) -o build/elowen obj/elowen.o obj/render.o

obj/%.o: elowen/%.c
	$(CC) $(CFLAGS) -c -MMD $< -o $@

-include obj/*.d

.PHONY: clean
clean:
	rm -f obj/*
