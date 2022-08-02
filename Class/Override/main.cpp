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

    
    Shape *shape_collection3[] = {&sh1, &ov1, &cir1, &sh2, &ov2, &cir2};
    for(Shape *sptr : shape_collection3){
        //cout << sizeof(*sptr) << endl;
        sptr->draw();
    }


    return 0;
}