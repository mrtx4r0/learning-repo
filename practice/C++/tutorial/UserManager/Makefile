# 
TARGET := UserApp

CXX := g++

SRC_DIR := src
INC_DIR := include
OBJ_DIR := build/obj
BIN_DIR := bin

SRCS := $(SRC_DIR)/main.cpp \
		$(SRC_DIR)/User.cpp

OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CXXFLAGS := -Wall -Wextra -I$(INC_DIR)

.PHONY: all clean

all: $(BIN_DIR)/$(TARGET)

# 実行ファイル生成
$(BIN_DIR)/$(TARGET): $(OBJS)
	$(CXX) -o $@ $^

# オブジェクト生成
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $?

# 
clean:
	-rm -f $(OBJS) $(BIN_DIR)/$(TARGET)


