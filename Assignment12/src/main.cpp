#include <algorithm>
#include <iostream>

class BinaryTree {
public:
    struct Node {
        int value;
        Node* left;
        Node* right;
    };
private:
    Node* root;
    size_t _height(Node* node) {
        if (node == nullptr) return 0;

        return 1 + std::max(_height(node->left), _height(node->right));
    }

public:
    explicit BinaryTree(Node *root)
        : root(root) {
    }

    ~BinaryTree() {}

    size_t height() {
        return _height(root);
    }
};

using Node = BinaryTree::Node;

int main() {
    std::cout << "===== BinaryTree Height Test =====" << std::endl;

    BinaryTree emptyTree(nullptr);
    std::cout << "Empty tree height: " << emptyTree.height()
              << " (expected 0)" << std::endl;

    Node singleNode{10, nullptr, nullptr};
    BinaryTree singleNodeTree(&singleNode);
    std::cout << "Single node tree height: " << singleNodeTree.height()
              << " (expected 1)" << std::endl;

    Node leftChild{5, nullptr, nullptr};
    Node deepChild{20, nullptr, nullptr};
    Node rightChild{15, nullptr, &deepChild};
    Node root{10, &leftChild, &rightChild};

    BinaryTree testTree(&root);
    std::cout << "Three level tree height: " << testTree.height()
              << " (expected 3)" << std::endl;

    std::cout << "===== End Test =====" << std::endl;

    return 0;
}