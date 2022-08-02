#ifndef CIRCLE_H
#define CIRCLE_H

#include "oval.h"
#include <string>
#include <iostream>

using namespace std;

class Circle : public Oval{
    public:
        //constructor
        Circle() = default;
        Circle(double r, string description);

        virtual void draw()const override{
            cout << "Circle::draw() called : " << description << ", " << get_x_r() << endl;
        }
};

#endif