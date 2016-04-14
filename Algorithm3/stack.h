#pragma once

template <class T> class Stack{
private:
    int size;
    T *data;
    int position;
public:
    Stack<T>(int);
    ~Stack();
    bool push(T);
    bool pop(void);
    T top(void);
};

#include "stack.h"

template <typename T> Stack<T>::Stack(int size) : size(size), position(-1){
    // create new array for stack
    data = new T[size];
}
template<class T> Stack<T>::~Stack(){
    if(data) delete[] data;
}
template <class T> bool Stack<T>::push(T element){
    if(position + 1 < size) position++;
    else return false;

    data[position] = element;
    return true;
}

template <class T> bool Stack<T>::pop(void){
    if(position != -1) position--;
    else return false;

    return true;
}
template <class T> T Stack<T>::top(void){
    if(position != -1)
    return data[position];
}