#ifndef CROW_H
#define CROW_H

#include "bird.h"
#include <string>

using namespace std;

class Crow : public Bird{
    public:
        Crow() = default;
        Crow(string wing_color, string description);
        ~Crow() = default;
        
        virtual void cow() const{
            cout << "Crow::cow called fro crow : " << m_description << endl;
        }

        virtual void breathe()const{
            cout << "Crow::breathe called for : " << m_description << endl;
        }

        virtual void fly() const override{
            cout << "Crow::fly() called for bird : " << m_description << endl;
        }

};

#endif