CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -O2

SRC = src/main.c src/raid/raid6.c
OUT = astrahm

all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)

