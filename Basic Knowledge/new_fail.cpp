#include <iostream>

using namespace std;

int main(){

/*
    terminate called after throwing an instance of 'std::bad_alloc'
    what():  std::bad_alloc
    Abort (core dumped)
*/
    int *a1 = new int[1000000000000000000];

    for(int i = 0; i < 1000000000; i++){
        int *a2 = new int[10000000];
    }

    //check for failed memory allocation
    for(int i = 0; i < 1000000000000000; i++){
        try{
            int *a3 = new int[10000000];
        }
        catch(exception& ex){
            cout << "Cought Exception : " << ex.what() << endl;
            break;
        }
    }

    //using nothrow, if fail return nullptr
    for(int i = 0; i < 100000000000000000; i++){
        int *a4 = new(nothrow) int[1000000000];
        if(a4 == nullptr){
            cout << "Memory Allocation Failed" << endl;
            break;
        }
        else{
            cout << "Memory Allocation Succeeded" << endl;
        }
    }

    return 0;
}