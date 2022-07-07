#include <iostream>
#define SIZE 10
using namespace std;

//using dynamic array to allocate memory on the heap instead of stack

void printArray(int *array){
    for(int i = 0; i < SIZE; i++){
        cout << array[i] << " "; 
    }
    cout << endl;

    //can't use range base for loop to print it out
    // for(int val : array){
    //     cout << val << " ";
    // }
    // cout << endl;
}

int main(){
    int *arrptr1 = new int[SIZE];   //array contains garbage data
    printArray(arrptr1);    //using valgrind: contains " Conditional jump or move depends on uninitialised value(s)"
    delete[] arrptr1;
    arrptr1 = nullptr;

    //using nothrow to exclude exception
    int *arrptr2 = new(nothrow) int[SIZE]{};  //array init to all 0
    printArray(arrptr2);
    delete[] arrptr2;
    arrptr2 = nullptr;

    int *arrptr3 = new int[SIZE]{1,2,3,4,5}; //first 5 elements with rest 0
    printArray(arrptr3);
    delete[] arrptr3;
    arrptr3 = nullptr;

    return 0;
}