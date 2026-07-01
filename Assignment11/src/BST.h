//
// Created by Nazarii Tsubera on 6/30/26.
//

#ifndef ASSIGNMENT11_BST_H
#define ASSIGNMENT11_BST_H

#include <iostream>
#include <stdexcept>
#include <string>

class BST {
private:
    struct Node {
        int item;
        Node* left;
        Node* right;
    };

    Node* root;

    bool find(Node* node, int item) const;
    void insert(Node*& node, int item);
    void remove(Node*& node, int item);
    void deleteTree(Node*& node);
    void drawTree(Node* node, const std::string& prefix, const std::string& branch, bool isLast) const;

public:
    BST();
    ~BST();

    bool find(int item) const;
    void insert(int item);
    void remove(int item);
    void deleteTree();
    void drawTree() const;
};

inline BST::BST() : root(nullptr) {}

inline BST::~BST() {
    deleteTree();
}

inline bool BST::find(int item) const {
    return find(root, item);
}

inline void BST::insert(int item) {
    insert(root, item);
}

inline void BST::remove(int item) {
    remove(root, item);
}

inline void BST::deleteTree() {
    deleteTree(root);
}

inline void BST::drawTree() const {
    if (root == nullptr) {
        std::cout << "(empty)" << std::endl;
        return;
    }

    std::cout << root->item << std::endl;

    if (root->left != nullptr && root->right != nullptr) {
        drawTree(root->left, "", "L: ", false);
        drawTree(root->right, "", "R: ", true);
    }
    else if (root->left != nullptr) {
        drawTree(root->left, "", "L: ", true);
    }
    else if (root->right != nullptr) {
        drawTree(root->right, "", "R: ", true);
    }
}

inline bool BST::find(Node* node, int item) const {
    if (node == nullptr) {
        return false;
    }

    if (item < node->item) {
        return find(node->left, item);
    }

    if (item > node->item) {
        return find(node->right, item);
    }

    return true;
}

inline void BST::insert(Node*& node, int item) {

    if (node == nullptr) {
        Node* newNode = new Node{item, nullptr, nullptr};
        node = newNode;
        return;
    }

    if (item < node->item) {
        return insert(node->left, item);
    }
    if (item > node->item) {
        return insert(node->right, item);
    }

    throw std::runtime_error("Cannot insert dupliates");
}

inline void BST::remove(Node*& node, int item) {

    if (node == nullptr) {
        return;
    }

    if (item < node->item) {
        remove(node->left, item);
    }
    else if (item > node->item) {
        remove(node->right, item);
    }
    else {
        //found it, must check for conditions

        //leaf
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        }
        //left branch is nullptr
        else if (node->left == nullptr) {
            Node* temp = node;
            node = node->right;
            delete temp;
        }
        //right branch is nullptr
        else if (node->right == nullptr) {
            Node* temp = node;
            node = node->left;
            delete temp;
        }
        //neither children are nullptr
        else {
            Node* successor = node->right;

            while (successor->left != nullptr) {
                successor = successor->left;
            }

            node->item = successor->item;
            remove(node->right, successor->item);
        }
    }
}

inline void BST::deleteTree(Node*& node) {
    if (node == nullptr) {
        return;
    }

    deleteTree(node->left);
    deleteTree(node->right);

    delete node;
    node = nullptr;
}

inline void BST::drawTree(Node* node, const std::string& prefix, const std::string& branch, bool isLast) const {
    if (node == nullptr) {
        return;
    }

    std::cout << prefix << (isLast ? "`-- " : "|-- ") << branch << node->item << std::endl;

    const std::string childPrefix = prefix + (isLast ? "    " : "|   ");

    if (node->left != nullptr && node->right != nullptr) {
        drawTree(node->left, childPrefix, "L: ", false);
        drawTree(node->right, childPrefix, "R: ", true);
    }
    else if (node->left != nullptr) {
        drawTree(node->left, childPrefix, "L: ", true);
    }
    else if (node->right != nullptr) {
        drawTree(node->right, childPrefix, "R: ", true);
    }
}




#endif //ASSIGNMENT11_BST_H
