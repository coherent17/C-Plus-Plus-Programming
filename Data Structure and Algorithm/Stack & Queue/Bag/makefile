CC = g++
CXXFLAGS = -g -Wall
BIN = main

all: $(BIN)

$(BIN): main.cpp Bag.hpp
	$(CC) $(CXXFLAGS) $^ -o $@

clean:
	rm -rf $(BIN) $(OBJ)