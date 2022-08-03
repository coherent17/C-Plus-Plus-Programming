#ifndef DOG_H
#define DOG_H

#include "feline.h"
#include <string>

using namespace std;

class Dog : public Feline{
    public:
        Dog() = default;
        Dog(string fur_style, string description);
        virtual ~Dog();

};

#endif