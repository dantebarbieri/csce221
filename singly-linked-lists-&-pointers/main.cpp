#include "iostream"
#include "pair.h"
#include "singlylinked.h"

using std::cout, std::endl;

int countXis0(Pair* arr, int n) {
    int count = 0;
    cout << arr << endl;
    for(int i = 0; i < n; ++i) {
        cout << &arr[i] << endl;
        cout << (arr + i) << endl;
        if((arr + i)->x == 0) {
            ++count;
        }
    }
    return count;
}

// 0 1 2 3 4 5 6 7 8 9 A B C D E F
// 0x10 = 16
// 0xF = 15

int main() {
    Pair p;
    Pair equals_p(0, 0);
    Pair& pref = p;
    Pair* ppoint = &p;

    cout << "Does P Equal P?: " << (p == equals_p) << endl;

    Pair pairs[20];
    for(int i = 0; i < sizeof(pairs) / sizeof(pairs[0]); ++i) {
        pairs[i].x = rand() % 5;
    }

    cout << "Number of Pairs where X is zero: " << countXis0(pairs, sizeof(pairs)/sizeof(pairs[0])) << endl;

    SinglyLinked<int> list;
    for(int i = 0; i < sizeof(pairs) / sizeof(pairs[0]); ++i) {
        list.push_back(pairs[i].x);
    }
    cout << list << endl;
}