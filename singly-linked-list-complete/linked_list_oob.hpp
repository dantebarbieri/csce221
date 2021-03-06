#ifndef _LINKED_LIST_OOB_HPP_
#define _LINKED_LIST_OOB_HPP_

#include <exception>
#include <string>

class LinkedListOutOfBounds : public std::exception {
    std::string message_text;
    public:
    LinkedListOutOfBounds(const std::string& message) : message_text(message) {}
    const char* what() const noexcept { return message_text.c_str(); }
};

#endif