#include <iostream>
#include <typeinfo>
#include <vector>

using namespace std;

// ================================================================================================
// Esame 10/09/12, Parte 2, Esercizio 1
//
// Dato un array v ordinato in senso crescente di n interi, il cui valore può essere solo 0 e 1, progettare 
// un algoritmo efficiente, di tipo divide-et-impera, che restituisca il numero di occorrenze del numero 
// 1 in v. 
// Calcolare la complessità al caso pessimo dell’algoritmo proposto indicando, e risolvendo, la 
// corrispondente relazione di ricorrenza.

int occorrenze_1_aux(vector<int>& v){

}

int occorrenze_1(vector<int>& v){
    int left, right;

    // Empty Vector
    if(v.size() == 0){
        return 0;
    }

    // Left and Right Index Limits
    left = 0;
    right = v.size()-1;



    return 1;
}

// ================================================================================================
int main(){

}