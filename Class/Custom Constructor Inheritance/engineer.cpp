#include "person.h"
#include "engineer.h"
#include <iostream>

//error code
// Engineer::Engineer(string name, int age, int weight, int contract_count){
//     this->name = name;
//     this->age = age;
//     this->weight = weight;  //weight is private in base class
//     this->contract_count = contract_count;
// }

//can't set other member variable in this class
// Engineer::Engineer(string name, int age, int weight, int contract_count)
//     :name(name), age(age), weight(weight), contract_count(contract_count)
// {
//
// }

Engineer::Engineer(string name, int age, int weight, int contract_count): Person(name, age, weight){
    this->contract_count = contract_count;
    cout << "Custom constructor called for Engineer" << endl;
}

ostream& operator<<(ostream& out, const Engineer& engineer){
    out << "Engineer : " << engineer.get_name() << ", " << engineer.get_age() << ", " << engineer.get_weight() << ", " << engineer.contract_count << endl;
    return out;   
}