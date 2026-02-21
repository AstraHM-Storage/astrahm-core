# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O2 -pthread -Iinclude

SRC = \
src/main.c \
src/raid/raid6.c \
src/meta/metadata.c \
src/utils/logger.c \
src/storage/disk.c \
src/storage/stripe.c \
src/storage/rebuild.c \
src/storage/disk_manager.c \
src/storage/parallel_io.c \
src/storage/thread_io.c	\
src/storage/io_queue.c \
src/utils/checksum.c \
src/storage/disk_health.c

TARGET = astrahm

all:
	$(CC) $(SRC) $(CFLAGS) -o $(TARGET)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)
# CC = gcc
#
# # Compiler flags:
# # -Iinclude  → include header directory
# # -Wall      → enable warnings
# # -Wextra    → extra warnings
# # -O2        → optimization:warnings
# CFLAGS = -Iinclude -Wall -Wextra -O2
# CFLAGS = -Wall -Wextra -O2 -pthread
#
# # Source files
# #SRC = src/main.c src/raid/raid6.c
# SRC = src/main.c src/raid/raid6.c src/meta/metadata.c src/utils/logger.c src/storage/disk.c src/storage/stripe.c src/storage/rebuild.c src/storage/disk_manager.c src/storage/parallel_io.c src/storage/thread_io.c
# # Output binary name
# OUT = astrahm
#
# # Default build
# all:
# 	$(CC) $(SRC) $(CFLAGS) -o $(OUT)
#
# run: all
# 	./$(OUT)
#
# # Remove compiled binary
# clean:
# 	rm -f $(OUT)
#
