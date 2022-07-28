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
        CivilEngineer() = default;
        CivilEngineer(string name, int age, int weight, int contract_count, string speciality);


    friend ostream& operator<<(ostream& out, CivilEngineer& civilengineer);
};

#endif