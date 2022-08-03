#ifndef FELINE_H
#define FELINE_H

#include "animal.h"
#include <string>

using namespace std;

class Feline : public Animal{

    public:
        Feline() = default;
        Feline(string fur_style, string description);
        virtual ~Feline();

        string m_fur_style;
};

#endif