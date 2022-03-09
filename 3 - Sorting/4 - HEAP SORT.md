# Heap Sort
Heap sort belongs to a particular category of algorithms where
some data structure were precisely thought in order to simplify
the sorting problem. In this case, the data structure is called [Heap](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/4%20-%20Heap/0%20-%20HEAP.md)

Characteristics:
* In-Loco
* Based on Heap
* Efficient

---

## Invariant
* The sub-array A[1..i] is a max_heap containing the `i` smallest values of the vector of
start
* The sub-array A[i+1..n] contains `n-i` largest elements of the vector of start, sorted
by value
  
INV:
* Initialization: checked
* Preservation: checked
* Conclusion: `i=1` at the end of the for block
  * A[1] is a max_heap, and is the smallest element of the starting vector
  * A[2..n] is a vector containing the `n-1`largest elements of the vector of start, sorted
  by value 
  * This means, the vector is sorted
  
---

## The algorithm

```python
Heap_sort(Array A)
    build_maxheap(A);
    for (i = A.length down to 2):
        swap(A[i], A[1]);
        A.heapsize = A.heapsize-1;
        max_heapify(A, 1);
```

**Final Time Complexity** T(n) = O(n * log(n))