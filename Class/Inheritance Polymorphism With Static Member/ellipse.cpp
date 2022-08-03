#include "ellipse.h"
#include <string>

using namespace std;

int Ellipse::count{0};

Ellipse::Ellipse(double x_radius, double y_radius, string description): Shape(description){
    this->m_x_radius = x_radius;
    this->m_y_radius = y_radius;
    count++;
}

Ellipse::Ellipse(): Ellipse(0.0,0.0,"NoDescription"){
    
}

Ellipse::~Ellipse(){
    --count;
}
