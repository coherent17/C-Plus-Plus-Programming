#include <iostream>
using namespace std;

template <typename T> const T& maximum(const T& a, const T& b);

int main(){
    double a = 23.5;
    double b = 52.2;

    cout << &a << endl;     //0x7ffe98d616b8
    cout << &b << endl;     //0x7ffe98d616b0

    cout << maximum(a, b) << endl;
    return 0;
}

template <typename T> const T& maximum(const T& a, const T& b){
    cout << &a << endl;     //0x7ffe98d616b8
    cout << &b << endl;     //0x7ffe98d616b0
    return a > b ? a : b;
}

//compiler error note:
// template <typename T> T maximum(T a, T b);  call by value
// template <typename T> const T& maximum(const T& a, const T& b); call by reference