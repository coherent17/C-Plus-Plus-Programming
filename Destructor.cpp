#include <iostream>
#include <string>
using namespace std;

class Dog{
    private:
        string name;
        string breed;
        int *age_ptr = nullptr;

    public:
        //constructor:
        Dog();
        Dog(string name_param, string breed_param, int age_param);
        
        //destructor: have no parameter to destructor
        ~Dog();

        //other method:
        void printInfo();
        
};

//constructor
Dog::Dog(){
    name = "None";
    breed = "None";
    age_ptr = new int;      //memory allocate on the heap
    *age_ptr = 0;
}

Dog::Dog(string name_param, string breed_param, int age_param){
    name = name_param;
    breed = breed_param;
    age_ptr = new int;      //memory allocate on the heap
    *age_ptr = age_param;
}

//destructor
Dog::~Dog(){
    delete age_ptr;     //release memory in destructor
    cout << "Dog destructor called for : " << name << endl;
}


//other method:
void Dog::printInfo(){
    cout << name << endl;
    cout << breed << endl;
    cout << *age_ptr << endl;
}





//the local copy will be destroied after the function call
void testFunction1(){
    Dog blueDog("BlueDog", "DogDog", 3);
    blueDog.printInfo();    //after this line, will excute the destructor
}

void testFunction2(){
    Dog *dogptr = new Dog("BlueDog", "DogDog", 3);  //create memory on the heap
    delete dogptr;  //after this line, will excute the destructor
}


/* 
When are destructor called?
*   The destructors are called in weird places that may not be obvious
    *   When an object is passed by value to a function
    *   When a local object is returned from a function
*   Other obvious :
    *   When a local stack object goes out of scope (dies)
    *   When a heap object is released with delete
*/

int main(){
    Dog d1("Harry", "Shepherd", 2);
    d1.printInfo();

    testFunction1();
    testFunction2();

    cout << "Done" << endl;
    return 0;   //after this line, will excute the destructor
}