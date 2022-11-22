//
// Created by PayThePizzo on 11/22/2022.
//

#include <iostream>

using namespace std;

struct Node{ 
    int key;
    char col;
    Node* left;
    Node* right;
    Node(int k, char c, Node* sx = nullptr, Node* dx = nullptr)
    : key{k}, col{c}, left{sx}, right{dx} {}
};

typedef Node* PNode;



int blackHeight(PNode u){
    return 0;
}


int main(int argc, char const *argv[])
{
    /* code */
    cout<< "lol" << endl;
    return 0;
}
