#ifndef NURSE_H
#define NURSE_H

#include "person.h"

/*
define base class-> bc, derived class-> dc
protected inheritance:
bc: public -> dc: protected
bc: protected -> dc: protected
bc: private -> dc: private
*/

class Nurse : protected Person{
    public:
        Nurse() = default;

        //test for access data public inherited from base class
        void testProtected(){
            /*
            public:
                string name = "None";
            protected:
                int age = 0;
            private:
                int weight = 0;
            */
            name = "ProtectedBlueDog";      //OK
            age = 500;                      //OK
            //weight = 100;                 //get compiler error
        }   

    friend ostream& operator<<(ostream& out, Nurse& nurse);     
};

#endif