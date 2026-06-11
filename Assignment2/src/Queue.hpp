//
// Created by Nazarii on 6/10/26.
//

#include <stdexcept>

#include "Queue.h"

template<typename T>
Queue<T>::Queue(size_t capacity) : capacity_(capacity), size_(0) {
    data_ = new T[capacity_];
}

template<typename T>
void Queue<T>::grow() {
    capacity_ += step_;

    T* newData = new T[capacity_];

    for (int i = 0; i < size_; i++) {
        newData[i] = data_[i];
    }

    delete[] data_;
    data_ = newData;
}

template<typename T>
Queue<T>::~Queue() {
    delete[] data_;
    size_ = 0;
}

template<typename T>
void Queue<T>::add(T element) {
    if (size_ == capacity_) {
        grow();
    }

    data_[size_] = element;
    size_++;
}

template<typename T>
size_t Queue<T>::size() const {
    return size_;
}

template<typename T>
T Queue<T>::pop() {
    if (size_ <= 0) {
        throw std::runtime_error("Queue is empty");
    }

    T popped = data_[0];

    for (int i = 0; i < size_; i++) {
        data_[i] = data_[i + 1];
    }

    size_--;

    return popped;
}

template<typename T>
T Queue<T>::get(size_t index) const {
    if (index >= size_) {
        throw std::runtime_error("Index is out of bounds");
    }

    return data_[index];
}

template<typename T>
void Queue<T>::clear() {
    delete[] data_;
    data_ = nullptr;
    capacity_ = 0;
    size_ = 0;
}
