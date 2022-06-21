#include <iostream>
#include <string>

int main(){
    std::cout <<"Hello World" << std::endl;
    std::cerr << "Something is wrong!" << std::endl;
    std::clog << "Log Message" << std::endl;

    int age;
    std::string name;
    std::cin >> name >> age;
    std::cout << name << " " << age << std::endl;
    return 0;
}