//
// Created by nazarii on 6/9/26.
//

#include "Vector.h"

template<typename T>
void Vector<T>::clear() {
    size_ = 0;
}

template<typename T>
void Vector<T>::append(T element) {
    size_++;

    if (size_ >= capacity_) {
        grow();
    }

    data_[size_ - 1] = element;
}

template<typename T>
void Vector<T>::remove(std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }

    for (size_t i = index; i < size_; i++) {
        data_[i] = data_[i + 1];
    }

    size_--;
}

template<typename T>
void Vector<T>::insert(T element, std::size_t index) {
    if (index > size_) {
        throw std::out_of_range("Index out of range");
    }

    size_++;

    if (size_ >= capacity_) {
        capacity_ += step_;
    }

    T* newData = new T[capacity_];

    for (size_t i = 0; i < size_; i++) {
        if (i < index) {
            newData[i] = data_[i];
            continue;
        }

        if ((i > index) && i > 0) {
            newData[i] = data_[i - 1];
        }

    }

    newData[index] = element;

    delete [] data_;
    data_ = newData;
}

template<typename T>
T & Vector<T>::get(std::size_t index) {
    if (index >= size_) {
        throw std::out_of_range("Index out of range");
    }

    return data_[index];
}

template<typename T>
void Vector<T>::grow() {
    capacity_ = capacity_ + step_;

    T* newData = new T[capacity_];

    for (std::size_t i = 0; i < size_; i++) {
        newData[i] = data_[i];
    }

    delete [] data_;
    data_ = newData;
}
