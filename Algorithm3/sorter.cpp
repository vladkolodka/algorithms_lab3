#include "sorter.h"

Sorter::Sorter(){

}

void Sorter::InsertionSort(List<int> &list){
    Stack<int> stack(2);

    auto i = list.begin();
    ++i;

    for(; i.end(); ++i)
        for(auto j = i.clone(); j.notFirst() && j.prev() > *j ;--j){
            stack.push(j.prev());
            j.prev() = *j;
            *j = stack.top();
            stack.pop();
        }

}

void Sorter::RandomFill(List<int> &list, int size){
    srand(time(NULL));
    for(int i = 0; i < size; i++) list.add(rand() % 99);
}

std::string Sorter::ListLog(List<int> &list){
    std::string str = "> List:\n=========================\n";
    for(auto i = list.begin(); i.end(); ++i) str += std::to_string(*i) + ", ";

    str = str.substr(0, str.size() - 2);

    str += "\n=========================\n";
    return str;
}