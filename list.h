#pragma once

#include <iostream>

template<typename T>
class List {
public:
    List() {
        head_ = nullptr;
        tail_ = nullptr;
        size_ = 0;
    }

    void Insert(const T& item) {
        if (head_ == nullptr) {
            head_ = new Node(item);
            tail_ = head_;
        } else {
            Node *tmp = new Node(item);
            tmp->prev_ = tail_;
            tail_->next_ = tmp;
            tail_ = tmp;
        }
        ++size_;
    }

    void Delete(const int& numb) {
        if (IsSizeZero()) return;

        Node *it = Find(numb);
        if (size_ == 1) {
            delete head_;
        } else if (it == head_) {
            Node *tmp = head_->next_;
            delete head_;
            head_ = tmp;
            head_->prev_ = nullptr;
        } else if (it == tail_) {
            Node *tmp = tail_->prev_;
            delete tail_;
            tail_ = tmp;
            tail_->next_ = nullptr;
        } else {
            Node *left = it->prev_;
            Node *right = it->next_;
            left->next_ = right;
            right->prev_ = left;
            delete it;
        }
        --size_;
    }

    T *LookUp(const int& numb) const {
        if (IsSizeZero()) return nullptr;
        Node *it = Find(numb);
        return it != nullptr ? &it->item_ : nullptr;
    }

    T *Prev(const int& numb) const {
        if (numb == 1) {
            std::cerr << "No previous elements for head of list\n";
            return nullptr;
        }
        if (IsSizeZero()) return nullptr;
        Node *it = Find(numb);
        return it != nullptr ? &it->prev_->item_ : nullptr;
    }

    T *Next(const int& numb) const {
        if (numb == size_) {
            std::cerr << "No next elements for end of list\n";
            return nullptr;
        }
        if (IsSizeZero()) return nullptr;
        Node *it = Find(numb);
        return it != nullptr ? &it->next_->item_ : nullptr;
    }

    int GetSize() const {
        return size_;
    }

private:

    class Node {
    public:
        Node(const T& item = T()) {
            item_ = item;
        }

        T item_;
        Node *prev_ = nullptr, *next_ = nullptr;
    };

    Node *Find(const int& numb) const {
        if (numb > 0 && numb <= size_) {
            Node *it = head_;
            for (int i = 1; i < numb; ++i) {
                it = it->next_;
            }
            return it;
        } else {
            std::cerr << "Element doesn't exist\n";
            return nullptr;
        }

    }

    bool IsSizeZero() const {
        if (size_ == 0) {
            std::cerr << "Size = 0\n";
            return true;
        }
        return false;
    }

    int size_;
    Node *head_, *tail_;
};
