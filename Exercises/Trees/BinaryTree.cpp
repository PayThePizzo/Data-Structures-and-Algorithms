//
// Created by PayThePizzo on 3/27/2023.
//

#include <iostream>
#include <list>

using namespace std;

struct Node{
    int key;
    Node* p;
    Node* left;
    Node* right;

    Node(int val, Node* parent = nullptr, Node* sx = nullptr, Node* dx = nullptr)
            : key{val}, p{parent}, left{sx}, right{dx}{}
};

typedef Node* PNode;

struct Tree{
    PNode root;

    Tree(PNode r = nullptr)
            : root{r} {}
};

typedef Tree* PTree;

// Initialization

PNode NewNode(int k){
    PNode node = new Node(k);
    return node;
}

PTree NewTree(PNode r){
    PTree tree = new Tree(r);
    return tree;
}

bool TreeEmpty(PTree t){
    return t->root == nullptr;
}

Node parent(PTree t, PNode u){
}

list<Node> children(PTree t, PNode u){
}

void PreOrderVisit(PTree t){

}

void PostOrderVisit(PTree t){

}

void InOrderVisit(PTree t){

}

void BFSVisit(PTree t){

}

int TreeHeight(PTree t){

}

int NodeHeight(PTree t, PNode u){

}

int NodeDepth(PTree t, PNode u){

}

int LengthPath(PTree t, PNode u, PNode v){

}

PTree InducedSubTree(PTree t, PNode u){

}

void Neighborhood(PTree t, PNode u){

}

void Search(PTree t, int key){

}

void Delete(PTree t, PNode u){

}

// Test Tree

PTree TestTree1(){

}

PTree TestTree2(){

}

PTree TestTree3(){

}

// Main function
int main() {
    PNode u = NewNode(4);
    PTree t = NewTree(u);

    return 0;
}