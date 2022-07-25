#include <iostream>

using namespace std;

const double PI = 3.1415926535;

class Cylinder{
    private:
        double r;
        double h;

    public:
    //Constructor: called by compiler to init the class object
        //Cylinder() = default;     //let compiler do the empty constructor
        Cylinder(){
            r = 2;
            h = 2;
        }

        Cylinder(double r_parameter, double h_parameter){
            r = r_parameter;
            h = h_parameter;
        }

        double volume(){
            return PI * r * r * h;
        }
};

int main(){
    //using Cylinder() constructor to init the object
    Cylinder c1;
    cout << c1.volume() << endl;

    //using Cylinder(double r_parameter, double h_parameter) to init the object
    Cylinder c2(3, 10);
    cout << c2.volume() << endl;

}