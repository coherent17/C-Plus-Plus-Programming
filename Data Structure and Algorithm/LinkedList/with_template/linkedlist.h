#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include <iostream>
using namespace std;

template<class T>
struct Node{
    T value;
    Node<T> *next;
};

template <class T>
class LinkedList{
    
    private:
        Node<T> *head = nullptr;
        Node<T> *tail = nullptr;

    
    public:
        LinkedList();
        ~LinkedList();
        void printList();
        void insert_at_head(T value);
        void insert_at_tail(T value);
        void delete_node(T value);
        bool inList(T value);
};


//constructor
template <class T>
LinkedList<T>::LinkedList(){
    head = nullptr;
    tail = nullptr;
}

//destructor
template <class T>
LinkedList<T>::~LinkedList(){
    while(head){
        Node<T> *temp = head;
        head = head->next;
        delete temp;
    }
}

template <class T>
void LinkedList<T>::printList(){
    cout << endl;
    Node<T> *temp = head;
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

template <class T>
void LinkedList<T>::insert_at_head(T value){

    Node<T> *newNode = new Node<T>();
    newNode->value = value;
    newNode->next = nullptr;


    if(tail == nullptr){
        tail = newNode;
    }
    newNode->next = head;
    head = newNode;
}

template <class T>
void LinkedList<T>::insert_at_tail(T value){

    Node<T> *newNode = new Node<T>();
    newNode->value = value;
    newNode->next = nullptr;

    if(head == nullptr){
        head = newNode;
    }
    tail->next = newNode;
    tail = newNode;
}

//delete all node value that is equal to value
template <class T>
void LinkedList<T>::delete_node(T value){

    //if the linkedlist is empty
    if(head == nullptr) return;

    //when head value equals to target value
    while(head->value == value){
        Node<T> *node_to_delete = head;
        head = head->next;
        delete node_to_delete;
    }

    Node<T> *temp = head;
    while(temp->next != nullptr){
        if((temp->next)->value == value){


            if(temp->next == tail){
                tail = temp; 
                Node<T> *node_to_delete = temp->next;
                temp->next = (temp->next)->next;
                delete node_to_delete; 
                break;  
            }
            Node<T> *node_to_delete = temp->next;
            temp->next = (temp->next)->next;
            delete node_to_delete;
        }
        temp = temp->next;
    }
}

template <class T>
bool LinkedList<T>::inList(T value){
    Node<T> *temp = head;
    while(temp != nullptr){
        if(temp->value == value){
            return true;
        }
        temp = temp->next;
    }
    return false;
}

#endif