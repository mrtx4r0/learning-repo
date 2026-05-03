CXX := g++
CXXFLAGS := -std=c++11 -Wall -Wextra -Iinclude
TARGET := device_sample
SRCS := src/main.cpp src/Device.cpp src/CameraDevice.cpp src/PrinterDevice.cpp
OBJS := $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
