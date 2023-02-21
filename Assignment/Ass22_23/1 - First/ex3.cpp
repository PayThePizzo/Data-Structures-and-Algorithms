//
// Created by PayThePizzo on 11/22/2022.
//

#include "header.h"

using namespace std;

// Sia T un albero ternario completo i cui nodi sono colorati di bianco
// (carattere ‘w’) o nero (carattere ‘b’). L’albero è rappresentato tramite un
// vettore posizionale.
//
// Scrivere una funzione EFFICIENTE che ritorni la
// lunghezza del cammino più lungo all’interno dell’albero con
// nodi che presentano tutti lo stesso colore (il cammino può partire da un nodo qualsiasi,
// non necessariamente dalla radice) e il colore dei nodi del cammino più lungo.


// Properties
// Every Node has 3 children
// v is the index, v=0 is the root
// the i-ary child of v is in position 3*v+i+1

int max_l_cammino_monocolore(const std::vector<char>& tree,
                             char& colore_max_cammino){
    std:tuple<int, char>res = aux(tree, colore_max_cammino);
    colore_max_cammino = std::get<1>(res);
    return std::get<0>(res);
}

std::tuple<int,char> aux(const std::vector<char>& tree,
        char& colore_max_cammino, int counter){
    if(tree.empty()){
        return std::make_tuple(0, 'x');
    }else{
        std::tuple<int, char> white = std::make_tuple(0, 'w');
        std::tuple<int, char> black = std::make_tuple(0, 'b');
        int n = tree.size();

    }
}