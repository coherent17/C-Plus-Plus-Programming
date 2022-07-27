#include <iostream>
#include <concepts>

using namespace std;

template <typename T>
concept TinyType = requires(T t){
    sizeof(T) <= 4;
    requires sizeof(T) <= 4;
};

//combine two concepts
template <typename T>
//T foo(T t) requires integral<T> || floating_point<T>
void print(T t) requires integral<T> && TinyType<T>{
    cout << t << endl;
}

int main(){
    char x = 56;
    double y = 5.6;
    long long int z = 899;
    print(x);   //work
    print(y);   //fail
    print(z);   //fail
    return 0;
}