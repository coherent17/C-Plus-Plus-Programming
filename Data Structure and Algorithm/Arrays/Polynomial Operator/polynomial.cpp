#include "polynomial.h"
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

#define InitCapacity 100

using namespace std;

bool cmp(term a, term b){
    return a.exp > b.exp;
}

Polynomial::Polynomial(){
    terms = 0;
    capacity = InitCapacity;
    termArray = new term[capacity];
}

Polynomial::~Polynomial(){
    delete[] termArray;
}

void Polynomial::NewTerm(int coef, int exp){
    if(terms > capacity){
        cerr << "Too many terms in polynomial!" << endl;
    }

    termArray[terms].coef = coef;
    termArray[terms].exp = exp;
    terms++; 
}

void Polynomial::SetPolynomial(int termCounts, int *coef_array, int *exp_array){
    for(int i = 0; i < termCounts; i++){
        this->NewTerm(coef_array[i], exp_array[i]);
    }
    sort(termArray, termArray + termCounts, cmp);
}

int Polynomial::eval(int x_value){
    int result = 0;
    for(int i = 0; i < terms; i++){
        result += termArray[i].coef * (int)pow(x_value, termArray[i].exp);
    }
    return result;
}

void Polynomial::add(Polynomial& x, Polynomial& result){

    int this_index = 0, x_index = 0;
    while(this_index < terms && x_index < x.terms){

        //exponent same, sum the coefficient
        if(termArray[this_index].exp == x.termArray[x_index].exp){
            int new_coef = termArray[this_index].coef + x.termArray[x_index].coef;
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

void Polynomial::minus(Polynomial& x, Polynomial &result){

    int this_index = 0, x_index = 0;
    while(this_index < terms && x_index < x.terms){

        //exponent same, minus the coefficient
        if(termArray[this_index].exp == x.termArray[x_index].exp){
            int new_coef = termArray[this_index].coef - x.termArray[x_index].coef;
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
            result.NewTerm(-1 * x.termArray[x_index].coef, x.termArray[x_index].exp);
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