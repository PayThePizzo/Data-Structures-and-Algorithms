//
// Created by PayThePizzo on 3/30/2022.
//
#include <iostream>
#include "first_assignment.h"

using namespace std;

PNode tree_build(int* key){
    PNode tree;
    int** aux = &key;

    while(aux != nullptr){

    }


    return tree;
}

void treeG_print(PNode G){

}

void tree_print(PNode r){

}

void print(std::vector <int> const &a) {
    std::cout << "The vector elements are : ";

    for(int i=0; i < a.size(); i++)
        std::cout << a.at(i) << ' ';
}

int main() {
    vector<int> vect;
    vect.reserve(10);

    for(int i=0; i<vect.size(); i++){
        vect.push_back(5);
    }

    print(vect);

    return 0;
}