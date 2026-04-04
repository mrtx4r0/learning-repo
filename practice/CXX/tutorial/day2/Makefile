# Makefile

CXX = g++
CPPFLAGS = -Wall -Wextra
LDFLAGS = -luser32	# user32.dllをリンク（MessageBoxの実装がある。Cコードのwindows.hはコンパイラへの指示のみ）
TARGET = msgbox.exe
SRCS = msgbox.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CPPFLAGS) -o $(TARGET) $^ $(LDFLAGS)

.PHONY: clean
clean: 
	del $(TARGET)