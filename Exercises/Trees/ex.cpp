//
// Created by PayThePizzo on 9/7/2022.
//

/// Binary Tree and BST C++
// Binary Tree only include PNode, while BST also include PTree
struct Node{
    int key;
    Node* p;
    Node* left;
    Node* right;
    Node(int k, Node* padre = nullptr, Node* sx = nullptr, Node* dx =nullptr)
            : key{k}, p{padre}, left{sx}, right{dx} {}
};
typedef Node* PNode;

struct Tree {
    PNode root;
    Tree(PNode radix = nullptr)
            : root(radix) {}
};
typedef Tree* PTree;

struct NodeList{
    PNode head;
    NodeList * queue;
    NodeList(PNode first = nullptr, NodeList *next = nullptr)
            : head(first){} , queue(next){}
};
typedef NodeList * PNodeList;

/// Returns a new Tree
PTree newTree(){

}

/// Returns true if empty, else false
bool treeEmpty(PTree t){

}

/// Returns father
void father(PTree t, PNode u){

}

/// Returns list of children
PNodeList children(){

}


//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

/// BT with LeftChild-RightSibling
struct NodeG{
    int key;
    NodeG* left_child;
    NodeG* right_sib;
    NodeG(int k, NodeG* lc = nullptr, NodeG* rs = nullptr)
            : key{k}, left_child{lc}, right_sib{rs} {}
};
typedef NodeG* PNodeG;




// Exercises ++++++++++++++++++++++++++++++++++++++++++++++++++++++

// Removes all keys greater than k, in a BST with distinct integer keys
void remove(PTree t, PNode z, int k){
    if(){

    }
}