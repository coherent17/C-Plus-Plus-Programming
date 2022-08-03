#include "polynomial.h"
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

#define InitCapacity 100
#define NOT_FOUND INT32_MIN

using namespace std;

bool cmp(term a, term b){
    return a.exp > b.exp;
}

Polynomial::Polynomial(string description){
    terms = 0;
    capacity = InitCapacity;
    termArray = new term[capacity];
    this->description = description;
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
    cout << description <<"(" << x_value <<") : ";
    return result;
}

int Polynomial::get_coef(int exp){
    int result = NOT_FOUND;
    for(int i = 0; i < terms; i++){
        if(termArray[i].exp == exp) return i;
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

void Polynomial::mult(Polynomial& x, Polynomial &result){
    int new_coef = 0;
    int new_exp = 0;
    int new_index = NOT_FOUND;
    for(int i = 0; i < terms; i++){
        for(int j = 0; j < x.terms; j++){
            new_coef = termArray[i].coef * x.termArray[j].coef;
            new_exp = termArray[i].exp + x.termArray[j].exp;
            new_index = result.get_coef(new_exp);
            
            if(new_coef != 0 && new_index == NOT_FOUND){
                result.NewTerm(new_coef, new_exp);
            }

            else{
                result.termArray[new_index].coef += new_coef;
            }

            sort(result.termArray, result.termArray + result.terms, cmp);
        }
    }
}

bool Polynomial::diff(Polynomial& x){
    int a = 0, b = 0;
    bool result = false;
    for(; a < terms || b < x.terms; ){
        while(termArray[a].coef == 0)a++;    //find the first no zero term
        while(x.termArray[b].coef == 0)b++;  //find the first no zero term
        if(termArray[a].exp == x.termArray[b].exp && termArray[a].coef == x.termArray[b].coef){
            a++;
            b++;
            continue;
        }
        else result = true;
        break;
    }
    cout << description << " and " << x.description << " is different? ";

    return result;
}

void Polynomial::printPolynomial(){

    cout << description << " : ";
    for(int i = 0; i < terms; i++){
        if(termArray[i].coef != 0){
            cout << termArray[i].coef << "x^"<< termArray[i].exp;
            if(i != terms - 1) cout << " + ";
        }
    }
    cout << endl;
}