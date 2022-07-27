#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person{
    private:
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

    //let the outer function can access the private member
    friend void printPersonInfo(Person& person);
};

#endif