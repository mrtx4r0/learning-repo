# ==========================
# プロジェクト設定
# ==========================
TARGET      := sample_app
CC			:= gcc

# ディレクトリ
SRC_DIR		:= src
INC_DIR		:= include
OBJ_DIR		:= build/obj
DEP_DIR		:= build/dep
BIN_DIR		:= bin

# ソース一覧
SRCS := \
	$(SRC_DIR)/main.c \
	$(SRC_DIR)/app.c \
	$(SRC_DIR)/mathutil.c

# オブジェクト・依存関係ファイル
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS := $(SRCS:$(SRC_DIR)/%.c=$(DEP_DIR)/%.d)

# ==========================
# ビルドタイプ
# ==========================
BUILD ?= debug

ifeq ($(BUILD), debug)
	CFLAGS := -g -O0 -Wall -Wextra
else ifeq ($(BUILD), release)
	CFLAGS := -O2 =DNDEBUG
endif

CFLAGS += -I$(INC_DIR)

# ==========================
# ルール
# ==========================
.PHONY: all clean

all: $(BIN_DIR)/$(TARGET)

# 実行ファイル生成
$(BIN_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $^ -o $@

# オブジェクト生成(依存関係も同時に生成)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) $(DEP_DIR)
	$(CC) $(CFLAGS) -MMD -MP -MF $(DEP_DIR)/$*.d -c $< -o $@

# 依存関係ファイルも読み込む
-include $(DEPS)

clean:
	rm -rf build bin
