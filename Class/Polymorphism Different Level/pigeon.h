#ifndef PIGEON_H
#define PIGEON_H

#include "bird.h"
#include <string>

using namespace std;

class Pigeon : public Bird{
    public:
        Pigeon() = default;
        Pigeon(string wing_color, string description);
        ~Pigeon() = default;
        
        virtual void coo() const{
            cout << "Pigeon::coo called for pigeon : " << m_description << endl;
        }

        virtual void breathe()const{
            cout << "Pigeon::breathe called for : " << m_description << endl;
        }

        virtual void fly() const override{
            cout << "Pigeon::fly() called for bird : " << m_description << endl;
        }

};

#endif