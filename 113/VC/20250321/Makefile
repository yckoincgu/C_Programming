# Compiler and flags
CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -pedantic -Iinclude
DEBUG_FLAGS = -g -DDEBUG
RELEASE_FLAGS = -O2

# Detect Windows and adjust clear command
ifdef OS
    CLEAR_CMD = cls
else
    CLEAR_CMD = clear
endif

# Directories
SRC_DIR = src
INC_DIR = include
OBJ_DIR = obj
BIN_DIR = bin

# Source files
SRCS = $(SRC_DIR)/start.c $(SRC_DIR)/menu.c
OBJS = $(OBJ_DIR)/start.o $(OBJ_DIR)/menu.o
TARGET = $(BIN_DIR)/a.exe

# Default target
all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) -o $@ $(OBJS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) $(RELEASE_FLAGS) -c $< -o $@

$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/*.exe

.PHONY: all clean