#include "polynomial.h"
#include <iostream>

int main(){

    Polynomial a;
    int a_coef_array[] ={3, 2, 4, 9};
    int a_exp_array[] = {1, 3, 7, 5};
    a.SetPolynomial(sizeof(a_coef_array)/sizeof(int), a_coef_array, a_exp_array);
    a.printPolynomial();
    cout << a.eval(1) << endl;


    Polynomial b;
    int b_coef_array[] ={1, 7, 17, 4, 9};
    int b_exp_array[] = {9, 7, 6, 5, 3};
    b.SetPolynomial(sizeof(b_coef_array)/sizeof(int), b_coef_array, b_exp_array);
    b.printPolynomial();
    cout << b.eval(1) << endl;

    Polynomial c;

    a.add(b, c);
    c.printPolynomial();
    cout << c.eval(1) << endl;


    Polynomial d;
    a.minus(b, d);
    d.printPolynomial();
    return 0;

}