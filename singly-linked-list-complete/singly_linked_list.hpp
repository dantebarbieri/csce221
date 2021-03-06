#ifndef _SINGLY_LINKED_LIST_H
#define _SINGLY_LINKED_LIST_H

#include <iostream>
#include "linked_list_oob.hpp"

template <typename T>
struct Node {
    T obj;
    Node<T>* next;
    Node(T obj = T(), Node<T>* next = nullptr) : obj(obj), next(next) {}
    explicit Node(Node<T>* next) : obj(), next(next) {}
};

template <typename T>
class SinglyLinkedList {
    Node<T> header, trailer;
    static constexpr size_t npos = -1;
    [[deprecated]] void move(SinglyLinkedList<T>&&);
    [[deprecated]] void copy(const SinglyLinkedList<T>&);
public:
    SinglyLinkedList();
    ~SinglyLinkedList();
    SinglyLinkedList(const SinglyLinkedList<T>&);
    SinglyLinkedList(SinglyLinkedList<T>&&);
    SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>&);
    SinglyLinkedList<T>& operator=(const SinglyLinkedList<T>&&);
    [[deprecated]] void clear();
    void insert(const T& obj, size_t index = npos);
    T remove(size_t index = npos);
    const T& operator[](size_t index) const;
    T& operator[](size_t index);
    const T& at(size_t index) const;
    T& at(size_t index);
    size_t size() const;
    bool empty() const;
    template <typename T1>
    friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<T1>& sll);
};

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList() : header(), trailer() {
    header.next = &trailer;
}

template <typename T>
SinglyLinkedList<T>::~SinglyLinkedList() {
    Node<T>* cursor = header.next;
    while(cursor != &trailer) {
        auto deletable = cursor;
        cursor = cursor->next;
        delete deletable;
    }
    header.next = &trailer;
}

template <typename T>
void SinglyLinkedList<T>::clear() {
    Node<T>* cursor = header.next;
    while(cursor != &trailer) {
        auto deletable = cursor;
        cursor = cursor->next;
        delete deletable;
    }
    header.next = &trailer;
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(const SinglyLinkedList<T>& sll) : header(), trailer() {
    Node<T>* cursor = sll.header.next;
    while(cursor != &sll.trailer) {
        insert(cursor->obj);
        cursor = cursor->next;
    }
}

template <typename T>
void SinglyLinkedList<T>::copy(const SinglyLinkedList<T>& sll) {
    Node<T>* cursor = sll.header.next;
    while(cursor != &sll.trailer) {
        insert(cursor->obj);
        cursor = cursor->next;
    }
}

template <typename T>
SinglyLinkedList<T>::SinglyLinkedList(SinglyLinkedList<T>&& sll) : header(sll.header.next), trailer(sll.trailer.next) {
    // Finds the last node, which we want to point at our tail
    Node<T>* cursor = header.next;
    while(cursor->next != &sll.trailer) {
        cursor = cursor->next;
    }
    // Points the last node at our tail
    cursor->next = &trailer;
    // Reroute SLL
    sll.header.next = &sll.trailer;
}

template <typename T>
void SinglyLinkedList<T>::move(SinglyLinkedList<T>&& sll) {
    // Finds the last node, which we want to point at our tail
    Node<T>* cursor = header.next;
    while(cursor->next != &sll.trailer) {
        cursor = cursor->next;
    }
    // Points the last node at our tail
    cursor->next = &trailer;
    // Reroute SLL
    sll.header.next = &sll.trailer;
}

template <typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>& sll) {
    if(this != &sll) {
        // Destructor
        Node<T>* cursor = header.next;
        while(cursor != &trailer) {
            auto deletable = cursor;
            cursor = cursor->next;
            delete deletable;
        }
        header.next = &trailer;

        // Copy Constructor
        cursor = sll.header.next;
        while(cursor != &sll.trailer) {
            insert(cursor->obj);
            cursor = cursor->next;
        }
    }
    return *this;
}

template <typename T>
SinglyLinkedList<T>& SinglyLinkedList<T>::operator=(const SinglyLinkedList<T>&& sll) {
    if(this != &sll) {
        // Destructor
        Node<T>* cursor = header.next;
        while(cursor != &trailer) {
            auto deletable = cursor;
            cursor = cursor->next;
            delete deletable;
        }
        header.next = &trailer;

        // Move constructor
        // Finds the last node, which we want to point at our tail
        cursor = header.next;
        while(cursor->next != &sll.trailer) {
            cursor = cursor->next;
        }
        // Points the last node at our tail
        cursor->next = &trailer;
        // Reroute SLL
        sll.header.next = &sll.trailer;
    }
    return *this;
}

template <typename T>
void SinglyLinkedList<T>::insert(const T& obj, size_t index) {
    size_t sz = size();
    if(index == npos) { index = sz; }
    if(index > sz) { throw LinkedListOutOfBounds("Insert index is larger than size"); }
    if(index == 0) {
        header.next = new Node<T>(obj, header.next);
        // header.next = new Node<T>();
        // header.next->obj = obj;
        // header.next->next = &trailer;
    } else {
        Node<T>* cursor = header.next;
        size_t curr_index = 0;
        while(cursor != &trailer && curr_index < index - 1) {
            ++curr_index;
            cursor = cursor->next;
        }
        // Cursor is the node before the place we want to insert.
        cursor->next = new Node<T>(obj, cursor->next);
    }
}

template <typename T>
T SinglyLinkedList<T>::remove(size_t index) {
    size_t sz = size();
    if(index == npos) { index = sz; }
    if(sz == 0) { throw LinkedListOutOfBounds("Remove from empty list"); }
    if(index >= sz) { throw LinkedListOutOfBounds("Remove index is not in list"); }
    Node<T>* cursor = header.next;
    if(index == 0) {
        cursor = &header;
    } else {
        size_t curr_pos = 0;
        while(cursor != &trailer && curr_pos < index - 1) {
            ++curr_pos;
            cursor = cursor->next;
        }
    }
    Node<T>* temp = cursor->next;
    cursor->next = temp->next;
    temp->next = nullptr;
    T obj = temp->obj;
    delete temp;
    return obj;
}

template <typename T>
const T& SinglyLinkedList<T>::operator[](size_t index) const {
    Node<T>* cursor = header.next;
    for(size_t i = 0; i < index; ++i) {
        cursor = cursor->next;
    }
    return cursor->obj;
}

template <typename T>
T& SinglyLinkedList<T>::operator[](size_t index) {
    Node<T>* cursor = header.next;
    for(size_t i = 0; i < index; ++i) {
        cursor = cursor->next;
    }
    return cursor->obj;
}

template <typename T>
const T& SinglyLinkedList<T>::at(size_t index) const {
    size_t sz = size();
    if(index >= sz) { throw LinkedListOutOfBounds("Indexing into position not in list"); }
    return (*this)[index];
}

template <typename T>
T& SinglyLinkedList<T>::at(size_t index) {
    size_t sz = size();
    if(index >= sz) { throw LinkedListOutOfBounds("Indexing into position not in list"); }
    return (*this)[index];
}

template <typename T>
size_t SinglyLinkedList<T>::size() const {
    size_t count = 0;
    Node<T>* cursor = header.next;
    while(cursor != &trailer) {
        ++count;
        cursor = cursor->next;
    }
    return count;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const SinglyLinkedList<T>& sll) {
    Node<T>* cursor = sll.header.next;
    os << "[";
    while(cursor != &sll.trailer) {
        os << cursor->obj;
        if(cursor->next != &sll.trailer) {
            os << ", ";
        }
        cursor = cursor->next;
    }
    return os << "]";
}

#endif