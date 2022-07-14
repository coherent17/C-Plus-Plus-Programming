#include <iostream>
#include <cctype>

using namespace std;

int main(){

    //check if character is alphanumeric (number or alphabet) a~z||A~Z||0~9
    //return non-zero value if the character is an alphanumeric, 0 otherwise
    cout << isalnum('C') << endl;   //non zero
    cout << isalnum('2') << endl;   //non zero
    cout << isalnum('.') << endl;   //0

    char input = 'U';
    if(isalnum(input)){
        cout << input << " is alphanumeric" << endl;
    }

    else{
        cout << input << " isn't alphanumeric " << endl;
    }

    //check if character is alphabetic
    cout << isalpha('C') << endl;   //non zero
    cout << isalpha('^') << endl;   //0
    cout << isalpha('7') << endl;   //0


    //check if character is blank
    cout << isblank(' ') << endl;   //non zero
    cout << isblank('A') << endl;   //0

    //check if character is lowercase/uppercase
    cout << islower('A') << endl;   //0
    cout << islower('a') << endl;   //non zero

    cout << isupper('A') << endl;   //non zero
    cout << isupper('a') << endl;   //0

    //check if character is digit
    cout << isdigit('3') << endl;   //non zero
    cout << isdigit('A') << endl;   //0

    //turn lowercase/uppercase
    cout << toupper('a') << endl;   //65
    cout << tolower('A') << endl;   //97
    cout << (char)toupper('a') << endl;   //A
    cout << (char)tolower('A') << endl;   //a
}