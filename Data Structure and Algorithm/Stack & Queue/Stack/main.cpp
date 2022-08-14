#include "Stack.hpp"
#include <iostream>

using namespace std;


int main(){
    
    Stack<int> s1(3);
    s1.push(1);
    s1.push(2);
    s1.push(3);
    cout << s1 << endl;

    s1.push(4);
    s1.push(5);
    s1.push(6);
    cout << s1 << endl;

    s1.pop();
    cout << s1 << endl;



    return 0;
}