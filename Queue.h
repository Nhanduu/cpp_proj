#pragma once

template<typename T>
class Queue {
public:
    Queue() {
        head_ = nullptr;
        size_ = 0;
    }

    void Enqueue(const T& item) {
        if (head_ == nullptr) {
            head_ = new Node(item);
        } else {
            Node *tmp = new Node(item);

            auto it = head_;
            while (it->next_ != nullptr) {
                it = it->next_;
            }
            it->next_ = tmp;
        }
        ++size_;
    }

    void Dequeue() {
        if (head_->next_ == nullptr) {
            delete head_;
            head_ = nullptr;
        } else {
            Node *tmp = head_->next_;
            delete head_;
            head_ = tmp;
        }
        --size_;
    };

    T Front() const {
        return head_->item_;
    }

protected:
    class Node {
    public:
        Node(const T& item) {
            item_ = item;
        }

        T item_;
        Node *next_ = nullptr;
    };

    int size_;
    Node *head_;
};