# Compiler
CC = gcc

# Compiler flags:
# -Iinclude  → include header directory
# -Wall      → enable warnings
# -Wextra    → extra warnings
# -O2        → optimization:warnings
CFLAGS = -Iinclude -Wall -Wextra -O2


# Source files
#SRC = src/main.c src/raid/raid6.c
SRC = src/main.c src/raid/raid6.c src/meta/metadata.c src/utils/logger.c

# Output binary name
OUT = astrahm

# Default build
all:
	$(CC) $(SRC) $(CFLAGS) -o $(OUT)

run: all
	./$(OUT)

# Remove compiled binary
clean:
	rm -f $(OUT)

