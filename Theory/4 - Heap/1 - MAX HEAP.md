# Max Heap
<mark>Max Heap Property</mark>: for every node i, except the root, we have `A[parent(i)] >= A[i]`
* The root is the largest element

## Max Heapify
* Pre: Trees with root in the left and right sub-trees (respectively `left(i)` and `right(i)`
must be **max heap** 

* Post: Tree with root in **i** becomes a **max heap**

```python
max_heapify(Heap A, Node i)
    l = left(i);
    r = right(i);
    if (l <= A.heap_size && A[l]>A[i]):
        max = l;
    else:
        max = i;
    if (r <= A.heap_size && A[r] > A[max]):
        max = r;
    if (i != max):
        swap(A[i],A[max]);
        max_heapify(A, max);
```
**Final Time Complexity** T(n)= O(h) = O(log(n))
* Lemma 1. guarantees this

## Build Max Heap
* Input: General vector (array)
* Output: Heap

Idea: to build a heap, we start from the middle because the resting nodes are already leaves

INV: every node in `i+1, i+2, ... n` is root of a max_heap with n = A.length. In particular
`i=n/2` is the first node that is not a leaf. So we start from there since `i=(n/2)+1` is 
already a leaf (like the following nodes).
* Initialization: checked
* Preservation: checked
* Conclusion: At the end of the for block `i = 0`. The invariant tells us that every not is
a root of max_heap, in particular the node A[i] with `i=1` (the root node) is a max_heap.

```python
build_maxheap(Array A)
    A.heap_size = A.length
    for (i = ⌊A.length/2⌋ down to 1):
        max_heapify(A, i);
```
**Final Time Complexity** T(n) = O(n * log(n))
* Simple analysis
* More specifically T(n) = O(n)

## Heap Sort
We will face this algorithm under the [sorting section](https://github.com/PayThePizzo/DataStrutucures-Algorithms/tree/main/3%20-%20Sorting)