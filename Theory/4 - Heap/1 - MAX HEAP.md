# Max Heap

## Max Heap Property

> For every node i, except the root, we have $A[parent(i)] \geq A[i]$ (as the root is the largest element)

```math
\forall i \in A \ni' i \neq root(A) : A[parent(i)] \geq A[i]
```

By induction, through the property of transitivity of $\leq$, it is possible to demonstrate that
1. The root of a Max Heap contains the largest element of a Max Heap
2. The root of a subtree of a Max Heap contains the largest element in that subtree
    1. The elements of that subtree are not greater than the root of that subtree

---

## Operations

| **Operation**                               	| **Time**                     	| **Pre-Condition**                                                                             	| **Post-Condition**                   	|
|---------------------------------------------	|------------------------------	|-----------------------------------------------------------------------------------------------	|--------------------------------------	|
| `Max_Heapify(Array A[], int i) -> Max_Heap` 	| $T(n) = \mathcal{O}(log(n))$ 	| $i \in A$ and the binary trees with root in $left_child(i)$ and $right_child(i)$ are Max Heap 	| The tree rooted in $i$ is a Max Heap 	|
| `Build_Max_Heap(Array A[]) -> Max_Heap`     	| $T(n) = \mathcal{O}(n)$      	| $A$ is an array                                                                               	| $A$ is a Max Heap                    	|

---

## Max Heapify

| **Operation**                               	| **Time**                     	| **Pre-Condition**                                                                             	| **Post-Condition**                   	|
|---------------------------------------------	|------------------------------	|-----------------------------------------------------------------------------------------------	|--------------------------------------	|
| `Max_Heapify(Array A[], int i) -> Max_Heap` 	| $T(n) = \mathcal{O}(log(n))$ 	| $i \in A$ and the binary trees with root in $left_child(i)$ and $right_child(i)$ are Max Heap 	| The tree rooted in $i$ is a Max Heap 	|

In order to maintain the max-heap property, we call the procedure `Max_Heapify`. 
Its inputs are an array $A$ and an index $i$ into the array. 

When it is called, `Max_Heapify` assumes that the binary trees rooted at $left_child(i)$ and $right_child(i)$ are max-heaps, 
but that $A[i]$ might be smaller than its children, thus violating the max-heap property. 

`Max_Heapify` lets the value at $A[i]$ _float down_ in the max-heap so that the subtree rooted at index $i$ 
obeys the max-heap property.

### The process

At each step, 
1. The largest of the elements $A[i], A[left_child(i)], A[right_child(i)]$ is determined, and its index is
stored in `max`. 
   1. If $A[i]$ is largest, then the subtree rooted at node $i$ is already a
   max-heap and the procedure terminates. 
   2. Otherwise, one of the two children has the largest element, and $A[i]$  is swapped with $A[max]$, which causes node 
   $i$ and its children to satisfy the max-heap property. 
      1. The node indexed by $max$, however, now has the original value $A[i]$, and thus the subtree rooted at largest might 
      violate the max-heap property. Consequently, we call `Max_Heapify` recursively on that subtree.

```python
max_heapify(Heap A, Node i)
    l = left_child(i);
    r = right_child(i);
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

Example: `Max_Heapify(A, 2)` with $A.heapsize = 10$


![maxheapifyex](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/maxheapifyex.png?raw=TRUE)

**(a)** The initial configuration, with $A[2]$ at node $i = 2$ violating the max-heap property since it is not larger than
both children. The max-heap property is restored for node 2 in **(b)** by exchanging $A[2]$ with $A[4]$, which destroys 
the max-heap property for node $4$. The recursive call `Max_Heapify(A, 4)` now has $i = 4$. 
After swapping $A[4]$ with $A[9]$, as shown in **(c)**, node $4$ is fixed up, and the recursive call
`Max_Heapify(A, 9)` yields no further change to the data structure.

### Time Complexity

$$T(n) = T(h) = \mathcal{O}(h) = \mathcal{O}(log(n)), \text{ by Lemma 1}$$

At every recursive call we go down one level, and by Lemma 1, the worst possible complexity is dictated 
by $\lfloor log(n) \rfloor$

---

## Build Max Heap

| **Operation**                           	| **Time**                	| **Pre-Condition** 	| **Post-Condition** 	|
|-----------------------------------------	|-------------------------	|-------------------	|--------------------	|
| `Build_Max_Heap(Array A[]) -> Max_Heap` 	| $T(n) = \mathcal{O}(n)$ 	| $A$ is an array   	| $A$ is a Max Heap  	|

### Process 

We can use the procedure `Max_Heapify` in a bottom-up manner to convert an array $A[1 \ldots n]$, where $n = A.length$,
into a max-heap. By Lemma 2, half of the nodes are leaves so each is a 1-element heap to begin with. The procedure
`Build_Max_Heap` goes through the remaining nodes of the tree and runs `Max_Heapify`on each one.

```python
build_maxheap(Array A)
    A.heap_size = A.length
    for (i = ⌊A.length/2⌋ down to 1):
        max_heapify(A, i);
```

Example:

![buildmaxheapex](https://github.com/PayThePizzo/DataStrutucures-Algorithms/blob/main/Resources/buildmaxheapex.png?raw=TRUE)


### Invariant

INV: every node in `i+1, i+2, ... n` is root of a max_heap with n = A.length. In particular
`i=n/2` is the first node that is not a leaf. So we start from there since `i=(n/2)+1` is
already a leaf (like the following nodes).

This is true since:
* Initialization: checked
* Preservation: checked
* Conclusion: At the end of the for block `i = 0`. The invariant tells us that every not is
  a root of max_heap, in particular the node A[i] with `i=1` (the root node) is a max_heap.

### Time Complexity

**Final Time Complexity** T(n) = O(n * log(n))
* Simple analysis
* More specifically T(n) = O(n)

## Heap Sort
We will face this algorithm under the [sorting section](https://github.com/PayThePizzo/DataStrutucures-Algorithms/tree/main/3%20-%20Sorting)