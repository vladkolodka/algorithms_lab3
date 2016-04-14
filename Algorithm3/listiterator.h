#pragma once
#include <list.h>

template <class ElementType, class T> class ListIterator{
ElementType *pointer;
int index = 0;
public:
    ListIterator(ElementType* element) : pointer(element){}
    T operator *() const;
    void operator ++(){pointer = pointer->next; index++;}
    T& operator *(){return pointer->value;}
    bool operator!=(ListIterator<ElementType, T> &iter){return pointer != iter.pointer;}
    bool end(){return pointer != 0;}
    int operator()(){return index;}
};