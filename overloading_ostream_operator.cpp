//to print out the member in the class using cout conviently

#include <iostream>
using namespace std;

class Point{

    private:
        int x = 0;
        int y = 0;
    
    public:
        //constructor
        Point(int x, int y){
            this->x = x;
            this->y = y;
        }

    //overloading << to output the member in the class
    friend ostream &operator<< (ostream &out, Point point){
        out << "(" << point.x << ", " << point.y << ")";
        return out;
    }
};


int main(){
    Point p1(2, 3);
    Point p2(5, 6);

    cout << p1 << endl;
    cout << p2 << endl;

    return 0;
}