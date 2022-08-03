#include "polynomial.h"
#include <iostream>

int main(){

    Polynomial a;
    float a_coef_array[] ={3.5, 2.3, 4.2};
    int a_exp_array[] = {5, 3, 1};
    a.SetPolynomial(sizeof(a_coef_array)/sizeof(int), a_coef_array, a_exp_array);
    a.printPolynomial();


    Polynomial b;
    float b_coef_array[] ={1, 7, 17, 4.8, 9};
    int b_exp_array[] = {9, 7, 6, 5, 3};
    b.SetPolynomial(sizeof(b_coef_array)/sizeof(int), b_coef_array, b_exp_array);
    b.printPolynomial();

    Polynomial c;

    a.add(b, c);
    c.printPolynomial();

    return 0;

}