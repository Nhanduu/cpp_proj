#pragma once

#include "Queue.h"
#include "Stack.h"

template<typename T>
class Dequeue : public Queue<T>, public Stack<T>{
public:
    Dequeue() {
       queue_= Queue<T>();
       stack_ = Stack<T>();
    }

    void PushBack(const T& item) {
        stack_.Push(item);
        if (queue_.head_ == nullptr && stack_.tail_ == nullptr) {
            queue_.head_ = stack_.tail_;
        } else {
            auto it = queue_.head_;
            while (it->next_ != nullptr) {
                it = it->next_;
            }
            it->next_ =  stack_.tail_;
        }
    }

    void PushFront() {

    }


    void PopFront() {

    }


private:
    int size_;
    Queue<T> queue_;
    Stack<T> stack_;
};