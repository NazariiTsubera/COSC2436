//
// Created by nazarii on 6/9/26.
//

#ifndef ASSIGNMENT1_VECTOR_H
#define ASSIGNMENT1_VECTOR_H
#include <cstddef>


template <typename T>
class Vector {
public:
    Vector() : Vector(step_) {}
    Vector(std::size_t capacity): capacity_(capacity), size_(0) {
        data_ = new T[capacity_];
        clear();
    };

    ~Vector() {
        delete[] data_;
    };

    void clear();
    void append(T element);
    void remove(std::size_t index);
    void insert(T element, std::size_t index);
    T& get(std::size_t index);


    [[nodiscard]] std::size_t size() const { return size_; }
    [[nodiscard]] std::size_t capacity() const { return capacity_; }

private:
    void grow();


private:
    constexpr static std::size_t step_{10};
    std::size_t capacity_;
    std::size_t size_;
    T* data_;
};

#include "Vector.hpp"


#endif //ASSIGNMENT1_VECTOR_H
