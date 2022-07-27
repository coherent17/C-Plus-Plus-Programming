#include <iostream>

using namespace std;

/*
reference:

*   No need fot dereference
*   Can't be changed to reference something else
*   Must be init and declaration


pointer:

*   Must dereference to read write throught the pointed value
*   Can be changed to point another things
*   Can be declared un init

*/

int main(){

    int a = 5;
    int& ref_a = a;
    int *aptr = &a;

    cout << a << endl;      //5
    cout << ref_a << endl;  //5
    cout << *aptr << endl;  //5


    //writing through pointer
    *aptr = 6;

    cout << a << endl;      //6
    cout << ref_a << endl;  //6
    cout << *aptr << endl;  //6

    //writing throught reference
    ref_a = 7;
    
    cout << a << endl;      //7
    cout << ref_a << endl;  //7
    cout << *aptr << endl;  //7


    //can't make reference to something else
    int b = 3;
    ref_a = b;
    cout << a << endl;      //3
    cout << ref_a << endl;  //3
    cout << *aptr << endl;  //3

    ref_a = 10;
    cout << a << endl;      //10
    cout << ref_a << endl;  //10
    cout << *aptr << endl;  //10
    cout << b << endl;      //3     will not change

    return 0;
}