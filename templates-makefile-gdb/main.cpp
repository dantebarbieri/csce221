#include <iostream>
#include <vector>
#include "Base.h"
#include "Derived.h"

template <typename T>
using SamePair = Pair<T, T>;

int main() {
    std::cout << "Program Run" << std::endl;
    Pair<int, int> coordinates(5, 10);
    Pair<char, char> char_coordinates('?', 'O');
    SamePair<SamePair<int>> nesting;
    nesting.get_first().get_first() = 10;
    nesting.get_first().get_second() = 1 << 20;
    nesting.get_second().get_first() = 5;
    nesting.get_second().get_second() = 1 << 5;
    std::cout << coordinates << std::endl << char_coordinates << std::endl << nesting << std::endl;
    std::cout << (coordinates == nesting.get_first()) << std::endl;
    return 0;
}