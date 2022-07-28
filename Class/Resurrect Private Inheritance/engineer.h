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
        //constructor
        Engineer() = default;

        //let the derive class of engineer class can use the public/protected member private inheritance from base class
        using Person::name;
        using Person::age;
        //using Person::weight; can't resurrect the private member in the base class

        //test for the overloading function
        using Person::add;

    //let derive class of engineer class can use the base class method
    protected:
        using Person::get_name;
        using Person::get_age;
        using Person::get_weight;

    friend ostream& operator<<(ostream& out, Engineer& engineer);            
};

#endif