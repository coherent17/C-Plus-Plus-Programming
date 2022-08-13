#include "Bag.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    Bag<int> b1;
    b1.push(4);
    b1.push(6);
    b1.push(2);
    b1.push(7);
    b1.push(1);

    cout << "size of the bag : " << b1.size() << endl;
    cout << "first element in bag : " << b1.Element() << endl;
    cout << "data in bag : " << b1 << endl;


    b1.pop();
    cout << "size of the bag : " << b1.size() << endl;
    cout << "first element in bag : " << b1.Element() << endl;
    cout << "data in bag : " << b1 << endl;


    b1.pop();
    cout << "size of the bag : " << b1.size() << endl;
    cout << "first element in bag : " << b1.Element() << endl;
    cout << "data in bag : " << b1 << endl;


    Bag<char> b2;
    b2.push('f');
    b2.push('g');
    b2.push('d');
    b2.push('y');
    b2.push('t');

    cout << "size of the bag : " << b2.size() << endl;
    cout << "first element in bag : " << b2.Element() << endl;
    cout << "data in bag : " << b2 << endl;

    b2.pop();
    cout << "size of the bag : " << b2.size() << endl;
    cout << "first element in bag : " << b2.Element() << endl;
    cout << "data in bag : " << b2 << endl;

    return 0;
}