#include "rectangle.h"
#include <string>

using namespace std;

Rectangle::Rectangle(double width , double height, string  description): Shape(description){
    this->m_width = width;
    this->m_height = height;
}