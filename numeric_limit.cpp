#include <iostream>
#include <limits>

using namespace std;

int main(){
    cout << "The range for short is from" << numeric_limits<short>::min() << "to" << numeric_limits<short>::max() << endl;
    cout << "The range for unsigned short is from" << numeric_limits<unsigned short>::min() << "to" << numeric_limits<unsigned short>::max() << endl;
    cout << "The range for int is from" << numeric_limits<int>::min() << "to" << numeric_limits<int>::max() << endl;
    cout << "The range for unsigned int is from" << numeric_limits<unsigned int>::min() << "to" << numeric_limits<unsigned int>::max() << endl;
   cout << "The range for long is from" << numeric_limits<long>::min() << "to" << numeric_limits<long>::max() << endl;
    return 0;
}