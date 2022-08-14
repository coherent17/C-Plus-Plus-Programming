CC = g++
CXXFLAGS = -g -Wall
BIN = main

all: $(BIN)

$(BIN): main.cpp Stack.hpp
	$(CC) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(BIN) $(OBJ)