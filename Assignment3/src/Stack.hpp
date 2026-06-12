//
// Created by Nazarii on 6/10/26.
//
#pragma once

#include "Stack.h"

template<typename T>
Stack<T>::Stack(size_t capacity) : data_(nullptr), capacity_(capacity), size_(0){
    grow();
}

template<typename T>
Stack<T>::~Stack() {
    delete[] data_;
    size_ = 0;
    capacity_ = 0;
}

template<typename T>
void Stack<T>::push(T element) {
    if (size_ == capacity_) {
        grow();
    }

    data_[size_] = element;
    size_++;
}

template<typename T>
T Stack<T>::pop() {
    if (size_ <= 0) {
        throw std::out_of_range("Stack is empty");
    }

    size_--;

    return data_[size_];
}

template<typename T>
size_t Stack<T>::size() const {
    return size_;
}

template<typename T>
void Stack<T>::grow() {
    T* newStack = new T[size_ + step_];

    for (size_t i = 0; i < size_; i++) {
        newStack[i] = data_[i];
    }

    if (size_ > 0) {
        delete[] data_;
    }

    data_ = newStack;
    capacity_ = size_ + step_;
}
