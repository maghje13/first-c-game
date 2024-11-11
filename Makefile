# Compiler and flags
CC := gcc
CFLAGS := -Wall -Wextra -I./src -I/opt/homebrew/include
LDFLAGS := -L/opt/homebrew/lib -lraylib

# Directories
SRC_DIR := src
BUILD_DIR := build
EXECUTABLE_NAME := game

# Executable name
TARGET := $(BUILD_DIR)/$(EXECUTABLE_NAME)

# Source files and object files
SRCS := $(wildcard $(SRC_DIR)/*.c)
OBJS := $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SRCS))

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET) $(LDFLAGS)

# Rule to compile each .c file to .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -rf $(BUILD_DIR)

# Optional: Run the executable
run: $(TARGET)
	./$(TARGET)
