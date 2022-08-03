CC = g++
CXXFLAGS = -g -Wall
OBJ = shape.o ellipse.o
BIN = main

all: $(BIN)

%.o: %.cpp %.h
	$(CC) $(CXXFLAGS) -c $< -o $@

$(BIN): main.cpp $(OBJ)
	$(CC) $(CXXFLAGS)  $^ -o $@

clean:
	rm -rf $(BIN) $(OBJ)