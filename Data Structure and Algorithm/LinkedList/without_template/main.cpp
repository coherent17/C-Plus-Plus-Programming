#include "linkedlist.h"
#include <iostream>


using namespace std;

int main(){
    LinkedList ll;
    ll.insert_at_head(5);
    ll.insert_at_head(7);
    ll.insert_at_head(2);
    ll.insert_at_head(7);
    ll.insert_at_tail(3);
    ll.insert_at_tail(4);
    ll.insert_at_tail(7);

    ll.printList();
    ll.delete_node(7);

    cout << boolalpha << ll.inList(1) << endl;
    cout << boolalpha << ll.inList(5) << endl;

    return 0;
}