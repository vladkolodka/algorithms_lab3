#pragma once

#include <time.h>
#include <string>

#include "list.h"
#include "stack.h"

class Sorter{
public:
    Sorter();

    static void InsertionSort(List<int>&);
    static void RandomFill(List<int>&, int);
    static std::string ListLog(List<int>&);
};