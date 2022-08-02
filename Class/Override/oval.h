#ifndef OVAL_H
#define OVAL_H

#include "shape.h"

using namespace std;

class Oval : public Shape{

    private:
        double x_r = 0;
        double y_r = 0;

    public:
        //constructor
        Oval();
        Oval(double x_r, double x_y, string description);

        virtual void draw()const override{
            cout << "Oval::draw() called : "<<  description << ", " << x_r << ", " << y_r << endl;
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