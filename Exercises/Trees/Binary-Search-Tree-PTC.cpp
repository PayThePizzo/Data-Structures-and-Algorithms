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
// Tree Operations

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

PNode parent(PTree t, PNode u){
    return t->root == u ? nullptr : u->p;
}

list<Node> children(PTree t, PNode u){
}


// ====================================================================================
// Dictionary Operations

/**
 * Search a key inside a BST and return the first corresponding node.
 * 
 * @note Recursive version.
 *      Pre-Condition: 
 *          - `None`
 *      Post-Condition:
 *          - Return a node `v` with `v->key == k` if it exists inside the BST with root in `u`. Else, return`NIL`
 *      Worst Time Complexity Analysis:`O(h)`, where `h` is the height of the BST.
 *          - The nodes encountered through the recursion create a path starting from the root and proceeding downard. The 
 *          worst case corresponds to the length of the longest path, which depends on whether the tree is balanced or not.
 *      Worst Space Complexity Analysis: O(1), No external data structure used.
 * 
 * @param u node of the BST, usually the root
 * @param k integer key 
 * @return `PNode v` if there is a node `v->key == k`, else `nullptr`
*/
PNode searchRec(PNode u, int k){
    // Base case: No match
    if(u == nullptr || u->key == k){
        return u;
    }else{
        if(u->key < k){
            return searchRec(u->right, k);
        }else{
            return searchRec(u->left, k);
        }
    }
}


/**
 * Search a key inside a BST and return the first corresponding node.
 * 
 * @note Iterative version.
 *      Pre-Condition: 
 *          - `None`
 *      Post-Condition:
 *          - Return a node `v` with `v->key == k` if it exists inside the BST with root in `u`. Else, return`NIL`
 *      Worst Time Complexity Analysis:`O(h)`, where `h` is the height of the BST.
 *          - The nodes encountered through the iteration create a path starting from the root and proceeding downard. The 
 *          worst case corresponds to the length of the longest path, which depends on whether the tree is balanced or not.
 *          
 *      Worst Space Complexity Analysis: O(1), No external data structure used.
 * 
 * @param u node of the BST, usually the root
 * @param k integer key 
 * @return `PNode v` if there is a node `v->key == k`, else `nullptr`
*/
PNode searchIter(PNode u, int k){
    while(u != nullptr && u->key != k){
        if(u->key < k){
            u = u->right;
        }else{
            u = u->left;
        }
    }
    return u;
}


PNode minimum(PNode u){
    while(u->left != nullptr){
        u = u->left;
    }
    return u;
}


PNode maximum(PNode u){
    while(u->right != nullptr){
        u = u->right;
    }
    return u;
}

// Predecessor and Successor (with regards to the symmetric visit)

PNode predecessor(PNode u){
    if(u->left != nullptr){
        return maximum(u->left);
    }

    PNode y = u->p;
    while(y != nullptr && y->left == u){
        u = y;
        y = u->p;
    }

    return y;
}


PNode successor(PNode u){
    if(u->right != nullptr){
        return minimum(u->right);
    }

    PNode y = u->p;
    while(y != nullptr && y->right == u){
        u = y;
        y = u->p;
    }

    return y;
}


void insert(PTree t, PNode z){
    // Keep track of parent
    PNode y = nullptr; 
    // Node used to iterate
    PNode x = t->root;
    
    // Iterate to get to the leaves and keep track
    // of parent 
    while(x != nullptr){
        // Update parent
        y = x;
        // Choose direction
        if(z->key < x->key){
            x = x->left;
        }else{
            x = x->right;
        }
    }
    // Set parent for new node
    z->p = y;

    if(y == nullptr){
        // If Tree is empty z is new root
        t->root = z;
    }else{
        // If y points to an existing node
        // set it according to value
        if(z->key < y->key){
            y->left = z;
        }else{
            y->right = z;
        }
    }
}

void transplant(){

}

void treeDelete(){

}


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

void nodeDelete(PTree t, PNode u){

}

// Removes all keys greater than k, in a BST with distinct integer keys
void nodeRemoveGreater(PTree t, PNode z, int k){
}


void nodeRemoveSmaller(PTree t, PNode z, int k){
}


bool isBST(PTree t){
}

PTree Modify_key(PTree t, PNode x, int key){
}

// ====================================================================================
// Main

int main() {

    return 0;
}