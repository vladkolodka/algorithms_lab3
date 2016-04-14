#pragma once
#include "listiterator.h"
#define NO_VALUE -1;

template <class ElementType, class T> class ListIterator;

template <class T> class List{
    struct ListElement{
        T value;
        ListElement* next;
    };

    typedef ListIterator<ListElement, T> iterator;

    // first element;
    ListElement* list = 0;

    ListElement* createElement(T value);
    ListElement* lastElement();

    // recursive method for internal use
    void clear(ListElement* elem);
public:
    List();
    List(const List<T>&);
    ~List();

    void add(T element);
    T operator[](int i);

    // remove element by index
    bool remove(int index);
    bool set(int index, T value);

    // delete all elements
    void clear();
    T last();

    // get iterators
    iterator begin();
    iterator end();

    // add(T elem) alternative
    List<T>& operator <<(T);
};

template <class T> List<T>::List(){}
template <class T> List<T>::~List(){
    if(list) clear();
}

template <class T> void List<T>::add(T elementValue){
    if(list) lastElement()->next = createElement(elementValue);
    else list = createElement(elementValue);
}
template <class T> T List<T>::operator[](int index){
    if(list){
        ListElement* pointer = list;
        bool elementExists = false;

        for(int i = 0; i <= index && list; i++){
            if(i == index) {
                elementExists = true;
                break;
            }
            pointer = pointer->next;
        }

        return elementExists ? pointer->value : NO_VALUE;
    } else return NO_VALUE;
}
template <class T> typename List<T>::ListElement* List<T>::lastElement(){
    // get last element pointer
    if(list){
        ListElement* p = list;

        while (p->next) p = p->next;

        return p;
    }
    return 0;
}
template <class T> typename List<T>::ListElement* List<T>::createElement(T value){
    // create new element
    ListElement* p = new ListElement;
    p->value = value;
    p->next = 0;
    return p;
}
template <class T> T List<T>::last(){
    ListElement* p = lastElement();
    return (p) ? p->value : -1;
}
template <class T> void List<T>::clear(){
    if(!list) return;
    clear(list);
    list = 0;
}
template <class T> void List<T>::clear(ListElement* elem){
    // internal usage only
    if(elem->next) clear(elem->next);
    delete elem;
}
template <class T> bool List<T>::remove(int index){
    // remove element by index
    if(!list) return false;

    ListElement* p = list;
    int i = 0;

    while (p->next) {
        if(i + 1 == index){
            delete p->next;
            p->next = p->next->next;

            return true;
        }

        p = p->next;
        i++;
    }
    return false;
}
template <class T> bool List<T>::set(int index, T value){
    if(!list) return false;

    ListElement *p = list;
    int i = 0;

    while (p) {
        if(i == index){
            p->value = value;
            return true;
        }

        p = p->next;
        i++;
    }
    return false;
}
template <class T> List<T>& List<T>::operator <<(T arg){
    add(arg);
    return *this;
}
template <class T> typename List<T>::iterator List<T>::begin(){
    return iterator(list);
}
template <class T> typename List<T>::iterator List<T>::end(){
    return iterator(lastElement());
}