#include <iostream>
#include <concepts>
#include <string>

using namespace std;

//nested requirement
template <typename T>
concept TinyType = requires(T t){
    sizeof(T) <= 4;             //only check the syntax sizeof(T) is valid
    requires sizeof(T) <= 4;    //check the expression is true
};

//function using TinyType concept
template <typename T>
requires TinyType<T>
T add1(T a, T b){
    return a + b;
}

//compound requirement
template <typename T>
concept Addable = requires(T a, T b){
    {a + b} -> convertible_to<int>;
    //check if a + b is valid syntax and the result can be convertible to int
};

template <typename T>
requires Addable<T>
T add2(T a, T b){
    return a + b;
}

int main(){
    //one byte type
    char x = 67;
    char y = 56;

    cout << add1(x, y) << endl;

    //8 bytes type
    double a = 5;
    double b = 6;

    cout << add1(a, b) << endl;
    //it will pass the first line in concept
    //because sizeof(double) is a valid syntax
    //and terminate in second line because sizeof(double) is 8 bytes


    //work because explicity convet the type char to int, therefore can be add
    cout << add2(x, y) << endl;

    //work, add two double is valid syntax, and can be convert to int
    cout << add2(a, b) << endl;

    string c = "Hello";
    string d = "World";

    //not work, add up two string means concatenate, but the result can't be turn into int
    cout << add2(c, d) << endl;

    return 0;
}