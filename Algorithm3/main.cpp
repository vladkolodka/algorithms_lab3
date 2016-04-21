#include <iostream>

#include "sorter.h"
#include "list.h"

using namespace std;

int main(){
    List<int> list;

    // fill list with random values
    Sorter::RandomFill(list, 54);

    // insertion sort
    Sorter::InsertionSort(list);

    // show list elements
    cout << Sorter::ListLog(list);

    cout.put('\n');
    return 0;
}