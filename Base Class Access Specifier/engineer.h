#ifndef ENGINEER_H
#define ENGINEER_H

#include "person.h"
#include <iostream>

/*
define base class-> bc, derived class-> dc
private inheritance:
bc: public -> dc: private to this class
bc: protected -> dc: private to this class
bc: private -> dc: private to base class
*/

class Engineer : private Person{
    public:
        Engineer() = default;
        //test for access data public inherited from base class
        void testPrivate(){
            /*
            public:
                string name = "None";
            protected:
                int age = 0;
            private:
                int weight = 0;
            */
            name = "PrivateBlueDog";      //OK
            age = 500620;                 //OK
            //weight = 100;               //get compiler error
        }

    friend ostream& operator<<(ostream& out, Engineer& engineer);            
};

#endif