#include "Bag.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(){
    Bag<int> b1(3);
    b1.push(4);
    b1.push(6);
    b1.push(2);
    cout << b1 << endl;

    b1.push(7);
    b1.push(1);

    cout << b1 << endl;


    b1.pop();
    cout << b1 << endl;


    b1.pop();
    cout << b1 << endl;


    Bag<char> b2(3);
    b2.push('f');
    b2.push('g');
    b2.push('d');
    cout << b2 << endl;

    b2.push('y');
    b2.push('t');

    cout << b2 << endl;

    b2.pop();
    cout << b2 << endl;

    return 0;
}