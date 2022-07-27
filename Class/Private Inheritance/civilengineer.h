#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H

#include "engineer.h"
#include <string>


class CivilEngineer : public Engineer{
    public:
        CivilEngineer() = default;

        void testPrivateInheritance(){

            //compiler error
            // string _name = get_name();
            // int _age = get_age();
            // int _weight = get_weight();
        }

    friend ostream& operator<<(ostream& out, CivilEngineer& civilengineer);
};

#endif