#include <iostream>
using namespace std;


/*
repeating the same function body in function overload
, using function templace to reduce the complexity
*/
// int max(int a, int b){
//     return a > b ? a : b;
// }

// double max(double a, double b){
//     return a > b ? a : b;
// }

// float max(float a, float b){
//     return a > b ? a : b;
// }

//T a, T b: template parameter with call by value
template <typename T> 
T maximum(T a, T b){
    return a > b ? a : b;
}


int main(){
    int a = 3;
    int b = 5;

    double c = 6.5;
    double d = 9.8;

    float e = 9.4;
    float f = 3.5;

    // a, and b are template argument
    cout << maximum(a, b) << endl;
    cout << maximum(c, d) << endl;
    cout << maximum(e, f) << endl;

    //how about maximm(a, c), using specfic type to generate
    cout << maximum<double>(a, c) << endl;

    return 0;
}

//cppinsights.io

// #include <iostream>
// using namespace std;


// /*
// repeating the same function body in function overload
// , using function templace to reduce the complexity
// */
// // int max(int a, int b){
// //     return a > b ? a : b;
// // }

// // double max(double a, double b){
// //     return a > b ? a : b;
// // }

// // float max(float a, float b){
// //     return a > b ? a : b;
// // }

// //T a, T b: template parameter
// template <typename T> 
// T maximum(T a, T b){
//     return a > b ? a : b;
// }

// /* First instantiated from: insights.cpp:39 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// int maximum<int>(int a, int b)
// {
//   return a > b ? a : b;
// }
// #endif


// /* First instantiated from: insights.cpp:40 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// double maximum<double>(double a, double b)
// {
//   return a > b ? a : b;
// }
// #endif


// /* First instantiated from: insights.cpp:41 */
// #ifdef INSIGHTS_USE_TEMPLATE
// template<>
// float maximum<float>(float a, float b)
// {
//   return a > b ? a : b;
// }
// #endif



// int main()
// {
//   int a = 3;
//   int b = 5;
//   double c = 6.5;
//   double d = 9.8000000000000007;
//   float e = static_cast<float>(9.4000000000000003);
//   float f = static_cast<float>(3.5);
//   std::cout.operator<<(maximum(a, b)).operator<<(std::endl);
//   std::cout.operator<<(maximum(c, d)).operator<<(std::endl);
//   std::cout.operator<<(maximum(e, f)).operator<<(std::endl);
//   std::cout.operator<<(maximum<double>(static_cast<double>(a), c)).operator<<(std::endl);
//   return 0;
// }
