CC = g++
CXXFLAGS = -g -Wall -std=c++11
OBJ = person.o engineer.o civilengineer.o
BIN = main

all: $(BIN)

%.o: %.cpp %.h
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BIN): main.cpp $(OBJ)
	$(CC) $(CXXFLAGS)  $^ -o $@

clean:
	rm -rf $(BIN) $(OBJ)