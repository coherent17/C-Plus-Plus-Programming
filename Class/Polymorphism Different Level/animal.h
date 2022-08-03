#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

using namespace std;

class Animal{
    
    public:
        Animal() = default;
        Animal(string description);
        virtual ~Animal() = default;
        
        virtual void breathe()const{
            std::cout << "Animal::breathe() called for : " << m_description << std::endl;
        }
        
    protected: 
        std::string m_description;
};

#endif