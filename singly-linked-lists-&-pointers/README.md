## Information
Video Link: [Makefiles & GDB and Big O Analysis](https://tamu.zoom.us/rec/share/9w8y00g2JHTbRTwE42YZi5ZaB5hHyQcU2xnocewkTFdr-AFRmRUnMfahq5LmMj_y.Yas7jaT_H8xkjGEv) &mdash; Access Passcode: RJ1ji?py

### Pair
[`pair.h`](pair.h) defines a simple `Pair` struct and has a link to the [CPP Operator Precedence Table](https://en.cppreference.com/w/cpp/language/operator_precedence). Its primary purpose is to demonstrate the difference between the operator `.` versus the operator `->`.

In [`main.cpp`](main.cpp), we use the `Pair` in the `countXis0` function, which takes in an array of `Pair` objects and accesses their data without using the `operator[]`, instead with the use of pointer arithmetic.

We also use *pointers* and *references* in [`main.cpp`](main.cpp) to demonstrate how *references* differ from the `&` (address-of) operator; it is in the same manner that pointers differ from the `*` (indirection/dereference) operator.

### Singly Linked List
[`singlylinked.h`](singlylinked.h) is a simple Singly Linked List implementation that makes use of the pointer mechanisms discussed in [`Pair`](#pair) to give an example of how they can be used on a Singly Linked List. There is some minor testing of the Singly Linked List in [`main.cpp`](main.cpp).

### The API
This is somewhere between Dr. Leyk's CSCE 221 Doubly Linked List and the `std::list`/`std::vector` API. Some of the functions are bad and should not be used, like access into the list at a point is a generally bad idea as opposed to implementing an iterator.