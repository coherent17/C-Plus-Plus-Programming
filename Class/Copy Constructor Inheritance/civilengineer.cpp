#include "person.h"
#include "engineer.h"
#include "civilengineer.h"
#include <iostream>

using namespace std;

CivilEngineer::CivilEngineer(){
    cout << "Default constructor called for civilEngineer" << endl;
}

CivilEngineer::CivilEngineer(string name, int age, int weight, int contract_count, string speciality) : Engineer(name, age, weight, contract_count){
    this->speciality = speciality;
    cout << "Custom constructor called for civilEngineer" << endl;
}

CivilEngineer::CivilEngineer(const CivilEngineer& civilengineer)
: Engineer(civilengineer), speciality{civilengineer.speciality}{
    cout << "Copy constructor called for civilEngineer" << endl;
}

ostream& operator<<(ostream& out, CivilEngineer& civilengineer){
    //getter become private in engineer class, therefore can't access by civilengineer class
    out << "CivilEngineer : " << civilengineer.get_name() << ", " << civilengineer.get_age() << ", " << civilengineer.get_weight() << ", " << civilengineer.get_contract_count() << ", " << civilengineer.speciality << endl;
    return out;  
}