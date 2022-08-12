#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

class Node{
    //let LinkedList class can access the private member
    friend class LinkedList;

    private:
        int value;
        Node *next;

    public:
        
        //constructor
        Node(int value);

};

class LinkedList{
    
    private:
        Node *head = nullptr;
        Node *tail = nullptr;

    
    public:
        LinkedList() = default;
        ~LinkedList();

        //linkedlist operation
        void printList();
        void insert_at_head(int value);
        void insert_at_tail(int value);
        void delete_node(int value);
        bool inList(int value);
        
};

#endif