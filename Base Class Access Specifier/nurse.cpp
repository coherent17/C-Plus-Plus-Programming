#include "person.h"
#include "nurse.h"

#include <iostream>

ostream& operator<<(ostream& out, Nurse& nurse){
    out << "Nurse : " << nurse.get_name() << ", " << nurse.get_age() << ", " << nurse.get_weight() << endl;
    return out;   
}