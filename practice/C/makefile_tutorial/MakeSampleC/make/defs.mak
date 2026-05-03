BUILD ?= prod

CC := gcc
RM := rm -rf
MKDIR_P := mkdir -p

CPPFLAGS := -I$(PRJ_ROOT)/include
CFLAGS_COMMON := -Wall -Wextra -std=c11
LDFLAGS :=

CFLAGS_prod := -O2 -DNDEBUG
CFLAGS_test := -O0 -g -DTEST

LIB_SRCS := \
	$(PRJ_ROOT)/src/lib/math/add.c \
	$(PRJ_ROOT)/src/lib/math/mul.c

APP_SRCS := \
	$(PRJ_ROOT)/src/app/main.c \
	$(LIB_SRCS)

TEST_SRCS := \
	$(PRJ_ROOT)/tests/unit/test_main.c \
	$(LIB_SRCS)

OBJDIR := $(PRJ_ROOT)/build/$(BUILD)/obj
BINDIR := $(PRJ_ROOT)/build/$(BUILD)/bin

APP_OBJS := $(patsubst $(PRJ_ROOT)/%.c,$(OBJDIR)/%.o,$(APP_SRCS))
TEST_OBJS := $(patsubst $(PRJ_ROOT)/%.c,$(OBJDIR)/%.o,$(TEST_SRCS))

APP_BIN := $(BINDIR)/app_sample
TEST_BIN := $(BINDIR)/test_sample

CFLAGS := $(CFLAGS_COMMON) $(CFLAGS_$(BUILD))
