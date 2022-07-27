#include <iostream>

using namespace std;

int main(){
    int a = 5;
    int *aptr = nullptr;    //init with nullptr instead NULL

    double b;
    double *bptr = nullptr;

    //pointer store the address, therefore same size (bytes)
    cout << sizeof(a) << endl;      //4
    cout << sizeof(aptr) << endl;   //8

    cout << sizeof(b) << endl;      //8
    cout << sizeof(bptr) << endl;   //8

    aptr = &a;
    cout << aptr << endl;   //pointer value : the address of a
    cout << &a <<endl;      //the address of a
    cout << *aptr <<endl;   //dereference the pointer : the value store in the address
    cout << a << endl;      //the value of a

    char s = 'a';
    char *sptr = &s;
    cout << s << endl;
    cout << *sptr << endl;

    //expand the string into char array, and msg point to the first char
    //if dereference the pointer, get the first character
    const char *msg = "Hello World";
    cout << "message = " << msg << endl;    //print out the entire string instead of the address of the first char
    cout << *msg << endl;       //H
    cout << msg[0] << endl;     //H
    cout << &msg[0] << endl;    //Hello World
    cout << &msg << endl;       // the address of the first char

    return 0;
}