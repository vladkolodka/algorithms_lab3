#pragma once

template <class ElementType, class T> class ListIterator{
    ElementType *pointer;
public:
    ListIterator(ElementType* element) : pointer(element){}
    ListIterator<ElementType, T>& clone(){
        return new ListIterator<ElementType, T>(pointer);
    }

    void operator ++(){pointer = pointer->next;}
    T& operator *(){return pointer->value;}
    bool operator !=(ListIterator<ElementType, T> &iter){
        return pointer != iter.pointer;
    }

    T& next(){ return pointer->next->value; }
    bool end(){ return pointer != 0; }
};