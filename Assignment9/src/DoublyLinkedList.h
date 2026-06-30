//
// Created by Nazarii Tsubera on 6/25/26.
//

#ifndef ASSIGNMENT9_LINKEDLIST_H
#define ASSIGNMENT9_LINKEDLIST_H
#include <exception>
#include <iostream>
#include <ostream>
#include <string>


class DoublyLinkedList {
private:
    struct Node {
        Node* next;
        std::string value;
    };

    Node* head;
public:
    // class Iterator {
    // private:
    //     Node* current;
    //     operator++() {
    //         current = current->next;
    //     }
    //
    //     std::string operator*() const {
    //         return current->value;
    //     }
    //
    //     operator!=(const Iterator& other) const {
    //         return other.current != current ? true : false;
    //     }
    // }
public:
    DoublyLinkedList() : head(nullptr) {}
    virtual ~DoublyLinkedList() {
        clear();
    }

    void insertFront(const std::string& value) {
        Node* newNode = new Node({head, value});
        head = newNode;
    }

    std::string get(size_t index) const {
        Node* current = head;

        for (size_t i = 0; i < index; i++) {
            if (current == nullptr) {
                throw std::out_of_range("Index out of range");
            }

            current = current->next;
        }

        if (current == nullptr) {
            throw std::out_of_range("Index out of range");
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

        Node* newNode = new Node{current->next, value};
        current->next = newNode;
    }

    void remove(const std::string& value) {
        if (head == nullptr) {
            return;
        }

        if (head->value == value) {
            Node* old = head;
            head = head->next;
            delete old;
            return;
        }

        Node* current = head;

        while (current->next != nullptr && current->next->value != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            return; // value not found
        }

        Node* old = current->next;
        current->next = current->next->next;
        delete old;
    }

    [[nodiscard]] size_t count() const {
        Node* current = head;
        size_t count = 0;

        while (current != nullptr) {
            current = current->next;
            count++;
        }
        return count;
    }

    void clear() {
        Node* current = head;

        while (current != nullptr) {
            Node* old = current;
            current = current->next;
            delete old;
        }

        head = nullptr;
    }

    void print() const {
        std::cout << "[ ";

        for (Node* current = head; current != nullptr; current = current->next) {
            std::cout << current->value;

            if (current->next != nullptr) {
                std::cout << " -> ";
            }
        }

        std::cout << " ]" << std::endl;
    }
};



#endif //ASSIGNMENT9_LINKEDLIST_H
