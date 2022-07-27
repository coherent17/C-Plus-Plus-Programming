#include <iostream>

using namespace std;

int main(){
    //dynamic allocate the memory on the heap, 
    //instead of storing on the stack (local variable)
    int *ptr = nullptr;
    ptr = new int;      //create 4 bytes memory on the heap
    *ptr = 5;           //write data into the memory

    //or can be declared :
    //int *ptr = new int (5);

    cout << ptr << endl;
    cout << *ptr << endl;

    //return the memory on the heap
    delete ptr;
    ptr = nullptr;

    return 0;
}