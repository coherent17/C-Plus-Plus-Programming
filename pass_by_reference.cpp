#include <iostream>

using namespace std;

//pass in the reference of the data
//and it can modified the data outside
void getnum(int &num){
    cout << &num << endl;
    num++;
}

int main(){
    int num = 5;
    cout << num << endl;    //5
    cout << &num << endl;   //0x7fff7977df4c

    getnum(num);            //0x7fff7977df4c
    cout << num << endl;    //6
}