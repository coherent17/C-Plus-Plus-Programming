#include "linkedlist.h"
#include <iostream>

using namespace std;

//constructor of list Node
Node::Node(int value){
    this->value = value;
    this->next = nullptr;
}

//destructor: delete all ListNode memory
LinkedList::~LinkedList(){
    while(head){
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void LinkedList::printList(){
    cout << endl;
    Node *temp = head;
    cout << "Head: " << head->value << "   " << "Tail: " << tail->value << endl;
    while(temp){
        cout << temp->value;
        if(temp != tail){
            cout<<" -> ";
        }
        else{
           cout << endl; 
        }
        temp = temp->next;
    } 
    cout << endl;  
}

void LinkedList::insert_at_head(int value){

    Node *newNode = new Node(value);
    if(tail == nullptr){
        tail = newNode;
    }
    newNode->next = head;
    head = newNode;
}

void LinkedList::insert_at_tail(int value){

    Node *newNode = new Node(value);
    if(head == nullptr){
        head = newNode;
    }
    tail->next = newNode;
    tail = newNode;
}

//delete all node value that is equal to value
void LinkedList::delete_node(int value){

    //if the linkedlist is empty
    if(head == nullptr) return;

    //when head value equals to target value
    while(head->value == value){
        Node *node_to_delete = head;
        head = head->next;
        delete node_to_delete;
    }

    Node *temp = head;
    while(temp->next != nullptr){
        if((temp->next)->value == value){


            if(temp->next == tail){
                tail = temp; 
                Node *node_to_delete = temp->next;
                temp->next = (temp->next)->next;
                delete node_to_delete; 
                break;  
            }
            Node *node_to_delete = temp->next;
            temp->next = (temp->next)->next;
            delete node_to_delete;
        }
        temp = temp->next;
    }
}

bool LinkedList::inList(int value){
    Node *temp = head;
    while(temp != nullptr){
        if(temp->value == value){
            return true;
        }
        temp = temp->next;
    }
    return false;
}