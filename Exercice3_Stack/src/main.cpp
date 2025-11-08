#include <iostream>
#include <memory>
#include <stdexcept>

template<typename T>
class Stack {
private:
    std::unique_ptr<T[]> data;
    size_t capacity;
    size_t top;
public:
    Stack(size_t cap=10) : data(std::make_unique<T[]>(cap)), capacity(cap), top(0) {}
    void push(const T& val) {
        if(top>=capacity) throw std::overflow_error("StackOverflow");
        data[top++] = val;
    }
    void pop() {
        if(top==0) throw std::underflow_error("StackUnderflow");
        top--;
    }
    T& peek() { return data[top-1]; }
    bool empty() const { return top==0; }
};
