//
// Created by PayThePizzo on 3/15/2023.
//

#ifndef ASD_GENERALTREE_H
#define ASD_GENERALTREE_H
#include "iostream"
#include "list"


namespace general_tree{

    // General Tree
    struct Node {
        int key;
        Node *p;
        Node *left;
        Node *right;

        Node(int k, Node *p = nullptr, Node *sx = nullptr, Node *dx = nullptr)
                : key{k}, left{sx}, right{dx} {}
    };

    typedef general_tree::Node *PNode;

    PNode newTree(int key);

    void insert_left(PNode t, int key);

    void insert_right(PNode t, int key);

    bool treeEmpty(PNode t);

    PNode parent(PNode t);

    std::list<PNode> children(PNode t);

    void printTree(PNode t);
}



namespace leftchild_rightsibling{

    // Left Child Right Sibling
    struct NodeG{
        int key;
        NodeG* p;
        NodeG* left_child;
        NodeG* right_sib;
        NodeG(int k, NodeG *p = nullptr, NodeG* sx = nullptr, NodeG* dx = nullptr)
                : key{k}, left_child{sx}, right_sib{dx} {}
    };

    typedef NodeG* PNodeG;

    PNodeG newTree();

    void insert_child(PNodeG t);

    void insert_sibling(PNodeG t);

    bool treeEmpty(PNodeG t);

    PNodeG parent(PNodeG t);

    std::list<PNodeG> children(PNodeG t);

    void printTree(PNodeG t);

}


#endif //ASD_GENERALTREE_H
