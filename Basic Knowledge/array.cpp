#include <iostream>

int main(){
    int sum = 0;
    int a[] = {1,2,3,4,5};

    std::cout << sizeof(a) << std::endl;                //20 bytes 
    std::cout << sizeof(a[0]) << std::endl;             //4 bytes per int
    std::cout << sizeof(a) / sizeof(a[0]) << std::endl; //5 integers in array

    //omit the size of array
    for(auto val : a){
        std::cout << val << std::endl;
    }

    for(int element : a){
        sum += element;
    }
    std::cout << sum << std::endl;

    char message[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    for(auto c : message){
        std::cout << c << std::endl;
    }

    //can directly print out character array if '\0' is at end of array
    std::cout << message << std::endl;


    //can use string to init the char array with '\0' terminate
    char msg[] = {"Hello World"};
    std::cout << msg << std::endl;

    return 0;
}