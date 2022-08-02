#ifndef SHAPE_H
#define SHAPE_H

#include <string>
#include <iostream>

using namespace std;

class Shape{
    protected:
        string description = "None";

    public:
        //constructor:
        Shape() = default;
        Shape(string description);

    void draw()const{
        cout << "Shape::draw() called : " << description << endl;  
    }
};


#endif