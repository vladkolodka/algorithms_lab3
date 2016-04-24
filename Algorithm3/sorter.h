#pragma once

#include <time.h>
#include <string>

#include "list.h"
#include "queue.h"
#include "stack.h"

class Sorter{
public:
    static void InsertionSort(List<int>&);
    static int BitwiseSort(Queue<int>&);
    static void RandomFill(List<int>&, int, int);
    static void RandomFill(Queue<int>&, int, int);
    static std::string ListLog(List<int>&);
    static std::string QueueLog(Queue<int>&);
};