#ifndef PLAYER_H
#define PLAYER_H

#include "person.h"
#include <string>

/*
define base class-> bc, derived class-> dc
public inheritance:
bc: public -> dc: public
bc: protected -> dc: protected
bc: private -> dc: private
*/

class Player : public Person{
    public:
        Player() = default;

        //test for access data public inherited from base class
        void testPublic(){
            /*
            public:
                string name = "None";
            protected:
                int age = 0;
            private:
                int weight = 0;
            */
            name = "BlueDog";   //OK
            age = 20;           //OK
            //weight = 100;     //get compiler error
        }
    
    friend ostream& operator<<(ostream& out, Player& player);
};

#endif