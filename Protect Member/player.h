#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "person.h"

class Player : public Person{

    private:
        string game;
    
    public:
        //constructor
        Player() = default;
        Player(string name, int height, int weight, string game);

    friend ostream& operator<<(ostream& out, const Player& player);
};

#endif