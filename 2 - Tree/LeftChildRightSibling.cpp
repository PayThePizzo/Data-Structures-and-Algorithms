//
// Created by PayThePizzo on 8/23/2022.
//

#include "LeftChildRightSibling.h"
#include <iostream>

using namespace binlcrs;

LeftChildRightSibling* newTree(int info){
    //Allocation
    LeftChildRightSibling *root = (LeftChildRightSibling*)malloc(sizeof (LeftChildRightSibling));
    root->key=info;
    root->p = nullptr;
    root->left_c = nullptr;
    root->right_s = nullptr;
    return root;
}

bool treeEmpty(LeftChildRightSibling* tree){
    return (tree == nullptr);
}

void insert(LeftChildRightSibling* tree, LeftChildRightSibling* node){
    if(tree != nullptr && node != nullptr){
        LeftChildRightSibling iter = tree->left_c;
        while(iter != nullptr){
            iter = iter->right_s;
        }
        iter = node;
    }
    return;
}


LeftChildRightSibling parent(LeftChildRightSibling tree, LeftChildRightSibling node){
    return *Node.p;
}

void children(LeftChildRightSibling tree, LeftChildRightSibling node){

}

void depthfirstsearch(LeftChildRightSibling tree){

}

void symmetric_visit(LeftChildRightSibling tree){

}

void post_order_visit(LeftChildRightSibling tree){

}

void breadfirstsearch(LeftChildRightSibling tree){

}

void print_tree(LeftChildRightSibling* root){

}
