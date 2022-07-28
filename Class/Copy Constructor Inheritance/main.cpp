#include "person.h"
#include "engineer.h"
#include "civilengineer.h"
#include <iostream>
#include <string>

using namespace std;

int main(){

    Engineer e1("RedBull", 79, 80, 9);
    cout << e1;
    cout << "------------------------------------" << endl;

    Engineer e2(e1);
    cout << e2;
    cout << "------------------------------------" << endl;

    CivilEngineer e3("Redcat", 45, 9, 89, "Good");
    cout << e3;

    cout << "------------------------------------" << endl;

    CivilEngineer e4(e3);
    cout << e4;


    return 0;
}
