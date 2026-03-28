# Makefile

CXX = g++
CPPFLAGS = -Wall -Wextra
LDFLAGS = -mwindows

TARGET = window.exe
SRCS = main.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CPPFLAGS) -o $(TARGET) $^ $(LDFLAGS)

.PHONY: clean
clean: 
	del $(TARGET)