//method to read or modify member var of a class
#include <iostream>

using namespace std;

const double PI = 3.1415926535;

class Cylinder{
    private:
        double r;
        double h;
    
    public:
        //constructors
        Cylinder() = default;

        Cylinder(double r_parameter, double h_parameter){
            r = r_parameter;
            h = h_parameter;
        }

        //getter
        double get_r(){
            return r;
        }

        double get_h(){
            return h;
        }

        //setter
        void set_r(double r_parameter){
            r = r_parameter;
        }

        void set_h(double h_parameter){
            h = h_parameter;
        }

        //other method
        double volume(){
            return PI * r * r * h;
        }
};

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