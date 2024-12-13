# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++20 -Wall -g -Iinc

# Source files
SRCS = src/main.cpp src/file_handler.cpp src/text_filter.cpp src/maze.cpp src/maze_walker.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable
EXEC = main

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm -f $(OBJS) $(EXEC)

.PHONY: all clean