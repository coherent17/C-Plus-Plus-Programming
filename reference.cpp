#include <iostream>

using namespace std;

int main(){
    int a = 45;
    int& ref_a = a;

    cout << a << endl;              //45
    cout << ref_a << endl;          //45
    cout << &a << endl;             //0x7ffd44750434
    cout << &ref_a << endl;         //0x7ffd44750434
    cout << sizeof(int) << endl;    //4
    cout << sizeof(int&) << endl;   //4

    //modify a throught the alias
    ref_a = 55;
    cout << a << endl;              //55
    cout << ref_a << endl;          //55
    cout << &a << endl;             //0x7ffd44750434
    cout << &ref_a << endl;         //0x7ffd44750434

}