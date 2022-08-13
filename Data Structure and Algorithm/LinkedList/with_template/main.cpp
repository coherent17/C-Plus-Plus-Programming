#include "linkedlist.h"
#include <iostream>
#include <string>

using namespace std;

int main(){
    LinkedList<int> ll1;
    ll1.insert_at_head(5);
    ll1.insert_at_head(7);
    ll1.insert_at_head(2);
    ll1.insert_at_head(7);
    ll1.insert_at_tail(3);
    ll1.insert_at_tail(4);
    ll1.insert_at_tail(7);

    ll1.printList();

    cout << boolalpha << ll1.inList(1) << endl;
    cout << boolalpha << ll1.inList(5) << endl;


    LinkedList<string> ll2;
    ll2.insert_at_head("test");
    ll2.insert_at_head("good");
    ll2.insert_at_head("all");
    ll2.insert_at_head("gsfd");
    ll2.insert_at_tail("fgds");
    ll2.insert_at_tail("gfkdl");
    ll2.insert_at_tail("gfds");

    ll2.printList();

    cout << boolalpha << ll2.inList("gsfd") << endl;
    cout << boolalpha << ll2.inList("fds") << endl;

    return 0;
}