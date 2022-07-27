#include <iostream>
#include "cylinder.h"

using namespace std;

int main(){
    Cylinder c1(2, 3);

    cout << c1.get_r() << endl;
    cout << c1.get_h() << endl;
    cout << c1.volume() << endl;

    //modifie the data in the class
    c1.set_h(6);
    c1.set_r(5);
    

    cout << c1.get_r() << endl;
    cout << c1.get_h() << endl;
    cout << c1.volume() << endl;

    //managing a stack object through pointer
    Cylinder *c1ptr = &c1;
    cout << (*c1ptr).volume() << endl;
    cout << c1ptr->volume() << endl;

    //managing class object through pointer
    Cylinder *c2 = new Cylinder(11, 20);    //create object on the heap
    cout << (*c2).volume() << endl;
    cout << c2->volume() << endl;
    delete c2;
    return 0;
}