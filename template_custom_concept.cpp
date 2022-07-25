#include <iostream>
#include <concepts>

using namespace std;

template <typename T>
concept MyIntegral = is_integral_v<T>;

//make sure that the function parameter can be multiplied
template <typename T>
concept Multipliable = requires(T a, T b){
    a * b;
};

//make sure that the function parameter can be increased
template <typename T>
concept Incrementable = requires(T a){
    a += 1;
    a++;
    ++a;
}

//using own concept

//syntax1
template <typename T>
requires MyIntegral<T>
T add_1(T a, T b){
    return a + b;
}

template <MyIntegral T>
T add_2(T a, T b){
    return a + b;
}

auto add_3(MyIntegral auto a, MyIntegral auto b){
    return a + b;
}