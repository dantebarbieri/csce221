#ifndef _PAIR_H_
#define _PAIR_H_

struct Pair {
    double x, y;
    Pair(int x = 0, int y = 0) : x(x), y(y) {}
    bool operator==(const Pair& other) const {
        // CPP Operator Precedence: cppreference.com
        // return (*this).x == other.x and (*this).y == other.y;
        return this->x == other.x && this->y == other.y;
    }
};

#endif