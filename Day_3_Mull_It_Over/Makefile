# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++17

# Source and target
#SRC = day_3.cpp
#TARGET = day_3

SRC = day_3_level_2.cpp
TARGET = day_3_level_2

# Rules
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Clean up build files
clean:
	rm -f $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)