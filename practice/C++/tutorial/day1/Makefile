CXX = g++
CXXFLAGS = -Wall -Wextra

TARGET = hello.exe
SRCS = hello.cpp

$(TARGET): $(SRCS)
	$(CXX) $(CFLAGS) -o $@ $^


.PHONY:clean
clean:
	del $(TARGET)