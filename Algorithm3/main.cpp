#include <iostream>

#include "stack.h"
#include <listiterator.h>
#include <list.h>

using namespace std;

int main(){
    List<int> list;

    list << 1 << 2 << 3 << 4 << 5 << 6;
    for(auto i = list.begin(); i.end(); ++i) cout << *i << " ";

    putchar('\n');
    return 0;
}