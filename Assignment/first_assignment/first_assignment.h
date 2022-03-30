#ifndef ASD_EX_1_H
#define ASD_EX_1_H
#include <math.h>
// Ex 1 =================================================

struct Node{
    int key;
    Node* p; // parent
    Node* left;
    Node* right;
    Node(int k, Node* padre, Node* sx = nullptr, Node* dx = nullptr)
            : key{k}, p{padre}, left{sx}, right{dx} {}
};
typedef Node* PNode;


/**
 * Recursive auxiliary function
 *
 */
int treBil_aux_rec(PNode root);

/**
 * Given the node u, of a binary tree, it verifies whether it is a 3-balanced binary tree
 *
 * @param u
 * @return True if the tree is a 3-balanced binary tree;
 */
bool treBil(PNode u);

//It is best to use a post-order visit

// Ex 2 =================================================




bool k_limitato(PNode r, int k);

// Ex 3 =================================================

struct NodeG{
    int key;
    NodeG* left_child;
    NodeG* right_sib;
    NodeG(int k, NodeG* lc = nullptr, NodeG* rs = nullptr)
            : key{k}, left_child{lc}, right_sib{rs} {}
};

typedef NodeG* PNodeG;

int larghezza(PNodeG r);

//It is best to use a symmetric visit


// Ex 4 =================================================

void findMaxTreasure(vector<vector<int>>& map, int columns, int& index_row, int& index_column);

// Ex 5 =================================================

int corsa(const vector<int>& tappe, const vector<int>& velocitaAtleti, vector<int>& ass);


#endif //ASD_EX_1_H
