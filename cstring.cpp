#include <iostream>
#include <cstring>

using namespace std;

int main(){

    //strlen
    char msg1[] = {"The sky is blue."};
    const char *msg2 = {"The sky is blue."};
    cout << strlen(msg1) << endl;   //16 (without '\0')
    cout << strlen(msg2) << endl;   //16 (without '\0')
    cout << sizeof(msg1) << endl;   //17 (with '\0')
    cout << sizeof(msg2) << endl;   //8 sizeof(pointer) is always 8 bytes

    //strcmp(s1, s2)
    //return 0 if two string equal
    //return >0 if the first ASCII value of diffrent character in s1 is greater than s2
    const char *s1 = "Alabama";
    const char *s2 = "Blabama";
    cout << strcmp(s1, s2) << endl;     //<0

    s1 = "Alabamc";
    s2 = "Alabama";
    cout << strcmp(s1, s2) << endl;     //>0


    s1 = "Alabama";
    s1 = "Alabama";
    cout << strcmp(s1, s2) << endl;     //0

    //strchr
    //find the first occurrence
    const char *str = "Testing String, I am fine, thank you!";
    char target = 'f';
    const char *result = str;
    result = strchr(result, target);
    cout << result << endl;     //fine, thank you!


    //strcat
    char dest[] = "Hello";
    char src[] = "World";
    strcat(dest, src);
    cout << dest << endl;

	return 0;
}