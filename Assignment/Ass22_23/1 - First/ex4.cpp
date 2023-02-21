//
// Created by PayThePizzo on 11/22/2022.
//

#include "header.h"

using namespace std;

// N barre di marmo di lunghezza L = [L0, L1, ... , LN-1] in metri sono posizionate una
// accanto all'altra.
//
// Ci sono K macchine tagliatrici, posizionate una accanto all'altra,
// in grado di trasformare una barra in cubetti di marmo.
//
// Ogni macchina elabora barre di marmo a velocità diverse S = [S0, S1, ..., SK-1] in metri/sec.
//
// Le macchine tagliatrici funzionano con i seguenti vincoli:
// una barra può essere elaborata da una sola macchina;
// una macchina può elaborare più barre, una dopo l'altra;
// una macchina, dopo aver completato una barra, può elaborare solo la barra adiacente
//  alla sua destra (quindi una macchina può elaborare SOLO sequenze consecutive di barre);
//
// le macchine possono lavorare in parallelo;
// l'ordine di barre e macchine non può essere modificato.
//
// Scrivere una funzione minTime che restituisce il tempo minimo richiesto per
// elaborare tutte le barre e inserisce nel vettore ass l'assegnazione delle barre
// alle macchine (ovvero ass[i] = j quando la barra i è assegnata alla macchina j)

int minTime(const std::vector<int>& len, const std::vector<int>& speed, std::vector<int>& ass){
    return 0;
}