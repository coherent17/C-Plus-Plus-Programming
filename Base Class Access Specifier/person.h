#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person{
    //member variable:
    public:
        string name = "None";
    protected:
        int age = 0;
    private:
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