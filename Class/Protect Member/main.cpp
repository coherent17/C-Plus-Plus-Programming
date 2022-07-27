#include <iostream>
#include "player.h"
#include "person.h"

using namespace std;

int main(){
    Player p1("BlueDog", 165, 70, "BasketBall");
    cout << p1 << endl;

    //error: ‘int Person::height’ is protected within this context
    //cout << p1.height << endl;    
    return 0;
}