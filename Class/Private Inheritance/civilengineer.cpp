#include "person.h"
#include "engineer.h"
#include "civilengineer.h"
#include <iostream>

using namespace std;

ostream& operator<<(ostream& out, const CivilEngineer& civilengineer){
    //getter become private in engineer class, therefore can't access by civilengineer class
    //out << "CivilEngineer : " << civilengineer.get_name() << ", " << civilengineer.get_age() << ", " << civilengineer.get_weight() << endl;
    return out;  
}