#include <iostream>

using namespace std;

int max(int a, int b){
    return a > b ? a : b;
}

/*
can't overload the return type, ex:
double max(int a, int b){
    return a > b ? a : b;
}

therefore, we can change 
1. order of parameter
2. number of parameter
3. types of parameter
*/

double max(double a, double b){
    return a > b ? a : b;
}

int main(){
    //compiler will choose the best function to due to the input parameter
    cout << max(1,3) << endl;
    cout << max(1.3, 1.5) << endl;

    return 0;
}