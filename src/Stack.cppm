module;

#include <cstdint>
#include <stdexcept>

export module Stack;

class UnderflowException: public std::exception {
public:
    const char* what() const noexcept {
        return "Stack is empty";
    }
};

class OverflowException: public std::exception {
public:
    const char* what() const noexcept {
        return "Stack exceeded its maximum capacity";
    }
};

export template <typename T>
class Stack {
    T* data;
    size_t capacity;
    uint32_t head = 0;

public:
    Stack(size_t capacity) {
        this->capacity = capacity;
        data = new T[capacity];
    }

    bool empty() const {
        return head == 0;
    }

    bool full() const {
        return head >= capacity;
    }

    void push(T value) {
        if (head >= capacity)
            throw OverflowException();
        data[head++] = value;
    }

    void push(T&& value) {
        if (head >= capacity)
            throw OverflowException();
        data[head++] = value;
    }

    T pop() {
        if (empty())
            throw UnderflowException();
        return data[--head];
    }

    const T& top() const {
        return data[head - 1];
    }
};
