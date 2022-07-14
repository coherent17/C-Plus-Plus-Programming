#include <iostream>

using namespace std;

int main(){
    int a = 3;
    int& ref_a = a;

    cout << a << endl;      //3
    cout << ref_a << endl;  //3

    //can modify a through reference
    ref_a++;

    cout << a << endl;      //4
    cout << ref_a << endl;  //4

    //const reference
    int b = 5;
    const int& ref_b = b;

    cout << b << endl;
    cout << ref_b << endl;

    //error : increment of read-only reference 
    //ref_b++;

    const int *aptr = &a;
    //error: assignment of read-only location ‘* aptr’
    //*aptr = 5;

    return 0;
}