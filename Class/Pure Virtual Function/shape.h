#ifndef SHAPE_H
#define SHAPE_H

#include <string>
using namespace std;

class Shape{
    protected:
        Shape() = default;
        Shape(string description);
    public :    
        
        virtual ~Shape() = default; // If destructor is not public, you won't be able to delete base_ptrs. SHOW THIS TO STUDENTS
        //Pure virtual functions -> the class become abstract class, can't create object in this class
        virtual double perimeter() const = 0;
        virtual double surface() const = 0;
    private : 
        std::string m_description;
};

#endif // SHAPE_H