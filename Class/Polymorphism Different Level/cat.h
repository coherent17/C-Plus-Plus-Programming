#ifndef CAT_H
#define CAT_H

#include "feline.h"
#include <string>

using namespace std;

class Cat : public Feline{
    public:
        Cat() = default;
        Cat(string fur_style, string description);
        virtual ~Cat() = default;
        
        virtual void miaw() const{
            cout << "Cat::miaw() called for cat " << m_description << endl;
        }

        virtual void breathe()const{
            cout << "Cat::breathe called for : " << m_description << endl;
        }

        virtual void run() const override{
            cout << "Cat " << m_description << " is running" << endl;
        }

};

#endif