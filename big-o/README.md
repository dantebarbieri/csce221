## Information
Video Link: [Makefiles & GDB and Big O Analysis](https://tamu.zoom.us/rec/share/X-ncEcYXMsnxVqn5sRop8f5H1KuzKaaGp6BImOEvTdTclgUbTMYeJRQCXalKD0LY.Srygw_74lu-jSPdd) &mdash; Access Passcode: H^5Q.KHA

### Analysis
The following code can be found in [`bigo.cpp`](bigo.cpp):
```cpp
int foo(int n) {
    int accumulator = 0;
    for(int i = 1; i < n; i *= 2) {
        accumulator++;// accumulator += 1 // accumulator = accumulator + 1
        for(int j = 0; j < n; ++j) {
            accumulator++;
            for(int k = 0; k < j; ++k) {
                accumulator++;
            }
        }
    }
    return accumulator;
}
```
Since we assume that Assignments, Additions, and Return statements take one operation, and the overhead of allocating an object and managing a `for` loop is assumed to take 0 operations.
```cpp
int accumulator = 0; // 1 Operation
```
```cpp
for(int i = 1; i < n; i *= 2) // ceil(log(n)) Repetitions
```
```cpp
accumulator++; // 2 Operations see expansion
```
```cpp
for(int j = 0; j < n; ++j) // n Repetitions
```
```cpp
for(int k = 0; k < j; ++k) // j Repetitions
```
```cpp
return accumulator; // 1 Operation
```
This breakdown is how the math in [`main.pdf`](main.pdf) is derived initially. Note that summations correlate with loops and that they nest (are inside one another) just like their original `for` loops.