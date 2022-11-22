# Esercitazione 1

## Esercizio 1.

Scrivere una funzione EFFICIENTE blackHeight(u) che dato in input la radice u di un albero binario, 
i cui nodi x hanno, oltre ai campi key, left e right, un campo col che può essere 'B' (per “black”) 
oppure 'R' (per “red”), verifica se per ogni nodo, il cammino da quel nodo a qualsiasi 
foglia contiene lo stesso numero di nodi neri (altezza nera del nodo x).
In caso negativo, restituisce -1, altrimenti restituisce l’altezza nera della radice.

Il prototipo della funzione è:
```c++
int blackHeight(PNode u)
```

Il tipo PNode è così definito:
```c++
struct Node{ 
  int key;
  char col;
  Node* left;
  Node* right;
  Node(int k, char c, Node* sx = nullptr, Node* dx = nullptr)
    : key{k}, col{c}, left{sx}, right{dx} {}
};
```

Valutare la complessità della funzione, indicando eventuali relazioni di ricorrenza.

### Soluzione 

```c++
int blackHeight(PNode u)
```
