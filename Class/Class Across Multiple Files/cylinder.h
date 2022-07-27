#ifndef CYLINDER_H
#define CYLINDER_H

#include "constants.h"

class Cylinder{
    private:
        double r;
        double h;
    
    public:
        //constructors
        Cylinder() = default;
        Cylinder(double r_parameter, double h_parameter);

        //getter
        double get_r();
        double get_h();

        //setter
        void set_r(double r_parameter);
        void set_h(double h_parameter);

        //other method
        double volume();
};

#endif