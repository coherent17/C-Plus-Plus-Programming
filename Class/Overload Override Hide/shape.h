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

    virtual void draw()const{
        cout << "Shape::draw() called : " << description << endl;  
    }

    //overload the draw function in base class
    virtual void draw(int color_depth)const{
        cout << "Shape::draw() with : " << color_depth << endl;
    }
};


#endif