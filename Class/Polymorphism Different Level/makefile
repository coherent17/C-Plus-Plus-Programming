CC = g++
CXXFLAGS = -g -Wall
OBJ = animal.o feline.o bird.o dog.o cat.o pigeon.o crow.o
BIN = main

all: $(BIN)

%.o: %.cpp %.h
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BIN): main.cpp $(OBJ)
	$(CC) $(CXXFLAGS)  $^ -o $@

clean:
	rm -rf $(BIN) $(OBJ)