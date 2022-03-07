# Insertion Sort
Insertion sort is a simple sorting algorithm that works similar to the way you sort playing 
cards in your hands. 

The array is virtually split into a **sorted** and an **unsorted part**. 
Values from the unsorted part are picked and placed at the correct position in the sorted part

![Insertion Sort](https://github.com/PayThePizzo/DataStrutucures-Algorithms/tree/main/Resources/insertionsort.png?raw=TRUE)

Characteristics:
* Incremental
* In-Loco Sorting

--- 

## Incremental Technique 
The array is virtually split into a  k **sorted** and an  A.length-k **unsorted part**.

Our goal is to extend the sorted part of the array from k to k+1 by placing in the correct position an element 
from the unsorted section at each iteration.

---

## In-Loco sorting
Questo algoritmo ordina in loco, cioè con uno spazio aggiuntivo O(1), n elementi, eseguendo nel
caso peggiore Θ(n**2) confronti: il for è eseguito n − 1 volte, mentre il numero massimo di confronti è
12 j per ogni ciclo. Nel caso migliore l’array è già ordinato, e si impiega Θ(n), mentre nel caso peggiore
l’array è ordinato in senso inverso, quindi Θ(n**2).

Invariant: the sub-array A[1 .. j-1] è formato dagli elementi ordinati che che originariamente erano
in A[1 .. j-1]. 

Quando il ciclo termina, j = A.length + 1, quindi per l’invariante gli elementi A[1 ..
A.length+1-1] sono ordinati, e questi costituiscono gli elementi originariamente presenti in A.


Idea: 
* A first cycle to go through all the cards, a second one to 
* We start from an index i = 2, since the first card is sorted for definition.

To sort an array of size n in ascending order:
* 1: Iterate from arr[1] to arr[n] over the array.
* 2: Compare the current element (key) to its predecessor.
* 3: If the key element is smaller than its predecessor, compare it to the elements before. 
Move the greater elements one position up to make space for the swapped element.

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
**Final Time Complexity**

**Final Space Complexity**

---

### Conclusion
Works well with small vectors

--- 

### Extra Credits

* [GfG - Insertion Sort](https://www.geeksforgeeks.org/insertion-sort/)