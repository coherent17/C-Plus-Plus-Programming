#include "person.h"
#include "engineer.h"
#include <iostream>

ostream& operator<<(ostream& out, Engineer& engineer){
    out << "Engineer : " << engineer.get_name() << ", " << engineer.get_age() << ", " << engineer.get_weight() << endl;
    return out;   
}