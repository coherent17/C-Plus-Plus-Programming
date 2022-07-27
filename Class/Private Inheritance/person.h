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
        Person() = default;
        Person(string name, int age, int weight);

        //getter
        string get_name(){
            return name;
        }
        int get_age(){
            return age;
        }
        int get_weight(){
            return weight;
        }


    friend ostream& operator<<(ostream& out, Person& person);
};

#endif