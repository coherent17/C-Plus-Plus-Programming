#include "person.h"
#include "player.h"
#include "nurse.h"
#include "engineer.h"
#include <iostream>

using namespace std;

int main(){

    Player p1;
    //p1.name = "Test";     //OK
    //p1.age = 50;          //protected compiler error
    //p1.weight = 100;      //private compiler erorr
    p1.testPublic();
    cout << p1 <<endl;
    

    Nurse n1;
    //n1.name = "Test";     //protected compiler error
    //n1.age = 50;          //protected compiler error
    //n1.weight = 100;      //private compiler erorr
    n1.testProtected();
    cout << n1 << endl;

    Engineer e1;
    //e1.name = "Test";     //private compiler error
    //e1.age = 50;          //private compiler error
    //e1.weight = 100;      //private compiler erorr
    e1.testPrivate();
    cout << e1 << endl;
    return 0;
}
