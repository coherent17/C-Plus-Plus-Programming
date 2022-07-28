#ifndef CIVIL_ENGINEER_H
#define CIVIL_ENGINEER_H

#include "engineer.h"
#include <string>
#include <iostream>

using namespace std;

class CivilEngineer : public Engineer{
    private:
        string speciality = "None";

    public:
        //constructor
        CivilEngineer();
        CivilEngineer(string name, int age, int weight, int contract_count, string speciality);

        //copy constructor
        CivilEngineer(const CivilEngineer& civilengineer);


    friend ostream& operator<<(ostream& out, CivilEngineer& civilengineer);
};

#endif