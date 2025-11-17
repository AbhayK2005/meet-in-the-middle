#include "dynamic_array.hpp"

DynamicArray::DynamicArray() : data(nullptr), size(0), capacity(0) {}

DynamicArray::~DynamicArray() {
    if (data != nullptr) {
        delete[] data;
        data = nullptr;
    }
}

void DynamicArray::resize() {
    size_t new_capacity = (capacity == 0) ? 1 : capacity * 2;
    int* new_data = new int[new_capacity];
    for (size_t i = 0; i < size; i++) {
        new_data[i] = data[i];
    }
    if (data != nullptr) {
        delete[] data;
    }
    data = new_data;
    capacity = new_capacity;
}

void DynamicArray::push_back(int value) {
    if (size >= capacity) {
        resize();
    }
    data[size] = value;
    size++;
}

int DynamicArray::get(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

size_t DynamicArray::get_size() const {
    return size;
}

bool DynamicArray::is_empty() const {
    return size == 0;
}