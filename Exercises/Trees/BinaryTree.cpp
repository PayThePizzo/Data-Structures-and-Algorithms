//
// Created by PayThePizzo on 3/27/2023.
//

#include <iostream>
#include <list>

using namespace std;

struct NodeB{
    int key; //Might change of type
    NodeB* p; //Might not be included
    NodeB* left;
    NodeB* right;

    NodeB(int val, NodeB* parent = nullptr, NodeB* sx = nullptr, NodeB* dx = nullptr)
            : key{val}, p{parent}, left{sx}, right{dx}{}
};

typedef NodeB* PNodeB;

struct Tree{
    PNodeB root;

    Tree(PNodeB r = nullptr): root{r} {}
};

typedef Tree* PTree;

PNodeB NewNode(int k){
    PNodeB node = new NodeB(k);
    return node;
}

PTree NewTree(PNodeB r){
    PTree tree = new Tree(r);
    return tree;
}

bool TreeEmpty(PTree t){
    return t->root == nullptr;
}

NodeB parent(PTree t, PNodeB u){
}

list<NodeB> children(PTree t, PNodeB u){
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

int NodeHeight(PTree t, PNodeB u){

}

int NodeDepth(PTree t, PNodeB u){

}

int LengthPath(PTree t, PNodeB u, PNodeB v){

}

PTree InducedSubTree(PTree t, PNodeB u){

}

void Neighborhood(PTree t, PNodeB u){

}

void Search(PTree t, int key){

}

void Delete(PTree t, PNodeB u){

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
    PNodeB u = NewNode(4);
    PTree t = NewTree(u);

    return 0;
}