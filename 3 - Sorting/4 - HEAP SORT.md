# Heap Sort
Heap sort belongs to a particular category of algorithms where
some data structure were precisely thought in order to simplify
the sorting problem.

max heapify:
* PRE: gli alberi radicati in left(i) e right(i) sono maxHeap*/
* POST: l’albero radicato in i è un maxHeap*/

```python
max_heapify(Heap A, Node i)
    l = left(i)
    r = right(i)
    if l <= A.heap_size AND A[l]>A[i]
        massimo = l
    else
        massimo = i
        
    if r <= A.heap_size AND A[r] > A[massimo]
        massimo = r
    if i != massimo
        scambia A[i] con A[massimo]
        max_heapify(A, massimo)


build_maxheap(Array A)
    A.heap_size = A.length
    for i = A.length/2 DOWN TO 1
    max_heapify(A, i)


Heap_sort(Array A)
    build_maxheap(A)
    for i = A.length DOWN TO 2
        scambia A[i] e A[1]
        A.heapsize = A.heapsize-1
        max_heapify(A, 1)


```