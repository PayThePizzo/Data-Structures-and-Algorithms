//
// Created by PayThePizzo on 3/30/2022.
//
#include "first_assignment.h"
#include <algorithm>

using namespace std;

int k_limitato_aux_rec(PNode r) {
    if (r->left && r->right) {        //both children
        return std::max(k_limitato_aux_rec(r->left) + r->key,
                        k_limitato_aux_rec(r->right) + r->key);
    } else if (r->left && !r->right) {   //only left child
        return k_limitato_aux_rec(r->left) + r->key;
    } else if (!r->left && r->right) {  //only right child
        return k_limitato_aux_rec(r->right) + r->key;
    } else if (!r->left && !r->right) {   //empty
        return 0;
    }
}
// Complexity
//  k_limitato_aux_rec: T(n) = Θ(n)
//
// We are visiting each node exactly once, we have no cycles, all the operations
// are really simple (either calls, sums, ..)


bool k_limitato(PNode r, int k) {
    if (r != nullptr)
        return k_limitato_aux_rec(r) <= k;
}

// Complexity
// k_limitato_aux_rec: T(n) = O(n)
//
// We have the case of the empty tree.