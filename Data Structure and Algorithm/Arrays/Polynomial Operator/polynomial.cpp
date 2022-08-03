#include "polynomial.h"
#include <iostream>
#include <string>

#define InitCapacity 100

using namespace std;

Polynomial::Polynomial(){
    terms = 0;
    capacity = InitCapacity;
    termArray = new term[capacity];
}

Polynomial::~Polynomial(){
    delete[] termArray;
}

void Polynomial::NewTerm(float coef, int exp){
    if(terms > capacity){
        cerr << "Too many terms in polynomial!" << endl;
    }

    termArray[terms].coef = coef;
    termArray[terms].exp = exp;
    terms++; 
}

void Polynomial::SetPolynomial(int termCounts, float *coef_array, int *exp_array){
    for(int i = 0; i < termCounts; i++){
        this->NewTerm(coef_array[i], exp_array[i]);
    }
}

void Polynomial::add(Polynomial& x, Polynomial& result)const{

    int this_index = 0, x_index = 0;
    while(this_index < terms && x_index < x.terms){

        //exponent same, sum the coefficient
        if(termArray[this_index].exp == x.termArray[x_index].exp){
            float new_coef = termArray[this_index].coef + x.termArray[x_index].coef;
            if(new_coef != 0){
                result.NewTerm(new_coef, x.termArray[x_index].exp);
                this_index++;
                x_index++;
            }
        }

        else if(termArray[this_index].exp > x.termArray[x_index].exp){
            result.NewTerm(termArray[this_index].coef, termArray[this_index].exp);
            this_index++;
        }

        else{
            result.NewTerm(x.termArray[x_index].coef, x.termArray[x_index].exp);
            x_index++;
        }
    }

    //remain term
    while(this_index < terms){
        result.NewTerm(termArray[this_index].coef, termArray[this_index].exp);
        this_index++;
    }

    while(x_index < x.terms){
        result.NewTerm(x.termArray[x_index].coef, x.termArray[x_index].exp);
        x_index++;
    }
}


void Polynomial::printPolynomial(){
    for(int i = 0; i < terms; i++){
        cout << termArray[i].coef << "x^"<< termArray[i].exp;
        if(i != terms - 1) cout << " + ";
    }
    cout << endl;
}