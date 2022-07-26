#include "player.h"
#include "person.h"
#include <iostream>

using namespace std;

Player::Player(string game_param){
    game = game_param;
}

//no direct access to the base class member variable
void printPlayerInfo(Player& player){
    cout << "Player : " << player.get_name() << " " << player.get_height() << " " << player.get_weight() << " " << player.game << endl;
}