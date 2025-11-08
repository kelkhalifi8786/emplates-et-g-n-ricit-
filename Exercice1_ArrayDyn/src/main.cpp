#include <iostream>

template<typename T>
class ArrayDyn {
private:
    T* data;
    size_t size;
    size_t capacity;
public:
    ArrayDyn(size_t cap = 10) : size(0), capacity(cap) { data = new T[capacity]; }
    ~ArrayDyn() { delete[] data; }

    void push_back(const T& val) {
        if (size >= capacity) {
            capacity *= 2;
            T* temp = new T[capacity];
            for (size_t i = 0; i < size; ++i) temp[i] = data[i];
            delete[] data;
            data = temp;
        }
        data[size++] = val;
    }

    T& operator[](size_t i) { return data[i]; }
    size_t getSize() const { return size; }

    class Iterator {
        T* ptr;
    public:
        Iterator(T* p) : ptr(p) {}
        T& operator*() { return *ptr; }
        Iterator& operator++() { ++ptr; return *this; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
    };

    Iterator begin() { return Iterator(data); }
    Iterator end() { return Iterator(data + size); }
};

int main() {
    ArrayDyn<int> arr;
    arr.push_back(10);
    arr.push_back(20);

    for(auto &x : arr) std::cout << x << " ";
    std::cout << std::endl;
    return 0;
}
