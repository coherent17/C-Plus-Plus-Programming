#ifndef ELLIPSE_H
#define ELLIPSE_H


#include "shape.h"
#include <string>


using namespace std;

class Ellipse : public Shape{
    public:
        Ellipse();
        Ellipse(double x_radius, double y_radius, string description);
        ~Ellipse();
        
        static int count;

        virtual int get_count()const override{
            return count;
        }

        
    private : 
        double m_x_radius;
        double m_y_radius;
};

#endif