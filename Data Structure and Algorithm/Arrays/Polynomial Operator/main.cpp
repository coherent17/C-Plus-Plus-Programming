#include "polynomial.h"
#include <iostream>

int main(){

    Polynomial a;
    int a_coef_array[] ={3, 2, 1};
    int a_exp_array[] = {1, 3, 5};
    a.SetPolynomial(sizeof(a_coef_array)/sizeof(int), a_coef_array, a_exp_array);
    a.printPolynomial();


    Polynomial b;
    int b_coef_array[] ={1, 7, 4};
    int b_exp_array[] = {9, 8, 6};
    b.SetPolynomial(sizeof(b_coef_array)/sizeof(int), b_coef_array, b_exp_array);
    b.printPolynomial();

    Polynomial c;
    a.add(b, c);
    c.printPolynomial();


    Polynomial d;
    a.minus(b, d);
    d.printPolynomial();

    Polynomial e;
    a.mult(b, e);
    e.printPolynomial();

    return 0;
}