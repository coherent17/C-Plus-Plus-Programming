#include "shape.h"
#include <string>

using namespace std;

int Shape::count = 0;

Shape::Shape(string description){
    this->description = description;
    count++;
}

Shape::Shape() : Shape("None"){
    
}

Shape::~Shape(){
    count--;
}