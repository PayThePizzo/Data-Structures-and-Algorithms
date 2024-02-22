//
// Created by PayThePizzo on 11/22/2022.
//

#ifndef ASD_EX1_H
#define ASD_EX1_H

#include <iostream>
#include <iostream>
#include <vector>
#include <tuple>

// Ex 1
struct Node{
    int key;
    char col;
    Node* left;
    Node* right;
    Node(int k, char c, Node* sx = nullptr, Node* dx = nullptr)
            : key{k}, col{c}, left{sx}, right{dx} {}
};

typedef Node* PNode;

int blackHeight_aux(PNode u);

int blackHeight(PNode u);

//-------------------------------------------------------
// Ex 2

struct NodeG{
    int key;
    NodeG* left_child;
    NodeG* right_sib;
    NodeG(int k, NodeG* sx = nullptr, NodeG* dx = nullptr)
            : key{k}, left_child{sx}, right_sib{dx} {}
};

typedef NodeG* PNodeG;

bool k_Completo(PNodeG r, int k);

std::tuple<bool, int> k_Completo_aux(PNodeG u, int k);

//-----------------------------------------------------
// Ex 3

int max_l_cammino_monocolore(const std::vector<char>& tree, char& colore_max_cammino);

//-------------------------------------------------------
// Ex 4

int minTime(const std::vector<int>& len, const std::vector<int>& speed, std::vector<int>& ass);

//-----------------------------------------------------------
// Ex 5

int estrai(const std::vector<int>& classifica1, const std::vector<int>& classifica2, int k);

#endif //ASD_EX1_H
