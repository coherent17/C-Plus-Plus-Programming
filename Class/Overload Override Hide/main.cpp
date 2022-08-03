#include "shape.h"
#include "oval.h"
#include "circle.h"
#include <iostream>

using namespace std;

void draw_shape_through_pointer(Shape *shapeptr){
    shapeptr->draw();
}

void draw_shape_through_reference(const Shape& shaperef){
    shaperef.draw();
}

int main(){


    Shape sh1("Shape1");
    Oval ov1(2, 3.5, "Oval1");
    Circle cir1(3.3, "Circle1");


    // ov1.draw();
    // ov1.draw(3);

    // cir1.draw();
    // cir1.draw(5);

    Shape *shapeptr = new Circle(4 , "Circle2");
    //shapeptr->draw(45, "blue");     
    //this method define in oval class, therefore the shapeptr can't reference to this method


    return 0;
}