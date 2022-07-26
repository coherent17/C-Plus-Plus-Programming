//class method contains a hidden pointer "this" contains the address of the current object
#include <iostream>
#include <string>

using namespace std;

class Dog{
    private:
        string name;
        string breed;
        int *age_ptr = nullptr;

    public:
        //constructor
        Dog();
        Dog(string name_param, string breed_param, int age);

        //destructor
        ~Dog();

        //setter for chained call using pointer
        Dog *set_name_ptr(string name);
        Dog *set_breed_ptr(string breed);
        Dog *set_age_ptr(int age);

        //setter for chained call using pointer
        Dog &set_name_ref(string name);
        Dog &set_breed_ref(string breed);
        Dog &set_age_ref(int age);

        //other methods;
        void printInfo();
};

//constructor
Dog::Dog(){
    name = "None";
    breed = "None";
    age_ptr = new int;
    *age_ptr = 0;
    cout << "Construct Dog : " << name << " @ " << this << endl;
}

Dog::Dog(string name_param, string breed_param, int age){
    name = name_param;
    breed = breed_param;
    age_ptr = new int;
    *age_ptr = age;
    cout << "Construct Dog : " << name << " @ " << this << endl;
}

//destructor
Dog::~Dog(){
    delete age_ptr;
    cout << "Destruct Dog : " << name << " @ " << this << endl;
}


//setter for chained call using pointer
Dog *Dog::set_name_ptr(string name){
    //name = name !error!
    this->name = name;
    return this;    //return the pointer to this object for chained use
}

Dog *Dog::set_breed_ptr(string breed){
    this->breed = breed;
    return this;
}

Dog *Dog::set_age_ptr(int age){
    *(this->age_ptr) = age;
    return this;
}

//setter for chained call using reference
Dog &Dog::set_name_ref(string name){
    this->name = name;
    return *this;   //need to dereference and return
}

Dog &Dog::set_breed_ref(string breed){
    this->breed = breed;
    return *this;
}

Dog &Dog::set_age_ref(int age){
    *(this->age_ptr) = age;
    return *this;
}

//other methods
void Dog::printInfo(){
    cout << "Dog @ " << this << " " << endl;
    cout << name <<" "<< breed << " " << *age_ptr << endl;
}

int main(){

    Dog d1("BlueDog", "Shepherd", 2);
    cout << &d1 << endl;    //same address in "this" pointer
    d1.printInfo();

    //chain call using pointer
    d1.set_name_ptr("YellowDog")->set_breed_ptr("WireFox")->set_age_ptr(5);
    d1.printInfo();

    //chain call using reference
    d1.set_name_ref("RedBull").set_breed_ref("Mitsu").set_age_ptr(9);
    d1.printInfo();

    return 0;
}