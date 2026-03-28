# Layered sample Makefile -----------------------------------------------
CC := gcc
CSTD := -std=c11
WARN := -Wall -Wextra -Wpedantic
OPT := -O2
INCLUDES := -Iinclude
CFLAGS := $(CSTD) $(WARN) $(OPT) $(INCLUDES)

SRC_DIR := src
BUILD_DIR := build
BIN_DIR := bin
TARGET_NAME := layered_stats
ARGS ?= 10.0 25.5 31.25 18

SRCS := \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/app/cli/cli.c \
	$(SRC_DIR)/app/math/operations.c
OBJS := $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

ifeq ($(OS),Windows_NT)
	EXE_EXT := .exe
else
	EXE_EXT :=
endif
TARGET := $(BIN_DIR)/$(TARGET_NAME)$(EXE_EXT)

ifeq ($(OS),Windows_NT)
SHELL := cmd.exe
.SHELLFLAGS := /C

define make-dir
	@if not exist "$(1)" mkdir "$(1)"
endef

define clean-dir
	@if exist "$(1)" rmdir /S /Q "$(1)"
endef

define show-tree
	@tree /F
endef
else

define make-dir
	@mkdir -p "$(1)"
endef

define clean-dir
	@rm -rf "$(1)"
endef

define show-tree
	@tree -a
endef
endif

.PHONY: all clean run tree

all: $(TARGET)

$(TARGET): $(OBJS)
	$(call make-dir,$(dir $@))
	$(CC) $(CFLAGS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(call make-dir,$(dir $@))
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

run: $(TARGET)
	$(TARGET) $(ARGS)

tree:
	$(call show-tree)

clean:
	$(call clean-dir,$(BUILD_DIR))
	$(call clean-dir,$(BIN_DIR))

-include $(DEPS)
