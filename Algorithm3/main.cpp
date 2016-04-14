#include <iostream>
#include <time.h>

#include "stack.h"
#include "listiterator.h"
#include "list.h"

using namespace std;

int main(){
    srand(time(NULL));

    const int size = 54;
    List<int> list;

    // fill list with random values
    for(int i = 0; i < size; i++) list << rand() % 99;

    // show list elements
    for(auto i = list.begin(); i.end(); ++i) cout << i() << " ";

    putchar('\n');
    return 0;
}