#include <iostream>
#include <typeinfo>
#include <list>

using namespace std;

// ====================================================================================
// Type Definition - Struct version

/**
 * Node of a Binary Search Tree
 *
 */
struct Node{
    int key;
    Node* p; // This might not be used sometimes
    Node* left;
    Node* right;

    Node(int val, Node* parent = nullptr, Node* sx = nullptr, Node* dx = nullptr)
            : key{val}, p{parent}, left{sx}, right{dx}{}
};

typedef Node* PNode;

/**
 * Binary Search Tree
 *
 */
struct Tree{
    PNode root;

    Tree(PNode r = nullptr)
            : root{r} {}
};

typedef Tree* PTree;

/**
 * NodeList
 *
 */
struct NodeList{
    PNode head;
    NodeList * queue;
    NodeList(PNode first = nullptr, NodeList *next = nullptr)
            :head{first}, queue{next} {}
};
typedef NodeList * PNodeList;

// ====================================================================================
// Base Data Type functions

bool treeEmpty(PTree t){
    return t->root == nullptr;
}

PNode newNode(int k){
    PNode node = new Node(k);
    return node;
}

PTree newTree(PNode r){
    PTree tree = new Tree(r);
    return tree;
}

Node parent(PTree t, PNode u){
}

list<Node> children(PTree t, PNode u){
}


// ====================================================================================
// Util functions


// ======================================================================
// Visits

void preOrderVisit(PTree t){

}

void postOrderVisit(PTree t){

}

void symmetricVisit(PTree t){

}

void breadFirstSearchVisit(PTree t){

}


// ====================================================================================
// Test Trees - key k (int)


// ====================================================================================
// Exercises

int treeHeight(PTree t){

}

int nodeHeight(PTree t, PNode u){

}

int nodeDepth(PTree t, PNode u){

}

int lengthPath(PTree t, PNode u, PNode v){

}

PTree inducedSubTree(PTree t, PNode u){

}

void neighborhood(PTree t, PNode u){

}

void search(PTree t, int key){

}

void nodeDelete(PTree t, PNode u){

}

// Removes all keys greater than k, in a BST with distinct integer keys
void nodeRemove(PTree t, PNode z, int k){
}

// ====================================================================================
// Main

int main() {

    return 0;
}