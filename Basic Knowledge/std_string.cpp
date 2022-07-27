#include <iostream>
#include <string>

using namespace std;

int main(){
    string empty_string;    //empty string
    string planet = "Hello Earth";
    string message = {planet, 5};

    cout << empty_string << endl;       //empty
    cout << planet << endl;             //Hello Earth
    cout << message << endl;            // Earth

    return 0;
}