//
// Created by PayThePizzo on 3/27/2023.
//

#include <iostream>

using namespace std;

// Node class
class Node {
public:
    int value;
    Node* left;
    Node* right;
    Node(int val) {
        value = val;
        left = NULL;
        right = NULL;
    }
};

// Binary Search Tree class
class BST {
public:
    Node* root;
    BST() {
        root = NULL;
    }

    // Insert a node
    void insert(int value) {
        Node* node = new Node(value);
        if (root == NULL) {
            root = node;
            return;
        }
        Node* curr = root;
        while (true) {
            if (value < curr->value) {
                if (curr->left == NULL) {
                    curr->left = node;
                    return;
                }
                curr = curr->left;
            } else {
                if (curr->right == NULL) {
                    curr->right = node;
                    return;
                }
                curr = curr->right;
            }
        }
    }

    // Search for a node
    bool search(int value) {
        if (root == NULL) {
            return false;
        }
        Node* curr = root;
        while (curr != NULL) {
            if (value == curr->value) {
                return true;
            } else if (value < curr->value) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
        }
        return false;
    }

    // In-order traversal
    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->value << " ";
        inorder(node->right);
    }

    // Pre-order traversal
    void preorder(Node* node) {
        if (node == NULL) return;
        cout << node->value << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Post-order traversal
    void postorder(Node* node) {
        if (node == NULL) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->value << " ";
    }
};

// Main function
int main() {
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(7);
    tree.insert(1);
    tree.insert(9);

    cout << "In-order traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    cout << "Pre-order traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    cout << "Post-order traversal: ";
    tree.postorder(tree.root);
    cout << endl;

    cout << "Search for 7: " << (tree.search(7) ? "found" : "not found") << endl;
    cout << "Search for 2: " << (tree.search(2) ? "found" : "not found") << endl;

    return 0;
}
