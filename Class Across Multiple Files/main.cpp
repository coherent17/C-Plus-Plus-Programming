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
    return 0;
}