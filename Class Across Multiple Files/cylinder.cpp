#include "cylinder.h"

//constructor
Cylinder::Cylinder(double r_parameter, double h_parameter){
    r = r_parameter;
    h = h_parameter;
}

double Cylinder::volume(){
    return PI * r * r * h;
}

//getter
double Cylinder::get_r(){
    return r;
}

double Cylinder::get_h(){
    return h;
}

//setter
void Cylinder::set_r(double r_parameter){
    r = r_parameter;
}

void Cylinder::set_h(double h_parameter){
    h = h_parameter;
}