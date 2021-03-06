## Information
No video for this one! It seemed like it would take a long time, and it did! A video would be too long to be useful.

### Custom Exceptions
You can find the code pertaining to custom exceptions for the Singly Linked List in [`linked_list_oob.hpp`](linked_list_oob.hpp), which defines the Linked List Out of Bounds exception.

*Note: a `.hpp` file acts like a `.h` file but is generally targeted for C++ development whereas a `.h` file can be used in C/C++.*

### Singly Linked List
The code for this is in the [`singly_linked_list.hpp`](singly_linked_list.hpp) header because it is templated, and therefore should generally be in the header file. Note that there *is* a way to separate them but to avoid confusion, it has been avoided.

In the Singly Linked List there are some functions marked as **deprecated**, which means that they are not used anywhere and would be scheduled to be removed in a future version. Their purpose is to make the Rule of 5 *(Destructor, Copy Construct/Assign, Move Construct/Assign)* a little more DRY (Don't Repeat Yourself: the code is not very 'self similar' and portions where code would be duplicated or nearly duplicated are extracted into functions).

### The API
This is somewhere between Dr. Leyk's CSCE 221 Doubly Linked List and the `std::list`/`std::vector` API. Some of the functions are bad and should not be used, like access into the list at a point is a generally bad idea as opposed to implementing an iterator.