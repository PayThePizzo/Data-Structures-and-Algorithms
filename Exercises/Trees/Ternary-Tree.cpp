#include <iostream>
#include <typeinfo>

using namespace std;

// General Tree Node
struct GNode {
    int key;
    GNode *left_child;
    GNode *right_sibling;

    GNode(int k = 0, GNode *sx = nullptr, GNode *dx = nullptr)
            : key{k}, left_child{sx}, right_sibling{dx} {}
};

typedef GNode *PGNode;

// Binary Tree Node
struct Node {
    int key;
    Node *left;
    Node *right;

    Node(int k = 0, Node *sx = nullptr, Node *dx = nullptr)
            : key{k}, left{sx}, right{dx} {}
};

typedef Node *PNode;

// Ternary Tree Node
struct TNode {
    int key;
    bool fruitful;
    TNode *left;
    TNode *center;
    TNode *right;

    TNode(int k = 0, bool f = false, TNode *sx = nullptr, TNode *cx = nullptr, TNode *dx = nullptr)
            : key{k}, fruitful{f}, left{sx}, center{cx}, right{dx} {}
};

typedef TNode *PTNode;

// ================================================================================================
// Esame 26/01/12, Parte 2, Esercizio 1
//
// (1)  Dato un albero binario con chiavi intere positive e negative, progettare un algoritmo efficiente che
//      restituisca la somma totale di tutte le chiavi dell'albero.
//
// (2)  Definire un secondo algoritmo, anch'esso efficiente, che restituisca il massimo peso di tutti i sottoalberi,
//      dove il peso di un sottoalbero è la somma di tutte le chiavi dei suoi nodi.
// 
// (3)  Valutare la complessità dei due algoritmi.
//
// La rappresentazione dell’albero binario utilizza esclusivamente i campi left, right e key.
// T(n) = Theta(n)      dove n, e' il numero di nodi dell'albero radicato in t.
//                      Perche' visita ogni nodo esattamente una sola volta.

int sum_keys_binary_tree(PNode t){
    int left_sum, right_sum;

    // Base Case: Empty Tree
    if (t == nullptr){
        return 0;
    }

    // Recursive Calls
    left_sum = sum_keys_binary_tree(t->left);
    right_sum = sum_keys_binary_tree(t->right);

    // Recombine
    return left_sum + right_sum + t->key;
}

// T(n) = Theta(n)
int max_subtree_weight_aux(PNode t, int &max_weight, bool &initialized){
    int left_sum, right_sum, total_sum;

    // Base Case
    if (t == nullptr){
        return 0;
    }

    // Recursive Calls
    left_sum = max_subtree_weight_aux(t->left, max_weight, initialized);
    right_sum = max_subtree_weight_aux(t->right, max_weight, initialized);

    // Recombine
    total_sum = left_sum + right_sum + t->key;

    // First leaf sets the initial value of the max_weight
    // Since a leaf is a subtree of just one node with weight k
    if (initialized == false && t->left == nullptr && t->right == nullptr){
        max_weight = total_sum;
        initialized = true;
    }

    // Check max weight
    if (total_sum > max_weight){
        max_weight = total_sum;
    }

    return total_sum;
}

// T(n) = Thetan(n)
int max_subtree_weight(PNode t){
    // Max weight result
    int max_weight;

    // Guard to check whether the first initialization took place
    // Since we have both positive and negative values, we cannot
    // assign an arbitrary value, nor it is right to assign a MIN_INT
    // constant
    bool initialized = false;

    // Empty Tree
    if (t == nullptr){
        return 0;
    }

    // Find Max Weight Subtree
    max_subtree_weight_aux(t, max_weight, initialized);

    return max_weight;
}

// ================================================================================================
// Esame 15/05/12, Parte 2, Esercizio 1
//
// Un nodo di un albero binario è detto pari se il numero di foglie del sottoalbero di cui è radice è pari.
//      a. Progettare un algoritmo efficiente che dato un albero binario restituisca il numero di nodi pari. 
//      b. Discutere brevemente la complessità della soluzione trovata.
//
//  La rappresentazione dell’albero binario utilizza esclusivamente i campi left, right e key

// Un albero vuoto e' un albero senza nodi e senza foglie, percio' e' pari
// Un albero con sola radice e' un albero con 1 solo nodo ed e' esso stesso una foglia, percio' e'dispari.

