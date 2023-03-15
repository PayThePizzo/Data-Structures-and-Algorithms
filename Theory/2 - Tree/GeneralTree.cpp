//
// Created by PayThePizzo on 3/15/2023.
//

#include "GeneralTree.h"

using namespace std;

general_tree::PNode general_tree::newTree(int key) {
    general_tree::PNode t;
    t->p = nullptr;
    t->right = nullptr;
    t->left = nullptr;
    t->key = key;
    return t;
}

bool general_tree::treeEmpty(PNode t) {
    return t == nullptr;
}

void general_tree::insert_left(PNode t, int key) {
    if(t != nullptr) {
        general_tree::PNode left_node = newTree(key);
        left_node->p = t;
        t->left = left_node;
    }
}

void general_tree::insert_right(PNode t, int key) {
    if(t != nullptr) {
        general_tree::PNode right_node = newTree(key);
        right_node->p = t;
        t->right = right_node;
    }
}

general_tree::PNode general_tree::parent(PNode t) {
    return t->p;
}

std::list<general_tree::PNode> general_tree::children(PNode t) {
    std::list<general_tree::PNode> children;
}

void general_tree::printTree(PNode t){

}

int main ()
{
    cout << "Salve gente! ";
    return 0;
}