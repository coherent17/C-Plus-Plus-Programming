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

class Engineer : public Person{
    private:
        int contract_count = 0;

    public:
        //constructor
        Engineer() = default;
        Engineer(string name, int age, int weight, int contract_count);

        //getter
        int get_contract_count() const{
            return contract_count;
        }


    friend ostream& operator<<(ostream& out, const Engineer& engineer);            
};

#endif