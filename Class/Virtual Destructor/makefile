CC = g++
CXXFLAGS = -g -Wall -std=c++17
OBJ = animal.o feline.o dog.o
BIN = main

all: $(BIN)

%.o: %.cpp %.h
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BIN): main.cpp $(OBJ)
	$(CC) $(CXXFLAGS)  $^ -o $@

clean:
	rm -rf $(BIN) $(OBJ)