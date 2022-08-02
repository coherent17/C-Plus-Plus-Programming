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

    //Dynamic binding using virtual function, using the type of the actual object
    Shape *shapeptr = &sh1;
    shapeptr->draw();       //Shape::draw() called : Shape1

    shapeptr = &ov1;
    shapeptr->draw();       //Oval::draw() called : Oval1, 2, 0

    shapeptr = &cir1;
    shapeptr->draw();       //Circle::draw() called : Circle1, 3.3

    draw_shape_through_pointer(&sh1);       //Shape::draw() called : Shape1
    draw_shape_through_pointer(&ov1);       //Oval::draw() called : Oval1, 2, 0
    draw_shape_through_pointer(&cir1);      //Circle::draw() called : Circle1, 3.3



    Shape& shaperef1 = sh1;
    shaperef1.draw();                       //Shape::draw() called : Shape1

    Shape& shaperef2 = ov1;
    shaperef2.draw();                       //Oval::draw() called : Oval1, 2, 0

    Shape& shaperef3 = cir1;
    shaperef3.draw();                       //Circle::draw() called : Circle1, 3.3

    draw_shape_through_reference(sh1);      //Shape::draw() called : Shape1
    draw_shape_through_reference(ov1);      //Oval::draw() called : Oval1, 2, 0
    draw_shape_through_reference(cir1);     //Circle::draw() called : Circle1, 3.3


    Shape *shape_collection[] = {&sh1, &ov1, &cir1};

    for(auto sptr : shape_collection){
        sptr->draw();
    }

    return 0;
}