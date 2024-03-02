#include <iostream>
#include <typeinfo>
#include "list"

using namespace std;

// ====================================================================================
// Template function documentation
// This is used to document the functions extensively
// FIXME: graphic documentation is not well defined (check function signature).
/**
 * What the function does (briefly).
 *
 * Longer description and details of what it does.
 *
 * @pre
 *      Pre-Condition:
 *      - Assumptions of the passed parameters.
 *      - Conditions needed for the function to work.
 * @post
 *      Post-Condition:
 *      - Cases for what the outcomes might be.
 * @time
 *      Worst Time Complexity Analysis:
 *      - What does n stand for (ex: if we are using trees -> n = #nodes).
 *      - How it is computed (ex: Master Theorem).
 *      - Explanation of worst cases under these assumptions
 * @space
 *      Worst Space Complexity Analysis: /
 *      - What does n stand for (ex: if we are using trees -> n = #nodes).
 *      - How it is computed (ex: Master Theorem).
 *      - Explanation of worst cases under these assumptions
 *
 * @param type and what it stands for logically
 * @return What it returns for each case
 */
int example_foo(int c){
    c++;
    return c;
}

// ====================================================================================
// Type Definition - Struct version

/**
 * Binary Tree Node
 *
 */
struct Node {
    int key;
    char col;
    Node *p;
    Node *left;
    Node *right;

    Node(int k = 0, char c = 'U', Node *parent = nullptr, Node *sx = nullptr, Node *dx = nullptr)
            : key{k}, col{c}, p{parent}, left{sx}, right{dx} {}
};

typedef Node *PNode;

// ====================================================================================
// Base Data Type functions


/**
 * Return an empty new tree.
 *
 * It returns a root node with the passed key parameters
 *
 * @pre
 *      Pre-Condition:
 * @post
 *      Post-Condition:
 * @time
 *      Worst Time Complexity Analysis:
 * @space
 *      Worst Space Complexity Analysis:
 * @param key integer key
 * @param col char key
 * @return Empty tree
 */
PNode newTree(int key = 0, char col = 'U') {
    return new Node(key, col);
}

/**
 * Test whether the given tree is empty or not.
 *
 * @param t
 * @return
 */
bool treeEmpty(PNode t) {
    return (t == nullptr);
}


PNode parent(PNode t, PNode v){
    return v->p;
}

// If the v->p does not exist (namely we assume not to have the pointer here)
PNode parent_v2(PNode t, PNode v){
    return nullptr;
}

// Children


// ====================================================================================
// Util functions

void insertLeft(PNode t, PNode l) {
    if (t != nullptr && l != nullptr)
        t->left = l;
}

void insertRight(PNode t, PNode r) {
    if (t != nullptr && r != nullptr)
        t->right = r;
}

// ====================================================================================
// Visits

void preOrderVisit(PNode t){
}

void symmetricVisit(PNode t){
}

void postOrderVisit(PNode t){
}

void breadFirstSearchVisit(PNode t){
}


// ====================================================================================
// Test Trees - key k (int)


// ====================================================================================
// Test Trees - key col (char)


// ====================================================================================
// Exercises

std::pair<int, bool> k_compreso_aux(PNode t, int k, int sum){
    if(t == nullptr){
        std::pair<int,bool> p = {0, true};
        return p;
    }else{
        std::pair<int, bool> left = k_compreso_aux(t->left,  k, sum);
        std::pair<int, bool> right = k_compreso_aux(t->right, k, sum);
        int total = t->key + left.first + right.first;

        if((total >= -k && total <= k) && (left.second && right.second)){
            std::pair<int,bool> p = {total, true};
            return p;
        }else{
            std::pair<int,bool> p = {total, false};
            return p;
        }
    }

}

int k_compreso(PNode t, int k){
    if(t == nullptr){
        return 0;
    }else{
        return k_compreso_aux(t, k, 0).second ? 1 : 0 ;
    }
}

int gradosquil_aux(PNode t){
    if(t == nullptr){
        return 0;
    }else{
        int l = gradosquil_aux(t->left);
        int r = gradosquil_aux(t->right);
        int grado = abs(l-r);
    }
    return 0;
}

int gradosquil(PNode t){
    if (t== nullptr){
        return 0;
    }else{
        return gradosquil_aux(t);
    }
}

int gradosquil_aux(Node *root, int *max_gs){
    if(!root){
        return 0;
    }else{
        if(!root->left && !root->right){
            return root->key;
        }else {
            int gsn = abs(gradosquil_aux(root->left, max_gs)- gradosquil_aux(root->right, max_gs));
            if(gsn > *max_gs){
                *max_gs = gsn;
            }
            return gsn;
        }
    }
}

int gradosquil_tree(Node *root){
    int max = 0;
    return gradosquil_aux(root, &max);
}

// ====================================================================================
// Main

// g++ -std=c++14 --pedantic -Wall -o BST main_es1.cpp
// 

int main() {
    // Empty Tree
    PNode empty_tree = newTree();

    // Simple Binary Tree
    PNode tree1 = newTree();
    PNode left_node = newTree(1, 'U');
    PNode right_node = newTree(2, 'U');
    insertLeft(tree1, left_node);
    insertRight(tree1, right_node);

    cout << "root" << endl;
    cout << tree1->key << endl;
    cout << "left" << endl;
    cout << tree1->left->key << endl;
    cout << "right" << endl;
    cout << tree1->right->key << endl;

    return 0;
}