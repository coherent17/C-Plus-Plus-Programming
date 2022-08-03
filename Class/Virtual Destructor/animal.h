#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

using namespace std;

class Animal{
    
    public:
        Animal() = default;
        Animal(string description);
        virtual ~Animal();
        
    protected: 
        std::string m_description;
};

#endif