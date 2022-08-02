#include "shape.h"
#include "oval.h"
#include "circle.h"
#include <iostream>
#include <memory>

using namespace std;

int main(){


    Shape sh1("Shape1");
    Oval ov1(2, 3.5, "Oval1");
    Circle cir1(3.3, "Circle1");
    Shape sh2("Shape2");
    Oval ov2(6, 6.5, "Oval2");
    Circle cir2(3.7, "Circle2");


    //copy the object into the array
    //slicing the derived class to the base class, strip of the properties outside the base class
    Shape shape_collection1[] = {sh1, ov1, cir1, sh2, ov2, cir2};

    for(Shape& s : shape_collection1){
        //cout << sizeof(s) << endl;      //all same size as shape
        s.draw();
    }

    // Shape::draw() called : Shape1
    // Shape::draw() called : Oval1
    // Shape::draw() called : Circle1
    // Shape::draw() called : Shape2
    // Shape::draw() called : Oval2
    // Shape::draw() called : Circle2

    //array of reference is not allowed
    //const Shape& shape_collection2[] = {sh1, ov1, cir1, sh2, ov2, cir2};

    Shape *shape_collection3[] = {&sh1, &ov1, &cir1, &sh2, &ov2, &cir2};
    for(Shape *sptr : shape_collection3){
        //cout << sizeof(*sptr) << endl;
        sptr->draw();
    }

    // Shape::draw() called : Shape1
    // Oval::draw() called : Oval1, 2, 0
    // Circle::draw() called : Circle1, 3.3
    // Shape::draw() called : Shape2
    // Oval::draw() called : Oval2, 6, 0
    // Circle::draw() called : Circle2, 3.7


    shared_ptr<Shape> shape_collection4[] = {make_shared<Circle>(12.2, "Circle6"), make_shared<Oval>(10, 20, "Oval7")};
    for(auto& s : shape_collection4){
        s->draw();
    }

    // Circle::draw() called : Circle6, 12.2
    // Oval::draw() called : Oval7, 10, 0

    return 0;
}