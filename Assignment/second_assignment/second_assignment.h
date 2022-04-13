#ifndef ASD_SECOND_ASSIGNMENT_H
#define ASD_SECOND_ASSIGNMENT_H

#include <math.h>
#include <vector>
#include <pair>

using namespace std;

// Aux =================================================

struct Node{
    int key;
    Node* p; // parent
    Node* left;
    Node* right;
    Node(int k, Node* padre, Node* sx = nullptr, Node* dx = nullptr)
            : key{k}, p{padre}, left{sx}, right{dx} {}
};
typedef Node* PNode;



// Ex 1 =================================================


bool unione(vector<pair<int, int>>& arr, pair<int, int>& ris);


//input: [1,2],[3,4]; output: true, [1,4].
//input: [1,3], [2,4]; output: true, [1,4].
//input: [-1,0], [2,4]; output: false.

// Ex 2 =================================================



// Ex 3 =================================================



int scarto(vector<int>& punteggi);



// Ex 4 =================================================





// Ex 5 =================================================


void range(const Tree& t, PNode u, int k1, int k2, vector<int>& arr);


#endif //ASD_SECOND_ASSIGNMENT_H
