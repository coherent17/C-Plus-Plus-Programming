#include "person.h"
#include "engineer.h"
#include "civilengineer.h"
#include <iostream>
#include <string>

using namespace std;

int main(){

    Person p1("BlueDog", 65, 70);
    cout << p1 << endl;

    Engineer e1("RedBull", 79, 80, 9);
    cout << e1 << endl;

    CivilEngineer ce1("YellowCat", 100, 98, 32, "Good");
    cout << ce1 << endl;

    return 0;
}
