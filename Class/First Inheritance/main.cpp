#include <iostream>
#include "player.h"
#include "person.h"

int main(){
    Player p1("BasketBall");

    //using base setter to change the private member in base class
    p1.set_height(170);
    p1.set_weight(65);
    p1.set_name("BlueDog");
    printPlayerInfo(p1);

    return 0;
}