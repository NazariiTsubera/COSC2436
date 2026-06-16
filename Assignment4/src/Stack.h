//
// Created by Nazarii on 6/10/26.
//

#ifndef QUEUE_H
#define QUEUE_H


template <typename T>
class Stack {
public:
    explicit Stack(size_t capacity=10);
    virtual ~Stack();

    Stack(Stack<T>&) = delete;
    Stack<T>& operator=(const Stack<T>&) = delete;

    void push(T element);
    T pop();

    [[nodiscard]] size_t size() const;
private:
    void grow();
    static constexpr size_t step_ = 10;
    size_t size_;
    size_t capacity_;
    T* data_;
};

#include "Stack.hpp"

#endif //QUEUE_H