// TODO: Capire se nel caso di un albero vuoto, lo consideriamo pari o meno.
// T(n) = Theta(n)
int pari_aux(PNode t, int &nump){
    int numfsx, numfdx, numf;

    // Base Case: Empty Tree
    if(t == nullptr){
        return 0;
    }

    // Base Case: Leaf
    // All 
    if(t->left == nullptr && t->right == nullptr){
        return 1;
    }

    // Recursive Call
    numfsx = pari_aux(t->left, nump);
    numfdx = pari_aux(t->right, nump);

    // Recombine
    numf = numfsx + numfdx;

    if(numf % 2 == 0){
        nump++;
    }

    return numf;
}

// T(n) = Theta(n)
int pari(PNode t){
    // Even Nodes
    int nump = 0;

    pari_aux(t, nump);

    return nump;
}

// ================================================================================================
// Esame 29/05/12, Parte 2, Esercizio 1
//
// Sia T un albero generico i cui nodi hanno chiavi intere e campi: key, left-child, right-sib. Scrivere 
// un algoritmo che calcoli l’altezza di tale albero. 
// Discutere brevemente la complessità della soluzione trovata.

int general_tree_height(PGNode u){
}

// ================================================================================================
// Esame 28/01/15, Parte 2, Esercizio 1
//
// Un nodo di un albero binario u è detto intermedio se la somma delle chiavi contenute nei nodi del sottoalbero 
// di cui u è radice è uguale alla somma delle chiavi contenute nei nodi sul percorso che collega u alla radice 
// dell’albero (u escluso).
// Scrivere un algoritmo efficiente che restituisca il numero di nodi intermedi. 

// Caso (1) in cui
// 1. Somma delle chiavi contenute nei nodi del sottoalbero di cui u è radice (U INCLUSO)
// 2. Somma delle chiavi contenute nei nodi sul percorso che collega u alla radice dell’albero (u ESCLUSO)
int intermedi_aux(PNode u, int &ris, int w){
    int left_sum, right_sum, tot_sum;

    // Base Case
    if (u == nullptr){
        return 0;
    }

    left_sum = intermedi_aux(u->left, ris, w+u->key);
    right_sum = intermedi_aux(u->right, ris, w+u->key);

    tot_sum = left_sum + right_sum;

    ris = (tot_sum == w) ? ris+1 : ris ;

    return tot_sum;
}

// Caso (2) in cui
// 1. Somma delle chiavi contenute nei nodi del sottoalbero di cui u è radice (U ESCLUSO)
// 2. Somma delle chiavi contenute nei nodi sul percorso che collega u alla radice dell’albero (u ESCLUSO)
int intermedi_aux2(PNode u, int &ris, int w){
    int left_sum, right_sum, tot_sum;

    // Base Case
    if (u == nullptr){
        return 0;
    }

    left_sum = intermedi_aux(u->left, ris, w+u->key);
    right_sum = intermedi_aux(u->right, ris, w+u->key);

    tot_sum = left_sum + right_sum;

    ris = (tot_sum == w) ? ris+1 : ris ;

    return tot_sum;
}


int intermedi(PNode u){
    // Total intermediate nodes
    int ris = 0;
    // Procedure
    intermedi_aux(u, ris, 0);

    return ris;
}

// ================================================================================================

// Esame 10/01/23, Parte 2, Esercizio 1

// Sia T un albero binario i cui nodi x hanno i campi left, right e key, dove key è un numero intero. 
// L’albero si dice k-compreso, per un certo numero naturale k, se per ogni nodo x la somma delle chiavi 
// dei nodi dell’albero radicato in x è compresa tra -k e k
// Scrivere una funzione efficiente in C o C++ k_compreso(u,k) che dato in input la radice 
// u di un albero T e un valore k verifica se T è k-compreso e ritorna 1 se T è k-compreso, 0
// altrimenti

int k_compreso_aux(PNode t, int k, bool &guard){
    int left_sum, right_sum, total_sum;

    // Base case: Non-Existing Node or Guard has been invalidated
    if (t == nullptr || guard == false){
        return 0;
    }

    // Post-Order Calls
    left_sum = k_compreso_aux(t->left, k, guard);
    right_sum = k_compreso_aux(t->right, k, guard);

    // Recombine
    total_sum = t->key + left_sum + right_sum; 

    // Guard check: Changes the value of guard to false when out of range
    // If guard is true check the universal condition, else just keep the value false
    guard = (guard ? (-k <= total_sum && total_sum <= k) : guard);

    // Recombine
    return total_sum;
}

int k_compreso(PNode t, int k){
    // Guard condition
    bool guard;

    // Empty Tree
    if(t == nullptr){
        return 1;
    }

    // True unless we have counter-example
    guard = true;

    // Look for counter example
    k_compreso_aux(t, k, guard);

    // True     if universal condition is respected
    // False,   else
    return guard ? 1 : 0;
}


