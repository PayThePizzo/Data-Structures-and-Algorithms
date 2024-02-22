#include <iostream>
#include <typeinfo>
#include "vector"

using namespace std;

// ====================================================================================
// Type Definition - Struct version


/**
 * Left-Child Right-Sibling General Tree Node.
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
    NodeG(int k = 0, char c = 'U', NodeG* sx = nullptr, NodeG* dx = nullptr)
            : key{k}, col{c}, left_child{sx}, right_sib{dx} {}

    // No Default constructor needed
};

typedef NodeG* PNodeG;

// ====================================================================================
// Base Data Type functions

/**
 * Return pointer to a newly-constructed LCRS-Tree Node, with the indicated values.
 *
 * @param k integer value
 * @param c char value
 * @return a pointer of the type `struct NodeG*` or `PNodeG`
 */
struct NodeG* newTree(int k, char c){
    return new NodeG(k,c);
}

// ====================================================================================
// Util functions

/**
 * Insert node as left child
 *
 * @param r current node
 * @param c child node
 */
void insertLeft(PNodeG r, PNodeG c){
    r->left_child = c;
}

/**
 * Insert node as right sibling
 *
 * @param r current node
 * @param s sibling node
 */
void insertRight(PNodeG r, PNodeG s){
    r->right_sib = s;
}

//void insert_left_child(PNodeG tree, int key){
//    if(tree != nullptr){
//        if(tree->left_child != nullptr){
//            insert_left_child(tree, key);
//        }else{
//            PNodeG left = newTree2(key);
//            tree->left_child = left;
//        }
//    }
//}
//
//void insert_right_sibling(PNodeG tree, int key){
//    if(tree != nullptr){
//        if(tree->right_sib != nullptr){
//            insert_right_sibling(tree->right_sib, key);
//        }else{
//            PNodeG right = newTree2(key);
//            tree->right_sib = right;
//        }
//    }
//}

/**
 * Append a node as last child of current node.
 *
 * The new child node will be r->left_child, if there is no left-child.
 * Else, it will be inserted as the last sibling of the r->left_child.
 *
 * @param r current node
 * @param c child node to be appended
 */
void appendChild(PNodeG r, PNodeG c){
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


// Constructs and k-ary tree from a vector
struct NodeG* kAryTree(int k, vector<int> arr){

}


// Constructs and k-ary complete tree from a vector
struct NodeG* kAryCompleteTree(int k, vector<int> arr){

}


// ====================================================================================
// Visits

void preOrderVisit(PNodeG r){
}

void postOrderVisit(){

}

void symmetricVisit(){

}

void breadFirstSearchVisit(){

}

// ====================================================================================
// Test Trees - key k (int)

struct NodeG* testTree1(){
}


// ====================================================================================
// Test Trees - key col (char)


// ====================================================================================
// Exercises

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


int countLeaves(PNodeG r){
    return 0;
}


int countLeavesLCRS(PNodeG r){
    int l = 0;
    PNodeG figlio;

    // Empty tree
    if(r == nullptr){
        return 0;
    }

    // Not empty
    figlio = r->left_child;

    while(figlio){
        // Sum siblings leaves
        l+= countLeavesLCRS(figlio);
        figlio = figlio->right_sib;
    }

    return (r->left_child == nullptr) ? l+1 : l;
}

// Theta(n)
// Preorder Visit on the general tree to verify the existential property of being a leaf
// As we have a general tree, we must iterate through all the nodes to find out whether each node
// is a leaf.
// We must check each node to get our final answer as at any point, a node could be a leaf.
// Thus, be covering the tree exactly once, we perform a Preorder Visit of complexity T(n) = O(n).
int count_leaves(PNodeG tree){
    if(tree == nullptr){
        return 0;
    }else{
        if(tree->left_child== nullptr){
            return 1 + count_leaves(tree->right_sib);
        }else{
            return count_leaves(tree->left_child) + count_leaves(tree->right_sib);
        }
    }
}


int blackHeightLCRS(PNodeG root){
    return 0;
}


bool kCompleteLCRS(PNodeG root, int k){

    return false;
}


bool isNonDec(PNodeG r){
    // Base case
    if(r == nullptr)
        return true;

    // Prove for child if sibling is not there
    if(r->right_sib == nullptr)
        return isNonDec(r->left_child);

    // Prove for the current node, prove for sibling and child of current node
    return (r->key <= r->right_sib->key) && isNonDec(r->right_sib) && isNonDec(r->left_child);
}


/**
 *  Un albero binario si dice t-bilanciato se per ogni suo nodo vale la proprieta':
 *  le altezze dei sottoalberi radicati nei suoi figli differiscono per al piu' t unita'.
 *
 *  1. Dato un albero binario, scrivere una funzione EFFICIENTE che restituisca il
 *      minimo valore t per cui l' albero risulti t-bilanciato.
 *  2. Discutere la complessita' della soluzione trovata.
 * @param u PNode, nodo dell'albero
 * @return t, intero che rappresenta il minimo valore di bilanciamento.
 */
int tBil(PNodeG u){

}

// ====================================================================================
// Main

int main() {
    return 0;
}