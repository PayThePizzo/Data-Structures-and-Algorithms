//
// Created by PayThePizzo on 11/22/2022.
//
#include "header.h"

using namespace std;

// Sia T un albero generale i cui nodi hanno campi: key, left-child e right-sib.
// Scrivere una funzione EFFICIENTE che dato in input la radice dell'albero T e
// un intero k (k>=2) verifica se T è un albero k-completo.

// Properties:
// 1) All the leaves have the same depth
// 2) All the internal nodes have degree = k
// 3) All levels except the last one are full of nodes.

bool k_Completo(PNodeG r, int k){
    std::tuple<bool, int> res = k_Completo_aux(r,k);
    return std::get<0>(res);
}

std::tuple<bool, int> k_Completo_aux(PNodeG u, int k){
    // O(1)
    if(u == nullptr){
        //empty tree is a k-ary tree
        //O(1)
        return std::make_tuple(true,-1);
    }else{
        // No child assumption
        int child_height = -1;
        PNodeG child = u->left_child;
        // No child assumption
        int degree = 0;
        //Complete k-ary assumption
        bool cond = true;
        // If no child or cond is false, exit
        while(child!=nullptr && cond==true){
            //There is at least one child
            degree++;
            // Check the same for the child
            std::tuple<bool, int> rec = k_Completo_aux(child,k);
            if(child_height==-1){
                child_height = std::get<1>(rec);
            }
            cond = (cond && std::get<0>(rec)) && (degree<=k && std::get<1>(rec)==child_height);
            // repeat on the sibling
            child = child->right_sib;
        }
        return std::make_tuple(cond && (degree == k || degree == 0), child_height+1);
    }
}

// Each node is visited at most once O(n)