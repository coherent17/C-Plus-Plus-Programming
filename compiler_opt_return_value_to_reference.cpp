#include <iostream>
#include <string>

using namespace std;

string addString(string s1, string s2){
    string result = s1 + s2;
    
    //the address of the local variable in this function
    cout << &result << endl;    //0x7fff320a8b00


    return result;
}

//compiler optimize the code to avoid copy the whole data

int main(){

    string s1 = "Hello";
    string s2 = "World";
    string result = addString(s1, s2);

    //the address of the local variable in mainb
    cout << &result << endl;    //0x7fff320a8b00
    cout << result << endl;

    return 0;
}