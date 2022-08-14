#ifndef _STACK_H_
#define _STACK_H_

#include <iostream>

using namespace std;


template <class T>
class Stack{
    
    private:
        T *stack;
        int top;
        int capacity;

    public:
        Stack(int stackCapacity = 10);
        ~Stack();
        bool isEmpty()const;
        T& Top()const;
        void push(const T& element);
        void pop();

    template <class U>
    friend ostream& operator<<(ostream& out, const Stack<U>& s);
};

template <class T>
Stack<T>::Stack(int stackCapacity){
    capacity = stackCapacity;
    stack = new T[capacity];
    top = -1;
}


template <class T>
Stack<T>::~Stack(){
    delete[] stack;
}

template <class T>
bool Stack<T>::isEmpty()const{
    return top == -1;
}

template <class T>
T& Stack<T>::Top()const{
    if(isEmpty()){
        abort();
    }
    return stack[top];
}

template <class T>
void Stack<T>::push(const T& element){
    if(top == capacity - 1){
        T *newStack = new T[2 * capacity];
        for(int i = 0; i <= top; i++){
            newStack[i] = stack[i];
        }
        capacity *= 2;
        delete[] stack;
        stack = newStack;
    }
    stack[++top] = element;
}

template <class T>
void Stack<T>::pop(){
    if(isEmpty()){
        cerr << "Stack empty!" << endl;
    }
    top--;
}

template <class T>
ostream& operator<<(ostream& out, const Stack<T>& s){
    cout << "top = " << s.top << ", capccity = " << s.capacity << endl;
    for(int i = s.top; i >= 0; i--){
        out << s.stack[i] <<" ";
    }
    out << endl;
    return out;
}

#endif