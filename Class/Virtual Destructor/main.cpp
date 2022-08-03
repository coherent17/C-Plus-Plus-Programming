#include <iostream>
#include "dog.h"


int main(){
    Dog dog1;
    // Dog destructor called
    // Feline destructor called
    // Animal destructor called

    Animal *animalptr = new Dog;
    delete animalptr;
    //if no virtual destructor: Animal destructor called
    
    // Dog destructor called
    // Feline destructor called
    // Animal destructor called
}