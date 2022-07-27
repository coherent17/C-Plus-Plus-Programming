#include "person.h"
#include "player.h"
#include <iostream>

ostream& operator<<(ostream& out, Player& player){
    out << "Player : " << player.get_name() << ", " << player.get_age() << ", " << player.get_weight() << endl;
    return out;
}