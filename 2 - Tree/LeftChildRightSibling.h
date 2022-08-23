//
// Created by PayThePizzo on 8/23/2022.
//

#ifndef ASD_LEFTCHILDRIGHTSIBLING_H
#define ASD_LEFTCHILDRIGHTSIBLING_H
#include <iostream>

namespace binaryleftchildrightsiblingtree{

    typedef struct Tree{
        int key;
        struct Tree *left_c;
        struct Tree *right_s;
        struct Tree *p;
    } Tree;

    /**
     * Returns a binarized LeftChildRightSibling new tree
     *
     * @param A
     * @return
     */
    Tree* newTree(int info);

    bool treeEmpty(Tree* tree);

    void insert(Tree* tree, Tree* node);

    void parent(Tree tree, Tree Node);

    void children(Tree tree, Tree node);

    void depthfirstsearch(Tree tree);

    void symmetric_visit(Tree tree);

    void post_order_visit(Tree tree);

    void breadfirstsearch(Tree tree);

    void print_tree(Tree* root);

}

namespace genericbinarytree{

    typedef struct Tree{
        int key;
        struct LeftChildRightSibling *left;
        struct LeftChildRightSibling *right;
        struct LeftChildRightSibling *p;
    } Tree;

    Tree* newTree(int info);

    void insert(Tree* tree, Tree* node);

    void parent(Tree* tree, Tree* Node);

    void children(Tree* tree, Tree* node);

    void depthfirstsearch(Tree* tree);

    void symmetric_visit(Tree* tree);

    void post_order_visit(Tree* tree);

    void breadfirstsearch(Tree* tree);

    void print_tree(Tree* root);
}

namespace binarysearchtree{


}

int main(){

}
#endif //ASD_LEFTCHILDRIGHTSIBLING_H
