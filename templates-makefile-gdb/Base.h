#ifndef BASE_H
#define BASE_H

#include <iostream>

template <typename T, typename U>
class Pair {
    T first;
    U second;
    public:
    Pair() : first(), second() {}
    Pair(const T& first, const U& second) : first(first), second(second) {}
    const T& get_first() const { return first; }
    const U& get_second() const { return second; }
    T& get_first() { return first; }
    U& get_second() { return second; }
    void set_first(const T& newFirst) { first = newFirst; }
    void set_second(const U& newSecond) { second = newSecond; }
};

template <typename T, typename U>
std::ostream& operator<<(std::ostream& stream, const Pair<T, U>& pair) {
    return stream << "(" << pair.get_first() << ", " << pair.get_second() << ")";
}

#endif