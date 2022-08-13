#ifndef _BAG_H_
#define _BAG_H_

#include <iostream>
#include <limits>
#include <cstdlib>
#include <cstring>
#include <string>
#include <typeinfo>

using namespace std;

template <class T>
class Bag{

    private:
        T *array;
        int capacity;
        int top;


    public:
        //ctor & dtor
        Bag(int bag_capacity = 10);
        ~Bag();

        //Bag::method:
        int size()const;
        bool isEmpty()const;
        T& Element()const;
        void push(const T&);
        void pop();
        
        template <class U>
        friend ostream& operator <<(ostream& out, const Bag<U>& bag);
};

template <class T>
Bag<T>::Bag(int bag_capacity){
    if(bag_capacity < 1) throw "Capacity must be > 0";
    capacity = bag_capacity;
    array = new T[capacity];
    top = -1;
}

template <class T>
Bag<T>::~Bag(){
    delete[] array;
}

template <class T>
int Bag<T>::size()const{
    return top+1;
}

template <class T>
bool Bag<T>::isEmpty()const{
    return top == -1;
}

template <class T>
T& Bag<T>::Element()const{
    if(top == -1){
        abort();
    }
    return array[0];
}

template <class T>
void Bag<T>::push(const T& element){
    if(capacity == top + 1){
        array = (T *)realloc(array, 2 * capacity);
        capacity *= 2;
    }
    array[++top] = element;
}

template <class T>
void Bag<T>::pop(){
    if(isEmpty()){
        abort();
    }
    int delete_index = top / 2;
    
    //memmove usage: memmove(void *dest, void *src, byte_t byte)
    memmove(array + delete_index, array + delete_index + 1, sizeof(T) * (top - delete_index));
    top--;
}

template <class T>
ostream& operator <<(ostream& out, const Bag<T>& bag){
    if(bag.top == -1){
        cout << " I am here" << endl;
        out << "Empty Bag" << endl;
        return out;
    }

    for(int i = 0; i <= bag.top; i++){
        out << bag.array[i] << " ";
    }
    cout << endl;
    return out;
}

#endif