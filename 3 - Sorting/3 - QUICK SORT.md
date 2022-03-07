# Quick Sort
Quick sort belongs to a class of algorithms which use a Divide-et-Impera approach.

```python
Quick_sort(Array A, int p, int r)
    if p < r
    q = Partition(A, p, r)
    Quick_sort(A, p, q-1)
    Quick_sort(A, q+1, r)

Partition(Array A, int p, int r)
    x = A[r]
    i = p-1
    for j = p to r-1
        if A[j] <= x
        i++
        scambia A[i] e A[j]
    scambia A[i+1] e A[r]
    return i+1

```