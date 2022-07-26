#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include "person.h"

class Player : public Person{

    private:
        string game;
    
    public:
        //constructor
        Player() = default;
        Player(string game_param);

    friend void printPlayerInfo(Player& player);
};

#endif