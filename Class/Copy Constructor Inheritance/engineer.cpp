#include "person.h"
#include "engineer.h"
#include <iostream>


//constructor
Engineer::Engineer(){
    cout << "Default constructor called for Engineer" << endl;
}

Engineer::Engineer(string name, int age, int weight, int contract_count): Person(name, age, weight){
    this->contract_count = contract_count;
    cout << "Custom constructor called for Engineer" << endl;
}

Engineer::Engineer(const Engineer& engineer)
: Person(engineer), contract_count{engineer.contract_count}{
    cout << "Copy constructor called for Engineer" << endl;
}

ostream& operator<<(ostream& out, const Engineer& engineer){
    out << "Engineer : " << engineer.get_name() << ", " << engineer.get_age() << ", " << engineer.get_weight() << ", " << engineer.contract_count << endl;
    return out;   
}