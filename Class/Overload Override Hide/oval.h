#ifndef OVAL_H
#define OVAL_H

#include "shape.h"
#include <string>

using namespace std;

class Oval : public Shape{

    private:
        double x_r = 0;
        double y_r = 0;

    public:
        //constructor
        Oval();
        Oval(double x_r, double x_y, string description);

        //hide all overload method in inherite class, this is the only overload function in derived class
        virtual void draw()const override{
            cout << "Oval::draw() called : "<<  description << ", " << x_r << ", " << y_r << endl;
        }

        //if we want to override the method in shape class with one parameter
        // virtual void draw(int color_depth)const{
        //     cout << "Oval::draw() called with " << color_depth << endl;
        // }
 

        //function overload in oval class, not going to know in shape ptr
        virtual void draw(int color_depth, string color)const{
            cout << "Oval::draw(int, string) with " << color_depth << ", " << color << endl;
        }



    protected:
        //getter
        double get_x_r()const{
            return x_r;
        }

        double get_y_r()const{
            return y_r;
        }
};

#endif