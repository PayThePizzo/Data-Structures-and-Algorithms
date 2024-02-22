//
// Created by PayThePizzo on 11/22/2022.
//

#include <iostream>
#include "header.h"
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

PNode ricostruisciAux(const vector<int>& va, const vector<char>& vcol, int infa, int supa, const vector<int>& vs, int infs, int sups);
PNode ricostruisci(const vector<int>& va, const vector<char>& vcol, const vector<int>& vs);

// Scrivere una funzione EFFICIENTE blackHeight(u) che dato
// in input la radice u di un albero binario, i cui nodi x hanno,
// oltre ai campi key, left e right, un campo col che può essere 'B' (per “black”)
// oppure 'R' (per “red”), verifica se per ogni nodo, il cammino da quel nodo a
// qualsiasi foglia contiene lo stesso numero di nodi neri (altezza nera del nodo x).
// In caso negativo, restituisce -1, altrimenti restituisce l’altezza nera della radice.


// Dato che per tutti i nodi, bisogna considerare tutti i cammini da uno specifico nodo alle
// foglie raggingibili, cio' che si fa e' partire dalle foglie che possiamo considerare come
// alberi binari senza figli e riportare se quel nodo foglia ha un campo col = 'B'.

// Visita ricorsiva in POST-ORDINE
// Per il teorema, l'algoritmo di visita applicato alla radice di un albero con n nodi
// ha un tempo T = O(n) dato che ogni nodo viene visitato esattamente una volta.
// I controlli hanno tempo T = O(1).

int blackHeight(PNode u){
    if (u == nullptr) {
        return 0;
    } else {
        // Visita Figlio Sinistro
        int l = blackHeight(u->left);
        // Visita Figlio Destro
        int r = blackHeight(u->right);
        // Controlla se i sotto cammini hanno lunghezza uguale
        if(l != r){
            return -1;
        }else{
            // Ritorna lunghezza
            return u->col=='B'? l+1: l;
        }
    }
}


int main()
{
    vector<int> arrant, arrsim;
    vector<char> arrcol;
    PNode r;

    string dim_temp;
    getline(cin, dim_temp);

    int dim = stoi(ltrim(rtrim(dim_temp)));

    arrant.resize(dim);
    arrcol.resize(dim);
    arrsim.resize(dim);

    string arrant_temp_temp_int;
    getline(cin, arrant_temp_temp_int);
    vector<string> arrant_temp_int = split(rtrim(arrant_temp_temp_int));

    for (int i = 0; i < dim; i++) {
        int arrant_item = stoi(arrant_temp_int[i]);
        arrant[i] = arrant_item;
    }

    string arrant_temp_temp_string;
    getline(cin, arrant_temp_temp_string);
    vector<string> arrant_temp_string = split(rtrim(arrant_temp_temp_string));

    for (int i = 0; i < dim; i++) {
        char arrant_item = arrant_temp_string[i][0];
        arrcol[i] = arrant_item;
    }

    string arrsim_temp_temp_int;
    getline(cin, arrsim_temp_temp_int);
    vector<string> arrsim_temp_int = split(rtrim(arrsim_temp_temp_int));

    for (int i = 0; i < dim; i++) {
        int arrsim_item = stoi(arrsim_temp_int[i]);
        arrsim[i] = arrsim_item;
    }

    r = ricostruisci(arrant, arrcol, arrsim);

    cout << blackHeight(r);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

PNode ricostruisciAux(const vector<int>& va, const vector<char>& vcol, int infa, int supa, const vector<int>& vs, int infs, int sups){

    int i;
    PNode r;

    if (infa > supa)
        return nullptr;

    r = new Node(va[infa], vcol[infa]);

    i = infs;

    while (vs[i] != va[infa])
        i++;

    r->left = ricostruisciAux(va, vcol, infa+1, infa + (i - infs), vs, infs, i-1);
    r->right = ricostruisciAux(va, vcol, infa+(i - infs) + 1, supa, vs, i+1, sups);

    return r;
}

PNode ricostruisci(const vector<int>& va, const vector<char>& vcol, const vector<int>& vs){

    return ricostruisciAux(va, vcol, 0, va.size()-1, vs, 0, vs.size()-1);
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}