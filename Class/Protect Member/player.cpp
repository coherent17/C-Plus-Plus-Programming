#include "player.h"
#include "person.h"
#include <iostream>

using namespace std;

Player::Player(string name, int height, int weight, string game){
    this->name = name;
    this->height = height;
    this->weight = weight;
    this->game = game;
}

//since we use protected in base class, player can access to the variable member in base class
ostream& operator<<(ostream& out, const Player& player){
    out << "Player : " << player.name << ", " << player.height << ", " << player.weight << endl;
    return out;
}