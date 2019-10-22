#include <iostream>
#include "list.h"
#include "Stack.h"
#include "Queue.h"
#include "Deque.h"

int main() {
    Dequeue<int> dequeue;
    dequeue.PushBack(5);
    dequeue.PushBack(3);
    dequeue.PushBack(2);
    std::cout << dequeue.Front();

    return 0;
}