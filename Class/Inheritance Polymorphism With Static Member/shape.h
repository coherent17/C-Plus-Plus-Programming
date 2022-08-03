#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

using namespace std;

class Shape{

    protected:
        string description;


    public:
        Shape();
        Shape(string description);
        ~Shape();
        static int count;

        virtual int get_count()const{
            return count;
        }
};

#endif