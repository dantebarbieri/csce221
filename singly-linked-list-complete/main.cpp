#include <iostream>
#include "singly_linked_list.hpp"

using std::cout, std::endl;

int main() {
    SinglyLinkedList<int> list;

    for(int i = 0; i < 10; ++i) {
        list.insert(i, i / 2);
    }

    cout << list << endl;

    for(int i = 0; i < 5; ++i) {
        cout << "Removing: " << list.remove(i) << endl;
    }

    cout << list << endl;

    for(unsigned i = 0; i < list.size(); ++i) {
        cout << "List[" << i << "]: " << list[i] << endl;
    }

}