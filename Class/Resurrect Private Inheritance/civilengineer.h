#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H

#include "engineer.h"
#include <string>
#include <iostream>

using namespace std;

class CivilEngineer : public Engineer{
    public:
        CivilEngineer() = default;

        void testPrivateOverloading(){
            cout << add(10, 2) << endl;
            cout << add(10, 2, 8) << endl;
        }

    friend ostream& operator<<(ostream& out, CivilEngineer& civilengineer);
};

#endif