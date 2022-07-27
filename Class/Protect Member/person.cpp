#include "person.h"
#include <string>
#include <iostream>

using namespace std;

//constructor
Person::Person(int height_param, int weight_param, string name_param){
    height = height_param;
    weight = weight_param;
    name = name_param;
}

//getter
int Person::get_height(){
    return height;
}

int Person::get_weight(){
    return weight;
}

string Person::get_name(){
    return name;
}

//setter
void Person::set_height(int height_param){
    height = height_param;
}

void Person::set_weight(int weight_param){
    weight = weight_param;
}

void Person::set_name(string name_param){
    name = name_param;
}

ostream& operator<<(ostream& out, const Person &person){
    out << "Person : " << person.name << ", " << person.height << ", " << person.weight << endl;
    return out;
}