#include "animal.h"
#include "feline.h"
#include <string>

using namespace std;

Feline::Feline(string fur_style, string description) : Animal(description){
    this->m_fur_style = fur_style;
}

Feline::~Feline(){
    cout << "Feline destructor called" << endl;
}