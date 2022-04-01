// Exercise 1:

#include "first_assignment.h"
#include <algorithm>

using namespace std;

//TODO: Test if balanced
int treBil_aux_rec(PNode root){
    if (root->left && root->right) {        //both children
        return std::max(treBil_aux_rec(root->left)+1,
                   treBil_aux_rec(root->right)+1);
    }
    else if (root->left && !root->right){   //only left child
        return treBil_aux_rec(root->left)+1;
    }
    else if (!root->left && root->right) {  //only right child
        return treBil_aux_rec(root->right)+1 ;
    }
    else if(!root->left && !root->right){   //empty
        return 0;
    }
}


bool treBil(PNode u){
    if(u != nullptr)
        return treBil_aux_rec(u)<=3 ? true : false;

    return true; // if it is an empty tree, it is true by definition.
}

/*
*
 * Control
 *
*/