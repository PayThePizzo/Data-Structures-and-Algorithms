//
// Created by PayThePizzo on 3/27/2023.
//

#include <iostream>

using namespace std;

// Node class
class Node {
public:
    int value;
    Node* left_child;
    Node* right_sibling;

    Node(int val) {
        value = val;
        left_child = NULL;
        right_sibling = NULL;
    }
};


// Binary Tree class
class BinaryTree {
public:
    Node* root;
    BinaryTree() {
        root = NULL;
    }

    // Insert a node
    void insert(int value) {

    }

    // In-order traversal
    void inorder(Node* node) {

    }

    // Pre-order traversal
    void preorder(Node* node) {

    }

    // Post-order traversal
    void postorder(Node* node) {

    }
};

// Main function
int main() {
    return 0;
}
