#pragma once
#include "list.h"

template <class T> class List;

template <class T> class Queue : private List<T>{
public:
    Queue() {}
    bool empty();

    void push_back(T);
    void pop_front();
    T front();
    T back();

    using List<T>::list;

    using List<T>::clear;
    using List<T>::begin;
    using List<T>::end;
    using List<T>::size;
};
template <class T> bool Queue<T>::empty(){
    return list;
}
template <class T> void Queue<T>::push_back(T value){
    List<T>::add(value);
}
template <class T> void Queue<T>::pop_front(){
    if(!list) return;

    if(list->next != 0) list = list->next;
    else list = 0;
}
template <class T> T Queue<T>::front(){
    if(list) return list->value;
    return 0;
}
template <class T> T Queue<T>::back(){
    if(list) return List<T>::lastElement()->value;
    return 0;
}