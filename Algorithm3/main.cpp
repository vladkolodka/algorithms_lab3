#include <iostream>

#include "sorter.h"
#include "list.h"
#include "queue.h"

using namespace std;

int main(){
    List<int> list;
    Queue<int> queue;

    // fill with random values
    Sorter::RandomFill(list, 54, 99);
    Sorter::RandomFill(queue, 54, 99);

    // sorting
    float sort1 = Sorter::InsertionSort(list);
    float sort2 = Sorter::BitwiseSort(queue);

    // show elements
    cout << Sorter::ListLog(list);
    cout << "Time: " << sort1 << "ms\n\n";
    cout << Sorter::QueueLog(queue);
    cout << "Time: " << sort2 << "ms\n\n";

    cout.put('\n');
    return 0;
}