#include <iostream>
using namespace std;

template <typename T> T maximum(T a, T b){
    return a > b ? a : b;
}

//if pass the int pointer, will go to this block
template<>
int *maximum<int *>(int *a, int *b){
    return *a > *b ? a : b;
}

int main(){
    int a = 5;
    int b = 3;
    double c = 4;
    double d = 6;

    cout << maximum(a, b) << endl;
    cout << maximum(c, d) << endl;

    //when passing the int pointer as argument will compare the value which point to instead of comparing with the value of address
    cout << *maximum(&a, &b) << endl;
    return 0;
}
