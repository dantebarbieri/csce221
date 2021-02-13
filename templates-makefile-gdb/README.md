## Information
### Makefile
You can find the Makefile code in [`Makefile`](Makefile).

### GDB
You cannot find the broken code that I fixed with GDB in the files anymore. You can write similarly broken code in the following ways:
```cpp
void infinite_recursion() {
    return infinite_recursion();
}

int* illegal_memory_access() {
    int* a = 0; // This sets a to NULL (nullptr)
    for(int i = 0; i < 10; ++i)
        *a += i; // Dereferencing (*) a leads to illegal access on write
    return a;
}
```
Just be sure to call `infinite_recursion` or `illegal_memory_access` to find and fix the issues with `gdb`.

### Templates
You can find templated code in [`Base.h`](Base.h) and [`main.cpp`](main.cpp).