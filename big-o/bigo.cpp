#include <iostream>

int operations = 0;

int foo(int n) {
    int accumulator = 0; operations++;
    for(int i = 1; i < n; i *= 2) {
        accumulator++; operations += 2;// accumulator += 1 // accumulator = accumulator + 1
        for(int j = 0; j < n; ++j) {
            accumulator++; operations += 2;
            for(int k = 0; k < j; ++k) {
                accumulator++; operations += 2;
            }
        }
    }
    operations +=1; return accumulator;
}

int main() {
    for(int i = 10; i < 10000000; i *= 10) {
        foo(i);
        std::cout << operations << std::endl;
        operations = 0;
    }
}