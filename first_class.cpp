#include <iostream>

const double PI = 3.1415926535;

using namespace std;

class Cylinder{
    //member of class is private by default
    public:
        //member var can be stack var or pointers, can't be reference
        double radius = 1;
        double height = 1;

    public:
        double volume(){
            return PI * radius * radius * height;
        }
};

int main(){

    Cylinder c1;
    cout << c1.volume() << endl;

    c1.radius = 5;
    c1.height = 6;
    cout << c1.volume() << endl;

}