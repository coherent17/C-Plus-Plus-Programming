#include "polynomial.h"
#include <iostream>

int main(){

    Polynomial a("polynomial a");                   //1x^5 + 2x^3 + 3x^1
    int a_coef_array[] ={3, 2, 1};
    int a_exp_array[] = {1, 3, 5};
    a.SetPolynomial(sizeof(a_coef_array)/sizeof(int), a_coef_array, a_exp_array);
    a.printPolynomial();


    Polynomial b("polynomial b");                   //1x^9 + 7x^8 + 4x^6
    int b_coef_array[] ={1, 7, 4};
    int b_exp_array[] = {9, 8, 6};
    b.SetPolynomial(sizeof(b_coef_array)/sizeof(int), b_coef_array, b_exp_array);
    b.printPolynomial();

    Polynomial addResult("test for a + b");
    a.add(b, addResult);                    //1x^9 + 7x^8 + 4x^6 + 1x^5 + 2x^3 + 3x^1
    addResult.printPolynomial();


    Polynomial minusResult("test for a - b");
    a.minus(b, minusResult);                  //-1x^9 + -7x^8 + -4x^6 + 1x^5 + 2x^3 + 3x^1
    minusResult.printPolynomial();

    Polynomial multResult("test for a * b");
    a.mult(b, multResult);                   //1x^14 + 7x^13 + 2x^12 + 18x^11 + 3x^10 + 29x^9 + 12x^7
    multResult.printPolynomial();

    Polynomial add_times_minus_Result("test for (a + b) * (a - b)");
    addResult.mult(minusResult, add_times_minus_Result);  //1x^18 + 14x^17 + 49x^16 + 8x^15 + 58x^14 + 14x^13 + 20x^12 + 36x^11 + 7x^10 + 58x^9 + 4x^8 + 24x^7 + 10x^6 + 12x^4 + 9x^2
    add_times_minus_Result.printPolynomial();

    Polynomial a_square("test for a * a");
    a.mult(a, a_square);
    a_square.printPolynomial();


    Polynomial b_square("test for b * b");
    b.mult(b, b_square);
    b_square.printPolynomial();


    Polynomial a_square_minus_b_square("test for (a * a) - (b * b)");
    a_square.minus(b_square, a_square_minus_b_square);
    a_square_minus_b_square.printPolynomial();

    //test for eval
    cout << add_times_minus_Result.eval(1) << endl;
    cout << a_square_minus_b_square.eval(1) << endl;
    cout << add_times_minus_Result.eval(2) << endl;
    cout << a_square_minus_b_square.eval(2) << endl;
    cout << add_times_minus_Result.eval(3) << endl;
    cout << a_square_minus_b_square.eval(3) << endl;


    //test for diff
    cout << boolalpha;
    cout << a_square_minus_b_square.diff(add_times_minus_Result) << endl;
    cout << a_square.diff(add_times_minus_Result) << endl;
    cout << a_square.diff(a_square) << endl;
    return 0;
}