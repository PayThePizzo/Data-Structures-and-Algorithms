# Merge Sort
Merge sort belongs to a class of algorithms which use a Divide-et-Impera approach.


Utilizza il metodo del divide et impera, ordinando un array delimitato da due indici p e r:
1. Divide: si divide l’array in due parti A[p .. q] e A[q+1 .. r], con q indice di mezzo
2. Impera: ordina i due sotto-array ottenuti in modo ricorsivo utilizzando il mergesort. Se il problema è sufficientemente piccolo (0/1 elementi), risolve direttamente
3. Combina: fonde assieme i due sotto-array ordinati per generare un singolo vettore ordinato


```python
merge_sort(Array A, int, p, int r)
    if p < r //Almeno 2 elementi in A
    q = floor( (p+r)/2 )
    Merge_sort(A, p, q)
    Merge_sort(A, q+1, r)
    Merge(A, p, q, r)


Merge(Array A, int p, int q, int r)
    n1 = q - p + 1
    n2 = r - q
    crea array ausiliari L[1 .. n1+1] e R[1 .. n2+1]
    for i = 1 TO n1
        L[i] = A[p+i-1]
    for j = 1 TO n2
        R[i] = A[q+j]
    L[n1+1] = infinity
    R[n2+1] = infinity
    i = 1
    j = 1
    for k = p TO r
        if L[i] <= R[j]
            A[k] = L[i]
            i++
        else
            A[k] = R[j]
            j++


```