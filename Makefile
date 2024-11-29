# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall
 
# Directories
SRC_DIR = src
INCLUDE_DIR = include

# Target executable
TARGET = VoleMachineSimulator.exe

# Source files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)

# Object files (compiled directly without obj folder)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -o $@ $(OBJS)

# Compile source files into object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean up build files
clean:
	del /Q *.o $(TARGET)

# Phony targets
.PHONY: all clean
