#pragma once
#include <stdexcept>

class DynamicArray {
private:
    int* data;
    size_t size;
    size_t capacity;
    void resize();
public:
    DynamicArray();
    ~DynamicArray();
    DynamicArray(const DynamicArray&) = delete;
    DynamicArray& operator=(const DynamicArray&) = delete;
    void push_back(int value);
    int get(size_t index) const;
    size_t get_size() const;
    bool is_empty() const;
};