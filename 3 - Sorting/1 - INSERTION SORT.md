# Insertion Sort
It is an algorithm that exploits and incremental technique: we have k sorted elements
and we 

Invariant: the sub-array A[1 .. j-1] è formato dagli elementi ordinati che che originariamente erano
in A[1 .. j-1]. 

Quando il ciclo termina, j = A.length + 1, quindi per l’invariante gli elementi A[1 ..
A.length+1-1] sono ordinati, e questi costituiscono gli elementi originariamente presenti in A.


Questo algoritmo ordina in loco, cioè con uno spazio aggiuntivo O(1), n elementi, eseguendo nel
caso peggiore Θ(n**2) confronti: il for è eseguito n − 1 volte, mentre il numero massimo di confronti è
12 j per ogni ciclo. Nel caso migliore l’array è già ordinato, e si impiega Θ(n), mentre nel caso peggiore
l’array è ordinato in senso inverso, quindi Θ(n**2).

Funziona molto bene con array piccoli.


```python
insertion_sort(Array A)
    for j = 2 TO A.length #Array starts from 1
        key = A[j]
        i = j-1
        while i > 0 AND A[i] > key
            A[i+1] = A[i]
            i = i-1
        A[i+1] = key
```

