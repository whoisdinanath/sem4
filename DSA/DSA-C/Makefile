# Directories
SRC_DIR := src
BIN_DIR := bin

# Compiler and flags
CC := gcc
CFLAGS := -Wall

# Find all source files in SRC_DIR
SRCS := $(wildcard $(SRC_DIR)/*.c)

# Create list of corresponding object files in BIN_DIR
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BIN_DIR)/%,$(SRCS))

# Rule to compile each source file to executable
$(BIN_DIR)/%: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

# Target to compile all source files
all: $(OBJS)
	@echo "Compilation successful!"

run:
	$(MAKE) all
	clear
	$(BIN_DIR)/$(FILE)

# Target to clean executables
clean:
	rm -f $(BIN_DIR)/*

.PHONY: all clean
