//
// Created by Nazarii on 6/10/26.
//

#ifndef QUEUE_H
#define QUEUE_H


template <typename T>
class Queue {
public:
    Queue(size_t capacity=10);
    virtual ~Queue();

    void add(T element);
    void clear();
    T pop();
    [[nodiscard]] size_t size() const;
    [[nodiscard]] T get(size_t index) const;
private:
    void grow();
private:
    static constexpr size_t step_ = 10;
    size_t size_;
    size_t capacity_;
    T* data_;
};


#include "Queue.hpp"

#endif //QUEUE_H
