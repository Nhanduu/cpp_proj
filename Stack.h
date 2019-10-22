#pragma once

template<typename T>
class Stack {
public:
    Stack() {
        tail_ = nullptr;
        size_ = 0;
    }

    void Push(const T& item) {
        if (tail_ == nullptr) {
            tail_ = new Node(item);
        } else {
            Node *tmp = new Node(item);
            tmp->next_ = tail_;
            tail_ = tmp;
        }
        ++size_;
    }

    void Pop() {
        if (tail_->next_ == nullptr) {
            delete tail_;
            tail_ = nullptr;
        } else {
            Node *tmp = tail_->next_;
            delete tail_;
            tail_ = tmp;
        }
        --size_;
    }

    T Top() {
        return tail_->item_;
    }

protected:
    class Node {
    public:
        Node(const T& item = T()) {
            item_ = item;
        }

        T item_;
        Node *next_ = nullptr;
    };

    int size_;
    Node *tail_;
};