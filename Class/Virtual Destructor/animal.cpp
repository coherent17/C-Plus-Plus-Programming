#include "animal.h"

Animal::Animal(string description){
    this->m_description = description;
}

Animal::~Animal(){
    cout << "Animal destructor called" << endl;
}