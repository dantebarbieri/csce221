#ifndef _SINGLY_LINKED_H_
#define _SINGLY_LINKED_H_

#include <iostream>

template <typename T>
struct SinglyLinkedNode {
    T obj;
    SinglyLinkedNode<T>* next;
};

template <typename T>
class SinglyLinked {
    SinglyLinkedNode<T> header, trailer;
    public:
    SinglyLinked();
    ~SinglyLinked();
    void push_back(const T& to_be_inserted);
    template <typename TT>
    friend std::ostream& operator<<(std::ostream& o, const SinglyLinked<TT>& sl);
};

template <typename T>
SinglyLinked<T>::SinglyLinked() {
    header.next = &trailer;
    trailer.next = nullptr;
}

template <typename T>
SinglyLinked<T>::~SinglyLinked() {
    SinglyLinkedNode<T>* cursor = header.next;
    while(cursor != &trailer) {
        auto copy_curs = cursor;
        cursor = cursor->next;
        delete copy_curs;
    }
}

template <typename T>
void SinglyLinked<T>::push_back(const T& to_be_inserted) {
    if(header.next == &trailer) {
        header.next = new SinglyLinkedNode<T>();
        header.next->obj = to_be_inserted;
        header.next->next = &trailer;
    } else {
        SinglyLinkedNode<T>* cursor = header.next;
        while(cursor->next != &trailer) {
            cursor = cursor->next;
        }
        cursor->next = new SinglyLinkedNode<T>();
        cursor->next->obj = to_be_inserted;
        cursor->next->next = &trailer;
    }
}

template <typename TT>
std::ostream& operator<<(std::ostream& o, const SinglyLinked<TT>& sl) {
    SinglyLinkedNode<TT>* cursor = sl.header.next;
    while(cursor != &sl.trailer) {
        o << cursor->obj;
        if(cursor->next != &sl.trailer) {
            o << " ";
        }
        cursor = cursor->next;
    }
    return o;
}

#endif