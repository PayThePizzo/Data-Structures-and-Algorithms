#include <iostream>
#include <typeinfo>
#include "vector"

using namespace std;

/**
 * LCRS-Tree Node Implementation.
 *
 * This struct represent the implementation of node for the data structure Left-Child Right-Sibling General Tree.
 * Each node has a integer `key` field, a char `col` field, a pointer `left_child` and a pointer `right_sib`.
 *
 */
struct NodeG{
    int key; // Defaults -1 if it is not considered for the problem
    char col; // Defaults to 'U' if it is not considered for the problem
    NodeG* left_child; // Pointer to Left-Child
    NodeG* right_sib; // Pointer to Right-Sibling

    /**
     * Constructor of a LCRS-Tree Node
     *
     * @param k int field of the node, defaults to `0`
     * @param c char field of the node, defaults to `U`
     * @param sx pointer to left-child, defaults to `nullptr`
     * @param dx pointer to right-sibling, defaults to `nullptr`
     */
    NodeG(int k = 0, char c = 'U', NodeG* sx = nullptr, NodeG* dx = nullptr) : key{k}, col{c}, left_child{sx}, right_sib{dx} {
    }

    // No Default constructor needed
};

typedef NodeG* PNodeG;

// ====================================================================================
// Constructor
/**
 * Return pointer to a newly-constructed LCRS-Tree Node, with the indicated values.
 *
 * @param k integer value
 * @param c char value
 * @return a pointer of the type `struct NodeG*` or `PNodeG`
 */
struct NodeG* new_tree(int k, char c){
    return new NodeG(k,c);
}


/**
 * Insert node as left child
 *
 * @param r current node
 * @param c child node
 */
void insert_left(PNodeG r, PNodeG c){
    r->left_child = c;
}


/**
 * Insert node as right sibling
 *
 * @param r current node
 * @param s sibling node
 */
void insert_right(PNodeG r, PNodeG s){
    r->right_sib = s;
}

/**
 * Append a node as last child of current node.
 *
 * The new child node will be r->left_child, if there is no left-child.
 * Else, it will be inserted as the last sibling of the r->left_child.
 *
 * @param r current node
 * @param c child node to be appended
 */
void append_child(PNodeG r, PNodeG c){
    // No child
    if(r->left_child == nullptr){
        r->left_child = c;
    }else{
        // At least one child
        PNodeG current_child = r->left_child;
        // Go right until we reach the end of the siblings
        while(current_child->right_sib != nullptr){
            current_child = r->right_sib;
        }
        // Add a sibling to the last child
        current_child->right_sib = c;
    }
}


// Constructs and an-ary tree from a vector
struct NodeG* new_n_ary_tree(int n, vector<int> arr){

}


// Constructs and an-ary complete tree from a vector
struct NodeG* new_n_ary_complete_tree(int n, vector<int> arr){

}

// ====================================================================================
// Test
struct NodeG* test_tree1(){
    NodeG* a = new_tree(1, 'A');
    NodeG* b = new_tree(2, 'B');
    NodeG* c = new_tree(3, 'C');
    NodeG* d = new_tree(4, 'D');
    NodeG* e = new_tree(5, 'E');
    NodeG* f = new_tree(6, 'F');
    NodeG* g = new_tree(7, 'G');
    NodeG* h = new_tree(8, 'H');

    PNodeG root = a;
    root->left_child = b;
    root->left_child->right_sib = c;
    root->left_child->right_sib->left_child = d;
    root->left_child->right_sib->right_sib = e;
    root->left_child->left_child = f;
    root->left_child->right_sib->left_child->left_child=g;
    root->left_child->right_sib->left_child->right_sib=h;

    return root;
}

// ====================================================================================
// Visits

void pre_order_visit(){

}

void post_order_visit(){

}

void symmetric_visit(){

}

void bfs_visit(){

}

// ====================================================================================
// Functions

// Maximum key value among all nodes
int maximum_key(){

}

// Minimum key value among all nodes
int minimum_key(){

}

// Avg key value among all nodes
int average_key(){

}

// Mode key value among all nodes
int mode_key(){

}

//
int sum_keys(){

}


// Number of keys that only occur once
int unique_keys(){

}


bool has_even_nodes(){

}


int tree_height_aux(PNodeG root){
    //base case
    if(root == nullptr)
        return -1;

    // left
    int left_h = tree_height_aux(root->left_child);
    // right
    int right_h = tree_height_aux(root->right_sib);
    // extra condition

    // combine
    return max(left_h, right_h);
}

int tree_height(PNodeG root){
    int h = -1;

}

// ====================================================================================
// Main function

int main() {
    return 0;
}