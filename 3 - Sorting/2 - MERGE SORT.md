# Merge Sort
Merge sort belongs to a class of algorithms which use a Divide-et-Impera approach.

The MergeSort function repeatedly divides the array into two halves until 
we reach a stage where we try to perform MergeSort on a subarray of size 1.[1]

After that, the merge function comes into play and combines the sorted arrays into larger 
arrays until the whole array is merged.[1]

![Merge Sort](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/mergesort.jpg?raw=TRUE)

---
## Divide-Et-Impera
We 


---
## Invariant


1) Initialization: Respected
2) Preservation: Respected
3) Conclusion: When the for block stops, `k = r+1`

INV[(r+1)/k] ≡ 

---
## The Algorithm

Utilizza il metodo del divide et impera, ordinando un array delimitato da due indici p e r:
1. Divide: si divide l’array in due parti A[p .. q] e A[q+1 .. r], con q indice di mezzo
2. Impera: ordina i due sotto-array ottenuti in modo ricorsivo utilizzando il mergesort. Se il problema è sufficientemente piccolo (0/1 elementi), risolve direttamente
3. Combina: fonde assieme i due sotto-array ordinati per generare un singolo vettore ordinato

![Merge Sort](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/mergesort2.jpg?raw=TRUE)

Let's see the algorithm now.
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
**Final Time Complexity** T(n) = Θ(n * log(n))
* Merge: T(n) = Θ(n)
  1) variable initialization: O(1)
  2) for block: Θ(n)
  3) for block: Θ(n)
  4) for block: Θ(n)
* Sort: T(n) = Θ(log(n))


---
### Conclusion

Pros:
* More **efficient** than Insertion-Sort even in the worst case
* It is a **stable** method, numbers with the same value have the same order in the array
of output and input.

Cons:
* Not In-Place
* Not sensitive to order
* Depends on the number of keys to sort

We can optimize it by combining it with different algorithms, in order to handle
a large variety of input.

---

### Extra Credits

* [1] [Programiz - MergeSort](https://www.programiz.com/dsa/merge-sort)