#include <iostream>

using namespace std;

int main(){

    //non-initialized pointer
    int *a;
    cout << a << endl;
    //cout << *a << endl;   //segmentation fault


    //delete pointer
    int *b = new int (8);
    cout << b << endl;
    cout << *b << endl;

    delete b;
    cout << b << endl;      //undefined behavior
    cout << *b << endl;     //undefined behavior

    //multiple pointer point to same address
    int *c = new int(4);
    int *d = c;

    cout << c << endl;
    cout << d << endl;
    cout << *c << endl;
    cout << *d << endl;

    delete c;
    cout << c << endl;
    cout << d << endl;
    cout << *c << endl;     //undefined behavior
    cout << *d << endl;     //undefined behavior

    return 0;
}