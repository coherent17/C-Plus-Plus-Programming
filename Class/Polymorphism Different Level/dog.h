#ifndef DOG_H
#define DOG_H

#include "feline.h"
#include <string>

using namespace std;

class Dog : public Feline{
    public:
        Dog() = default;
        Dog(string fur_style, string description);
        virtual ~Dog() = default;
        
        virtual void bark() const{
            cout << "Dog::bark called : Woof!" << endl;
        }

        virtual void breathe()const override{
            cout << "Dog::breathe called for : " << m_description << endl;
        }

        virtual void run() const override{
            cout << "Dog " << m_description << " is running" << endl;
        }

};

#endif