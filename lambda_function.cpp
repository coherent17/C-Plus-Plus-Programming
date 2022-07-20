#include <iostream>

using namespace std;

int main(){

/*
Lambda function signature:
[capture list] (parameters) -> return type{
    function body
};
*/

auto func = [](){
    cout << "Hello World" << endl;
};

func();


//call lambda function after definition
[](){
    cout << "Immediate call function" << endl;
}();

//lambda function with parameter
[](int a, int b){
    cout << a + b << endl;
}(1,2);

//return something from lambda function and explicitly return type
auto result = [](double a, double b)->double{
    return a + b;
}(1.2,2.3);
cout << result << endl;


//capture list to access the data not in parameter:

//*     capture by value: make a copy of a and b inside the function
int a = 2;
int b = 3;

cout << &a << endl;     //0x7ffe22f5bbf0
cout << &b << endl;     //0x7ffe22f5bbec


[a, b](){
    cout << &a << endl; //0x7ffe22f5bbe4
    cout << &b << endl; //0x7ffe22f5bbe8
}();


//*     capture by reference: working on the original value outside the scope
int c = 5;
cout << &c << endl;     //0x7fff01f11c78
[&c](){
    cout << &c << endl; //0x7fff01f11c78
}();

//capture all content outside the lambda by value
[=](){
    cout << &a << endl; //0x7ffcfd0cecbc
    cout << &b << endl; //0x7ffcfd0ceca8
    cout << &c << endl; //0x7ffcfd0ceca8
}();

//capture all content outside the lambda by reference
[&](){
    cout << &a << endl; //0x7ffc55c02228
    cout << &b << endl; //0x7ffc55c02224
    cout << &c << endl; //0x7ffc55c02220
}();

return 0;
}