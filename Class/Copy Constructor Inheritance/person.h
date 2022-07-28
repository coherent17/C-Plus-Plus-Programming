#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person{
    //member variable:
    public:     //private to derive class
        string name = "None";
    protected:  //private to derive class
        int age = 0;
    private:    //private to base class
        int weight = 0;
    
    public:
        //constructor
        Person();
        Person(string name, int age, int weight);

        //copy constructor
        Person(const Person& person);

        //getter
        string get_name()const{
            return name;
        }
        int get_age()const{
            return age;
        }
        int get_weight()const{
            return weight;
        }


    friend ostream& operator<<(ostream& out, const Person& person);
};

#endif