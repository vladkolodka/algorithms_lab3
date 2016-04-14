#pragma once
#include <list.h>

template <class ElementType, class T> class ListIterator{
ElementType *pointer;

public:
    ListIterator(ElementType* element) : pointer(element){}
    T operator *() const;
    void operator ++(){pointer = pointer->next;}
    T operator *(){return pointer->value;}
    bool operator!=(ListIterator<ElementType, T> &iter){return pointer != iter.pointer;}
    bool end(){return pointer != 0;}
};