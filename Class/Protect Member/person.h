#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>

using namespace std;

class Person{
    //using protect so that the derive class can modify and access to the variable
    //but still not accessible in main or outside the inheritance class
    protected:
        int height = 0;
        int weight = 0;
        string name = "Mysterious";

    public:
        //constructor
       Person() = default;
       Person(int height_param, int weight_param, string name_param);

        //getter
       int get_height();
       int get_weight();
       string get_name();

       //setter
       void set_height(int height_param);
       void set_weight(int weight_param);
       void set_name(string name_param);

    //overloading << to cout the person class
    friend ostream& operator<<(ostream& out, const Person &person);
};

#endif