/*
    Input :         1 
*/
PNode test_binary_tree0(){
    PNode t = new Node(1);
    return t;
}

/*
    Input :         1
                  /   \
                 2      3 
*/
PNode test_binary_tree1(){
    PNode t = new Node(1);
    PNode l1 = new Node(2);
    t->left = l1;
    PNode r1 = new Node(4);
    t->right = r1;
    return t;
}

/*
    Input :         1
                  /   \
                 2      3 
                / \    / \ 
               4   5  6   7
*/
PNode test_binary_tree2(){
    PNode t = new Node(1);
    PNode l1 = new Node(2);
    t->left = l1;
    PNode r1 = new Node(3);
    t->right = r1;

    PNode l2 = new Node(4);
    l1->left = l2;
    PNode r2 = new Node(5);
    l1->right = r2;

    PNode l3 = new Node(6);
    r1->left = l3;
    PNode r3 = new Node(7);
    r1->right = r3;

    return t;
}


/*             1
            /    \
          -2      3
          / \    /  \
         4   5  -6   2
*/
PNode test_binary_tree3(){
    PNode t = new Node(1);
    PNode l1 = new Node(-2);
    t->left = l1;
    PNode r1 = new Node(3);
    t->right = r1;

    PNode l2 = new Node(4);
    l1->left = l2;
    PNode r2 = new Node(5);
    l1->right = r2;

    PNode l3 = new Node(-6);
    r1->left = l3;
    PNode r3 = new Node(2);
    r1->right = r3;

    return t;
}

/*             1
            /    \
          -2      3
            \    /  
            5  -6   
*/
PNode test_binary_tree4(){
    PNode t = new Node(1);
    PNode l1 = new Node(-2);
    t->left = l1;
    PNode r1 = new Node(3);
    t->right = r1;

    PNode r2 = new Node(5);
    l1->right = r2;

    PNode l3 = new Node(-6);
    r1->left = l3;

    return t;
}

/*             1
            /   
          -2     
          / 
         4   
*/
PNode test_binary_tree5(){
    PNode t = new Node(1);
    PNode l1 = new Node(-2);
    t->left = l1;
    PNode l2 = new Node(4);
    l1->left = l2;
    return t;
}

/*  1
        \
            3
            \
                2
*/
PNode test_binary_tree6(){
    PNode t = new Node(1);
    PNode r1 = new Node(3);
    t->right = r1;
    PNode r3 = new Node(2);
    r1->right = r3;
    return t;
}

/*
    Input :         1
                  /   \
                 2      3 
                / \     
               4   5 
*/
PNode test_binary_tree7(){
    PNode t = new Node(1);
    PNode l1 = new Node(2);
    t->left = l1;
    PNode r1 = new Node(3);
    t->right = r1;
    PNode l2 = new Node(4);
    l1->left = l2;
    PNode r2 = new Node(5);
    l1->right = r2;
    return t;
}



// ================================================================================================
// Esame 08/01/24, Parte 2, Esercizio 1
//
// Si consideri un albero ternario completo in cui ogni nodo ha i seguenti campi: 
// (i) key chiave intera, 
// (ii) fruitful valore booleano, 
// (iii) left puntatore al figlio sinistro,
// (iv) center puntatore al figlio centrale, 
// (v) right puntatore al figlio destro. 

// Si scriva una procedura efficiente in C o C++ che assegni True al campo fruitful del 
// nodo se e solo se la somma delle chiavi dei nodi di ciascuno dei sottoalberi radicati nei figli
// è maggiore di una costante k fornita in input.

int set_fruitful_aux(PTNode r, int k){
    // Empty Tree
    if (r == nullptr){
        return 0;
    }

    // Find sum of subtrees
    int left_sum = set_fruitful_aux(r->left, k);
    int center_sum = set_fruitful_aux(r->center, k);
    int right_sum = set_fruitful_aux(r->right, k);

    // Set fruitful
    r->fruitful = (left_sum > k) && (center_sum > k) && (right_sum > k);

    return r->key + left_sum + center_sum + right_sum;
}

void set_fruitful(PTNode r, int k){
    set_fruitful_aux(r, k);
}

PTNode test_ternary_tree_1(){
    PTNode t = new TNode(0);
    PTNode l1 = new TNode(2);
    t->left = l1;
    PTNode c1 = new TNode(3);
    t->center = c1;
    PTNode r1 = new TNode(4);
    t->right = r1;

    return t;
}

// ================================================================================================


// ================================================================================================


int main(){
    PNode t = test_binary_tree7();
    int result = pari(t);

    cout << "\n" << endl;
    cout << result << endl;
    cout << "\n" << endl;

    return 0;
}
