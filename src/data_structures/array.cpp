#include "array.h"
#include <stdexcept>

Array::Array(int size) : size(size) {
    data = new int[size];
}

Array::~Array() {
    delete[] data;
}

int Array::getSize() const {
    return size;
}

int Array::get(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

void Array::set(int index, int value) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of range");
    }
    data[index] = value;
}

Array::Array(const Array& other) : size(other.size) {
    data = new int[size];
    for (int i = 0; i < size; ++i) {
        data[i] = other.data[i];
    }
}