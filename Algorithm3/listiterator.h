#pragma once

template <class ElementType, class T> class ListIterator{
    ElementType *pointer;
    int index = 0;
public:
    ListIterator(ElementType* element) : pointer(element){}
    ListIterator<ElementType, T>& clone(){
        ListIterator<ElementType, T> *newIter= new ListIterator<ElementType, T>(pointer);
        newIter->index = index;

        return *newIter;
    }

    void operator ++(){pointer = pointer->next; index++;}
    void operator --(){pointer = pointer->prev; --index;}
    T& operator *(){return pointer->value;}
    bool operator !=(ListIterator<ElementType, T> &iter){return pointer != iter.pointer;}
    int operator()(){ return index; }

    T& prev(){ return pointer->prev->value; }
    T& next(){ return pointer->next->value; }
    bool notFirst(){ return pointer->prev; }
    bool end(){ return pointer != 0; }

};