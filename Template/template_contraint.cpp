#include <iostream>
#include <concepts>

using namespace std;

//a mechanism to place constraints on template type parameter
//using standard built in concepts

// Integral Types:
// 1. Integer values, signed or unsigned
// 2. Boolean values, where 0 is equivalent to false and any nonzero number is equivalent to true
// 3. Characters, which are automatically converted to an integer value by the compiler
// 4. Members of an enumerated type, which are interpreted as an integer by the compiler
// 5. Bit fields

//syntax 1
template <typename T>
requires integral<T>    //only integral types can be the parameters of this function template
T add(T a, T b){
    return a + b;
}

//syntax 2
template <integral T>
T add(T a, T b){
    return a + b;
}

//syntax 3
auto add(integral auto a, integral auto b){
    return a + b;
}

//syntax 4
template <integral T>
T add(T a, T b) requires integral<T>{
    return a + b;
}

int main(){
    
    //integer type
    cout << add(1, 2) << endl;

    //double type, not intergal type
    cout << add(11.1, 1.9) << endl;   //compile error

    return 0;
}