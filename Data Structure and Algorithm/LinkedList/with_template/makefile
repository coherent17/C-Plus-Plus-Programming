CC = g++
CXXFLAGS = -g -Wall
BIN = main

all: $(BIN)

$(BIN): main.cpp linkedlist.h
	$(CC) $(CXXFLAGS)  $^ -o $@

clean:
	rm -rf $(BIN) $(OBJ)