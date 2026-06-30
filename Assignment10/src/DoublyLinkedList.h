//
// Created by Nazarii Tsubera on 6/25/26.
//

#ifndef ASSIGNMENT10_DOUBLYLINKEDLIST_H
#define ASSIGNMENT10_DOUBLYLINKEDLIST_H
#include <exception>
#include <iostream>
#include <ostream>
#include <string>


class DoublyLinkedList {
private:
    struct Node {
        Node* next;
        Node* prev;
        std::string value;
    };

    Node* head;
    Node* tail;
    size_t size;
public:
    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    virtual ~DoublyLinkedList() {
        clear();
    }

    void insertFront(const std::string& value) {
        Node* newNode = new Node({head, nullptr, value});

        if (head != nullptr) {
            head->prev = newNode;
        }

        head = newNode;

        if (tail == nullptr) {
            tail = newNode;
        }
        size++;
    }

    [[nodiscard]] std::string get(size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node* current;

        if (index <= size / 2) {
            current = head;

            for (size_t i = 0; i < index; i++) {
                current = current->next;
            }
        } else {
            current = tail;

            for (size_t i = size - 1; i > index; i--) {
                current = current->prev;
            }
        }

        return current->value;
    }

    void insertAlpha(const std::string& value) {
        if (head == nullptr || value < head->value) {
            insertFront(value);
            return;
        }

        Node* current = head;

        while (current->next != nullptr && current->next->value < value) {
            current = current->next;
        }

        Node* newNode = new Node{current->next, current, value};

        if (current->next != nullptr) {
            current->next->prev = newNode;
        } else {
            tail = newNode;
        }

        current->next = newNode;
        size++;
    }

    void remove(const std::string& value) {
        Node* current = head;

        while (current != nullptr && current->value != value) {
            current = current->next;
        }

        if (current == nullptr) {
            return;
        }

        if (current->prev != nullptr) {
            current->prev->next = current->next;
        } else {
            head = current->next;
        }

        if (current->next != nullptr) {
            current->next->prev = current->prev;
        } else {
            tail = current->prev;
        }

        delete current;
        size--;
    }

    [[nodiscard]] size_t count() const {
        return size;
    }

    void clear() {
        Node* current = head;

        while (current != nullptr) {
            Node* old = current;
            current = current->next;
            delete old;
        }

        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    void print() const {
        std::cout << "[ ";

        for (Node* current = head; current != nullptr; current = current->next) {
            std::cout << current->value;

            if (current->next != nullptr) {
                std::cout << " <--> ";
            }
        }

        std::cout << " ]" << std::endl;
    }
};



#endif //ASSIGNMENT10_DOUBLY_LINKEDLIST_H
