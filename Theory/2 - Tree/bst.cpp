//
// Created by PayThePizzo on 3/22/2023.
//

// https://www.geeksforgeeks.org/remove-bst-keys-in-a-given-range/
// C++ implementation of the above approach
#include <bits/stdc++.h>

using namespace std;

class BSTnode {
public:
    int data;
    BSTnode *left, *right;
    BSTnode(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

// A Utility function to find leftMost node
BSTnode* leftMost(BSTnode* root)
{
    while (root->left != NULL)
        root = root->left;
    return root;
}

// A Utility function to delete the given node
BSTnode* deleteNode(BSTnode* root)
{
    // node with only one child or no child
    if (!root->left) {
        BSTnode* child = root->right;
        root = NULL;
        return child;
    }
    else if (!root->right) {
        BSTnode* child = root->left;
        root = NULL;
        return child;
    }

    // node with two children: get inorder successor
    // in the right subtree
    BSTnode* next = leftMost(root->right);

    // copy the inorder successor's content to this node
    root->data = next->data;

    // delete the inorder successor
    root->right = deleteNode(root->right);

    return root;
}

BSTnode* removeIfLEQ(BSTnode* node, int k){
    // Base case
    if (!node)
        return NULL;

    // First fix the left and right subtrees of node
    node->left = removeIfLEQ(node->left, k);
    node->right = removeIfLEQ(node->right, k);

    if (node->data <k)
        return deleteNode(node);

    // Root is out of range
    return node;
}

// function to find node in given range and delete
// it in preorder manner
BSTnode* removeRange(BSTnode* node, int low, int high)
{

    // Base case
    if (!node)
        return NULL;

    // First fix the left and right subtrees of node
    node->left = removeRange(node->left, low, high);
    node->right = removeRange(node->right, low, high);

    // Now fix the node.
    // if given node is in Range then delete it
    if (node->data >= low && node->data <= high)
        return deleteNode(node);

    // Root is out of range
    return node;
}

// Utility function to traverse the binary tree
// after conversion
void inorder(BSTnode* root)
{
    if (root) {
        inorder(root->left);
        cout << root->data << ' ';
        inorder(root->right);
    }
}

// Driver Program to test above functions
int main()
{
    /* Let us create following BST
             50
          /     \
         30      70
        /  \    /  \
      20   40  60   80 */
    BSTnode* root = new BSTnode(50);
    root->left = new BSTnode(30);
    root->right = new BSTnode(70);
    root->left->right = new BSTnode(40);
    root->right->right = new BSTnode(80);
    root->right->left = new BSTnode(60);
    root->left->left = new BSTnode(20);

    cout << "Inorder Before deletion: ";
    inorder(root);

    root = removeIfLEQ(root, 75);

    cout << "\nInorder After deletion: ";
    inorder(root);

    cout << endl;
    return 0;
}