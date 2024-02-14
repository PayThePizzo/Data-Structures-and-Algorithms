#include <iostream>
#include "vector"

using namespace std;

// ---------------------------------------------------------------
// No parent link
struct Node{
    int key;
    char col;
    Node* left;
    Node* right;
    Node(int k, char c = 'U', Node* sx = nullptr, Node* dx = nullptr)
            : key{k}, col{c}, left{sx}, right{dx} {}
};

typedef Node* PNode;

// ----------------------------------------------------------------

// Left Child - Right Sibling
struct NodeG{
    int key;
    char col;
    NodeG* left_child;
    NodeG* right_sib;
    NodeG(int k, char c = 'U', NodeG* sx = nullptr, NodeG* dx = nullptr)
            : key{k}, col{c}, left_child{sx}, right_sib{dx} {}
};

typedef NodeG* PNodeG;

// ------------------------------------------------------------------
// Initializer Functions pt 1

// New Tree

// Insert Left

// Insert Right

// ------------------------------------------------------------------

// Initializer Functions pt 2

// New Tree

struct NodeG* new_tree(int k, char c){
    return new NodeG(k,c);
}



// Insert Left

void insert_left(PNodeG r, PNodeG c){
    r->left_child = c;
}

// Insert Right

void insert_right(PNodeG r, PNodeG s){
    r->right_sib = s;
}



// ------------------------------------------------------------------

// Print Test Functions

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

// ------------------------------------------------------------------

int countLeaves(PNode r){
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
int tBil(PNode u){

}


// Main function
int main() {

    cout << countLeavesLCRS(test_tree1()) << endl;

    return 0;
}
