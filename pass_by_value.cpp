#include <iostream>

using namespace std;

//pass in the copy of the data
//it won't change the data itself
void getnum(int num){
    cout << &num << endl;
    num++;
}

int main(){
    int num = 5;
    cout << num << endl;    //5
    cout << &num << endl;   //0x7fff31791e8c

    getnum(num);            //0x7fff31791e6c
    cout << num << endl;    //5
}