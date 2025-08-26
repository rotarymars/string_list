CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = string_generator
SOURCE = main.cpp

all: $(TARGET)

$(TARGET): $(SOURCE)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCE)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET) output.txt

.PHONY: all run clean
