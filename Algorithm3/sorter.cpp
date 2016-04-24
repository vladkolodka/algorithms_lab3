#include "sorter.h"

float Sorter::InsertionSort(List<int> &list){
    Stack<int> stack(list.size());

    clock_t start_time = clock();
    for(int i = 0; i < 5000000; i++){}

    for(auto i = list.begin(); i.end(); ++i) stack.push(*i);

    list.clear();
    while (!stack.isEmpty()) {
        list.addOrdered(stack.top());
        stack.pop();
    }

    return static_cast<float>(clock() - start_time) / 100.0;
}
float Sorter::BitwiseSort(Queue<int>& queue){
    int length = 0;
    const int range = 10;

    Queue<int> QueueArray[range];

    clock_t start_time = clock();
    for(int i = 0; i < 5000000; i++){}

    //  find max length
    for(auto i = queue.begin(); i.end(); ++i){
        int temp_length = 0;
        int value = *i;
        while (value) {
            temp_length++;
            value = value / 10;
        }
        if(temp_length > length) length = temp_length;
    }

    // sorting
    for(int i = 0; i < length; i++){
        for(auto j = queue.begin(); j.end(); ++j){
            int queue_index = (*j % static_cast<int>(pow(range, i + 1))) / static_cast<int>(pow(range, i));

            QueueArray[queue_index].push_back(*j);
        }

        queue.clear();

        for(int j = 0; j < range; j++){
            for(auto iter = QueueArray[j].begin(); iter.end(); ++iter){
                queue.push_back(*iter);
            }
            QueueArray[j].clear();
        }
    }
    return static_cast<float>(clock() - start_time) / 100.0;
}
void Sorter::RandomFill(List<int> &list, int size, int max_value){
    srand(time(NULL));
    for(int i = 0; i < size; i++) list.add(rand() % max_value);
}
void Sorter::RandomFill(Queue<int> &queue, int size, int max_value){
    srand(time(NULL));
    for(int i = 0; i < size; i++) queue.push_back(rand() % max_value);
}

std::string Sorter::ListLog(List<int> &list){
    std::string str = "> List:\n=========================\n";
    for(auto i = list.begin(); i.end(); ++i) str += std::to_string(*i) + ", ";

    str = str.substr(0, str.size() - 2);

    str += "\n=========================\n";
    return str;
}
std::string Sorter::QueueLog(Queue<int> &queue){
    std::string str = "> Queue:\n=========================\n";
    for(auto i = queue.begin(); i.end(); ++i) str += std::to_string(*i) + " <- ";

    str = str.substr(0, str.size() - 3);

    str += "\n=========================\n";
    return str;
}