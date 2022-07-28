#include "person.h"
#include <iostream>

using namespace std;

//constructor
Person::Person(){
    cout << "Default constructor called for Person" << endl;
}

Person::Person(string name, int age, int weight){
    this->name = name;
    this->age = age;
    this->weight = weight;
    cout << "Custom constructor called for Person" << endl;
}

//copy constructor
Person::Person(const Person& person)
: name{person.name}, age{person.age}, weight{person.weight}{
    cout << "Copy constructor called for Person" << endl;    
}

ostream& operator<<(ostream& out, const Person& person){
    out << "Person : " << person.name << ", " << person.age << ", " << person.weight << endl;
    return out;
}