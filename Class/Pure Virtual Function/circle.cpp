#include "circle.h"
#include <string>


Circle::Circle(double radius , string  description): Shape(description){
    this->m_radius = radius;
}