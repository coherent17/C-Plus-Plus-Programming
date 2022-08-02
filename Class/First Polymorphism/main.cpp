#include "shape.h"
#include "oval.h"
#include "circle.h"
#include <iostream>

int main(){


    Shape sh1("Shape1");
    sh1.draw();                     //Shape::draw() called : Shape1

    Oval ov1(2, 3.5, "Oval1");
    ov1.draw();                     //Oval::draw() called : Oval1, 2, 0

    Circle cir1(3.3, "Circle1");
    cir1.draw();                    //Circle::draw() called : Circle1, 3.3



    //static binding
    //using base pointers
    //look the type of the pointer, and call the method in that class
    Shape *shapeptr = &sh1;
    shapeptr->draw();               //Shape::draw() called : Shape1

    shapeptr = &ov1;
    shapeptr->draw();               //Shape::draw() called : Oval1

    shapeptr = &cir1;
    shapeptr->draw();               //Shape::draw() called : Circle1



    //using base reference
    //look at the type of the reference, and call the method in that class
    Shape& shaperef = sh1;
    shaperef.draw();                //Shape::draw() called : Shape1

    shaperef = ov1;
    shaperef.draw();                //Shape::draw() called : Oval1

    shaperef = cir1;
    shaperef.draw();                //Shape::draw() called : Circle1

    return 0;
}