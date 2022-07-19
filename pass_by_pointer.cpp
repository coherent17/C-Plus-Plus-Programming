#include <iostream>

using namespace std;

void getnum(int *num){
    cout << &(*num) << endl;
    (*num)++;
}

int main(){
    int num = 5;
    cout << num << endl;    //5
    cout << &num << endl;   //0x7ffdc31ad22c

    getnum(&num);           //0x7ffdc31ad22c
    cout << num << endl;    //6
}