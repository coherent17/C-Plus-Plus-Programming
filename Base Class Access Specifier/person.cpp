#include "person.h"
#include <iostream>

using namespace std;

//constructor
Person::Person(string name, int age, int weight){
    this->name = name;
    this->age = age;
    this->weight = weight;
}

ostream& operator<<(ostream& out, Person& person){
    out << "Person : " << person.name << ", " << person.age << ", " << person.weight << endl;
    return out;
}